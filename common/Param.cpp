/*
 * Param.cpp
 *
 *  Created on: 7 déc. 2016
 *      Author: scapel
 */

#include <iostream>
#include <string>
#include "Param.h"
#include "Module.h"

using namespace std;

/*Constructor int with bounce*/
Param::Param(int value,t_direction direction,void* p_cfg, int minValue,int maxValue,string desc,Module& module):
      m_intValue(value),m_direction(direction),m_p_cfg(p_cfg),
      m_minIntValue(minValue),m_maxIntValue(maxValue),m_descriptorName(desc),
      m_module(module),
      m_type(INT),m_isBouncesMustBeTested(true),/*deduced values*/
      m_floatValue(0.0f),m_boolValue(false),m_minFloatValue(0.0f),m_maxFloatValue(0.0f)/*unused variable set to a default value*/
      {}
/*Constructor int without bounce*/
Param::Param(int value,t_direction direction,void* p_cfg, string desc,Module& module):
      m_intValue(value),m_direction(direction),m_p_cfg(p_cfg),m_descriptorName(desc),
      m_module(module),
      m_type(INT),m_isBouncesMustBeTested(false),/*deduced values*/
      m_minIntValue(0),m_maxIntValue(0),m_floatValue(0.0f),m_boolValue(false),
      m_minFloatValue(0.0f),m_maxFloatValue(0.0f)/*unused variable set to a default value*/
      {}

/*Constructor float without bounce*/
Param::Param(float value,t_direction direction,void* p_cfg, string desc,Module& module):
      m_floatValue(value),m_direction(direction),m_p_cfg(p_cfg),m_descriptorName(desc),
      m_module(module),
      m_type(FLOAT),m_isBouncesMustBeTested(false),/*deduced values*/
      m_minIntValue(0),m_maxIntValue(0),m_intValue(0),m_boolValue(false),
      m_minFloatValue(0.0f),m_maxFloatValue(0.0f)/*unused variable set to a default value*/
      {}


/*print information*/
void Param::printInfo(void) const{
   cout << m_descriptorName << "(";
   switch (m_type)
   {
   case INT:
      cout << "int)=" << m_intValue <<endl;
      break;
   case FLOAT:
      cout << "float)=" << m_floatValue <<endl;
      break;
   case BOOL:
      cout << "bool)=" << m_boolValue <<endl;
      break;
   default:
      cout << "????" << endl;
   }
}

/*recupere type*/
t_type Param::getType(void) const{
   return m_type;
}

/*recupere valeur*/
void Param::getValue(int& value) const{
   value = m_intValue;
}
void Param::getValue(float& value) const{
   value = m_floatValue;
}
void Param::getValue(bool& value) const{
   value = m_boolValue;
}

/************/
/*Operateurs*/
/************/

/*Affectation*/
Param& Param::operator=(Param const& param){
   switch (m_type)
   {
   case INT:
      switch (param.getType())
         {
         case INT:
         {
            int tmp;param.getValue(tmp);
            m_intValue = tmp;
            break;
         }
         case FLOAT:
         {
            float tmp;param.getValue(tmp);
            m_intValue = tmp;//promotion entiere
            break;
         }
         case BOOL:
            //exception a placer ici (pas d'affectation entre un int et un bool)
            cout << "bool" << endl;
            break;
         default:
            //exception a placer ici (pas d'affectation entre un int et un bool)
            cout << "????" << endl;
            break;

         }
   // Acompleter!!!!
   case FLOAT:
      cout << "A completer pour les float" << endl;
      break;
   case BOOL:
      cout << "A completer pour les bool" << endl;
      break;
   default:
      cout << "????" << endl;
      break;
   }
   return *this;
}

Param& Param::operator=(int const& intValue){
   switch (m_type)
   {
   case INT:
      m_intValue = intValue;
      break;
   // Acompleter!!!!
   case FLOAT:
      m_floatValue = (float)intValue;
      break;
   case BOOL:
      cout << "A completer pour les bool" << endl;
      break;
   default:
      cout << "????" << endl;
      break;
   }
   return *this;
}
Param& Param::operator=(float const& floatValue){
   switch (m_type)
   {
   case INT:
      m_intValue = (int)floatValue;
      break;
   // Acompleter!!!!
   case FLOAT:
      m_floatValue = floatValue;
      break;
   case BOOL:
      cout << "A completer pour les bool" << endl;
      break;
   default:
      cout << "????" << endl;
      break;
   }
   return *this;
}


/*Addition*/
Param& Param::operator+=(Param const& param){
   switch (m_type)
   {
   case INT:
      switch (param.getType())
         {
         case INT:
         {
            int tmp;param.getValue(tmp);
            m_intValue += tmp;
            break;
         }
         case FLOAT:
         {
            float tmp;param.getValue(tmp);
            m_intValue += tmp;
            break;
         }
         case BOOL:
            cout << "A completer pour les bool" << endl;
            break;
         default:
            cout << "????" << endl;
            break;

         }
   // Acompleter!!!!
   case FLOAT:
      cout << "A completer pour les float" << endl;
      break;
   case BOOL:
      cout << "A completer pour les bool" << endl;
      break;
   default:
      cout << "????" << endl;
      break;
   }
   return *this;
}


/*Fonction externe a la classe mais manipulant des objets issus de la classe*/
Param operator+(Param& val1, Param& val2) {
   Param copie(val1);
   copie += val2;
   return copie;
}
