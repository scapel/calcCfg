/*
 * ParamMere.cpp
 *
 *  Created on: 12 déc. 2016
 *      Author: scapel
 */
#include <string>
#include <ParamMere.h>
#include <module.h>

using namespace std;

ParamMere::ParamMere(t_direction direction,void* p_cfg, std::string descriptorName, Module& module, int size):
      m_direction(direction), m_p_cfg(p_cfg), m_descriptorName(descriptorName), m_size(size)
{
   // Associate the parameter to a module
   module.addVar(this);
   if (direction != IN)
      m_p_value = p_cfg;
   else
      m_p_value = 0;
}

void* ParamMere::getAdressOfValue(void){
   return (m_p_value);
}

/*Return the direction of a variable */
string ParamMere::directionString(void) const
{
   string out = "UNDEFINED";
   /*   IN = 0, OUT = 1, IN_OUT = 2*/
   switch (m_direction)
   {
   case IN:
   {
      out = "IN";
   }
      break;
   case OUT:
   {
      out = "OUT";
   }
      break;
   case IN_OUT:
   {
      out = "IN_OUT";
   }
      break;
   default:
   {
      out = "UNDEFINED";
   }
   }
   return out;
}

ParamMere::~ParamMere()
{
   // TODO Auto-generated destructor stub
}

