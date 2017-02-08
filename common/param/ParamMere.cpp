/******************************************************************************/
/**  \addtogroup Param
 *  Module Param \n
 *  \BEGIN_GROUP
 *     Define the principal class for parameters \n
 *                                                                            */
/*----------------------------------------------------------------------------*/
/** \class
 *     Define the attribut \n
 *     - generation des fichiers binaires pour un jeu de parametres secondaires \n
 *     - calcul du CRC32 de chacun des fichiers generes \n
 *     - generation du fichier de resume des CRC32 \n
 *     - calcul du CRC32 du fichier de resume \n
 *
 *  \warning None.
 *
 *  \todo None.
 *                                                                            */
/******************************************************************************/

#include <string>
#include <ParamMere.h>
#include <module.h>

using namespace std;
/**
 * */
ParamMere::ParamMere(t_direction direction,void* p_cfg, std::string descriptorName, Module& module, int size):
      m_direction(direction),m_type(UNKNOWN), m_p_cfg(p_cfg), m_descriptorName(descriptorName), m_size(size),m_module(module)
{
   // Associate the parameter to a module
   module.addVar(this);

   if (direction != DIR_IN)
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
   case DIR_IN:
   {
      out = "IN";
   }
      break;
   case DIR_OUT:
   {
      out = "OUT";
   }
      break;
   case DIR_IN_OUT:
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

int ParamMere::getSize(void) const{
   return (m_size);
}

/** */
string ParamMere::getDescripton(void) const{
   return (m_descriptorName);
}

Module& ParamMere::getModule(void) const{
   return (m_module);
}

t_type ParamMere::getType(void) const{
   return (m_type);
}

/*Fonction arbitraire définie ici, qui ne devront jamais être appelée*/
int ParamMere::getBounces(int& min,int& max) const{
   return (-1);
}
//int getBounces(float& min,float& max);
int ParamMere::getBounces(float& min,float& max) const{
   return(-1);
}


ParamMere::~ParamMere()
{
   // TODO Auto-generated destructor stub
}

