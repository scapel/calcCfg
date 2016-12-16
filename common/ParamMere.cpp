/*
 * ParamMere.cpp
 *
 *  Created on: 12 déc. 2016
 *      Author: scapel
 */
#include <string>
#include <ParamMere.h>

using namespace std;

ParamMere::ParamMere(t_direction direction,void* p_cfg, std::string descriptorName):
      m_direction(direction),m_p_cfg(p_cfg),m_descriptorName(descriptorName)
{
   // TODO Auto-generated constructor stub

}


ParamMere::~ParamMere()
{
   // TODO Auto-generated destructor stub
}

