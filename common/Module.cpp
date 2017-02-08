/*
 * Module.cpp
 *
 *  Created on: 8 déc. 2016
 *      Author: scapel
 */
#include <string> //stoi,stof,string
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "easylogging++.h"

#include "Module.h"
#include "ParamMere.h"

using namespace std;

/** Masque de lecture d'un octet */
#define K_GEN_BIN_MASK_OCTET      0x000000FFu

/** decalage du 2eme octet */
#define K_GEN_BIN_DECAL_OCTET_2   8

/** decalage du 3eme octet */
#define K_GEN_BIN_DECAL_OCTET_3   16

/** decalage du 4eme octet */
#define K_GEN_BIN_DECAL_OCTET_4   24


Module::Module(string inputFileName,string outputFileName,void* p_cfg,int size):
      m_inputFileName(inputFileName),m_outputFileName(outputFileName),m_p_cfg(p_cfg), m_size(size){
}

Module::~Module(){
}

//virtual void addVar(ParamMere *param)const;
void Module::addVar(ParamMere *param){
   /*/todo check that the descriptor is unique  */
   m_listVars.push_back(param);
}

int Module::removeVar(ParamMere& param){
   int ret = -1;
   int position = 0;
   int nbVariables = (int)m_listVars.size();//we suppose that can't be overload
   /*Parcours la liste a la recherche de l'element*/
   for (;position<nbVariables;position++)
   {
      if (m_listVars[position]->getDescripton().compare(param.getDescripton()) == 0){
         /*the variable is found, so i erase it*/
         m_listVars.erase(m_listVars.begin() + position);
         ret = 0;//success
      }
   }
   return(ret);
}

void Module::readInputFile(void) const{
   int indexInVector;
   int nbVariables = (int)m_listVars.size();//we suppose that can't be overflow
   //get file name
   string fileName = m_inputFileName;
   string token;
   int tokenNumber;
   bool isDescriptorFound;
   int intValue;
   float floatValue;
   size_t nextChar;

   //open input file
   ifstream f (fileName.c_str(), ios::in);
   if (!f.is_open())
   {
      LOG(ERROR) << "the file: " << fileName << " can't be open";
   }
   else
   {
      //current line, descriptor, value
      string aLine,descriptor,value;
      //istringstream value;
      //loop in file, line by line
      while (getline(f,aLine))
      {
         tokenNumber = 0;
         istringstream iss(aLine);
         while (getline(iss, token, ';'))
         {
            tokenNumber++;
            switch (tokenNumber)
            {
            case 1:
               value = token;
               break;
            case 2:
               descriptor = token;
               break;
            default:
               LOG(ERROR) << "The number of field is no consistent";
               break;
            }
         }
         if ( descriptor.size()!=0 )
         {
            //search in the vector of the module, the variable with the same descriptor
            indexInVector = 0;
            while (( isDescriptorFound = indexInVector < nbVariables) &&
                  (descriptor.compare(m_listVars[indexInVector]->getDescripton()) != 0) )
            {
               indexInVector++;
            }

            if (isDescriptorFound)
            {
               LOG(INFO) << "Descriptor: " << descriptor << " found, value: " << value;
               //associate the value function of type
               switch (m_listVars[indexInVector]->getType())
               {
               case TYPE_INT:
                  intValue = stoi(value,&nextChar);
                  m_listVars[indexInVector]->setValue(intValue);
                  break;
               case TYPE_FLOAT:
                  floatValue = stof (value,&nextChar);
                  m_listVars[indexInVector]->setValue(floatValue);
                  break;
               case TYPE_BOOL:
               default:
                  LOG(WARNING) << "The type bool is not managed";
                  break;
               }
            }
            else
            {
               //message error...in log
               LOG(ERROR) << "Descriptor: " << descriptor << " not found in the module ";
            }
         }
      }
      //we finish to analyse the file
      f.close();
   }
}

