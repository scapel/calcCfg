/*
 * Module.cpp
 *
 *  Created on: 8 déc. 2016
 *      Author: scapel
 */
#include <string.h>
#include <vector>
#include <iostream>
#include "Module.h"
#include "ParamMere.h"

using namespace std;

Module::Module(string inputFileName,string outputFileName,void* p_cfg,int size):
      m_inputFileName(inputFileName),m_outputFileName(outputFileName),m_p_cfg(p_cfg), m_size(size){
}

Module::~Module(){
}

//virtual void addVar(ParamMere *param)const;
void Module::addVar(ParamMere *param){
   m_listVars.push_back(param);
}

void Module::generate(void) const{
   int indexInCfg, indexInVariableList;
   int nbVariables = (int)m_listVars.size();//we suppose that can't be overload
   int* p_cfg = (int*)m_p_cfg;
   bool isVarFind = false;

   /*Control que les tailles soient coérentes*/
   if (m_size != nbVariables)
   {
      /*Si differente alors on logue l'erreur, on continue le traitement pour indiquer quelles variables posent pb!*/
      cout << "The Number of associated variables (" << m_listVars.size() << ") is different than the size of associate structure (" << m_size << ")" << endl;
   }

   /*Parcours la structure *_cfg.h associée */
   for (indexInCfg=0; indexInCfg < m_size; indexInCfg++)
   {
      /*Recherche la variable ou le début de structure associée */
      isVarFind = false;
      for (indexInVariableList=0;indexInVariableList<nbVariables;indexInVariableList++){
            if ( m_listVars[indexInVariableList]->getAdressOfValue() == (p_cfg+indexInCfg) )
            {
               /*var find!*/
               isVarFind = true;
               break;
            }
      }
      if (isVarFind)
      {
         /*S'il trouve, il vérifie que la variable soit dans les bornes */
         if (m_listVars[indexInVariableList]->testBounces())
         {
            /*on exporte la valeur dans le fichier binaire*/

         }
         else
         {
            /*Si ce n'est pas le cas, il loggue une erreure (mais n'abandonne pas... Par contre le fichier ne sera pas généré)*/
            cout << "Variable out of bounces!" << endl;
         }
      }
      else
      {
         /*S'il ne trouve pas, log l'erreure en mentionnant la position et le nom de la variable précédente et abandonne*/
      }
   }
}

void Module::printInfo(void)const{
   unsigned int i,nbVariables = m_listVars.size();
   cout << "Module file in:" << m_inputFileName << " file out: " << m_outputFileName << endl;
   cout << "The number of attached variables is: " << nbVariables << endl;
   /*print all variables in the list*/
   for (i=0;i<nbVariables;i++){
      m_listVars[i]->printInfo();
   }
}