void Module::generate(void) const{
   int indexInCfg, indexInVariableList;
   int nbVariables = (int)m_listVars.size();//we suppose that can't be overload
   int* p_cfg = (int*)m_p_cfg;
   bool isVarFind = false;
   int totalSizeAttachedVariable = totalSize();

   /** used transformation big2little endian */
   unsigned char v1,v2,v3,v4;
   unsigned int v;

   /*! binary file */
   string fileName = m_outputFileName;
   ofstream outputFile (fileName.c_str(),ios::out | ios::binary);

   if (outputFile.is_open())
   {

      /*Control que les tailles soient coérentes*/
      if (m_size != totalSizeAttachedVariable)
      {
         /*Si differente alors on logue l'erreur, on continue le traitement pour indiquer quelles variables posent pb!*/
         LOG(ERROR) << "The Number of associated variables ("
               << totalSizeAttachedVariable
               << ") is different than the size of associate structure ("
               << m_size << ")";
      }

      /*Parcours la structure *_cfg.h associée */
      indexInCfg = 0;
      while (indexInCfg < m_size)
      {
         /*Recherche la variable ou le début de structure associée */
         isVarFind = false;
         for (indexInVariableList = 0; indexInVariableList < nbVariables;
               indexInVariableList++)
         {
            if (m_listVars[indexInVariableList]->getAdressOfValue()
                  == (p_cfg + indexInCfg))
            {
               /*var find!*/
               isVarFind = true;
               break;
            }
         }
         if (isVarFind)
         {
            int sizeOfVar = m_listVars[indexInVariableList]->getSize();
            /*S'il trouve, il vérifie que la variable soit dans les bornes */
            if (m_listVars[indexInVariableList]->testBounces())
            {
               /*on exporte les valeurs dans le fichier binaire*/
               for (int index = 0; index < sizeOfVar; index++)
               {
                  /* Conversion Little Endian de la valeur du parametre sur 32 bits */
                  v1 = (unsigned char) ((*(p_cfg + indexInCfg))
                        & K_GEN_BIN_MASK_OCTET);
                  v2 = (unsigned char) (((*(p_cfg + indexInCfg))
                        >> K_GEN_BIN_DECAL_OCTET_2) & K_GEN_BIN_MASK_OCTET);
                  v3 = (unsigned char) (((*(p_cfg + indexInCfg))
                        >> K_GEN_BIN_DECAL_OCTET_3) & K_GEN_BIN_MASK_OCTET);
                  v4 = (unsigned char) (((*(p_cfg + indexInCfg))
                        >> K_GEN_BIN_DECAL_OCTET_4) & K_GEN_BIN_MASK_OCTET);
                  v = v1 | v2 | v3 | v4;

                  /* write data in binary file*/
                  outputFile.write((char*) &v, sizeof(int));
               }

               m_listVars[indexInVariableList]->printInfo();
               LOG(INFO) << "Variable found!" << endl;

               /*go to the next element in the structure*/
               indexInCfg = indexInCfg
                     + m_listVars[indexInVariableList]->getSize();

            }
            else
            {
               /*Si ce n'est pas le cas, il loggue une erreure (mais n'abandonne pas... Par contre le fichier ne sera pas généré)*/
               LOG(ERROR) << "Variable: " << m_listVars[indexInVariableList]->getDescripton() <<  " is out of bounces!";
            }
         }
         else
         {
            /*S'il ne trouve pas, log l'erreure en mentionnant la position et le nom de la variable précédente et on ne genere pas le fichier*/
            LOG(ERROR) << "La variable située a position " << indexInCfg
                  << " dans le fichier cfg associé au module n'est pas encore associée";
         }
         /*passe a la variable du module suivante*/
         indexInCfg++;
      }

      outputFile.close();
   }
   else
   {
      /*impossible to open the file*/
      LOG(ERROR) << "impossible to open the output file: " << fileName;
   }
}

void Module::printInfo(void)const{
   unsigned int i,nbVariables = m_listVars.size();
   LOG(INFO) << "Module file in:" << m_inputFileName << " file out: " << m_outputFileName;
   LOG(INFO) << "The number of attached variables is: " << nbVariables;
   LOG(INFO) << "The size total of attached variables is: " << totalSize();
   /*print all variables in the list*/
   for (i=0;i<nbVariables;i++){
      m_listVars[i]->printInfo();
   }
}


/*Retrieve the sum of size of associated variables*/
int Module::totalSize(void) const{
   int size = 0;
   /*parcours le vector et somme les tailles*/
   unsigned int i,nbVariables = m_listVars.size();
   for (i=0;i<nbVariables;i++){
      size = size + m_listVars[i]->getSize();
   }
   return (size);
}
