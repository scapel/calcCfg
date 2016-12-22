/*
 * ParamMere.h
 *
 *  Created on: 12 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_PARAMMERE_H_
#define COMMON_PARAMMERE_H_

#include <string>
#include "common.h"


class ParamMere
{
public:
   ParamMere(t_direction direction,void* p_cfg,std::string m_descriptorName);
   virtual ~ParamMere();

   /*fonction purement virtuelle qui devra etre defini dans les enfants +=*/
   virtual void printInfo(void) const = 0;
   virtual bool testBounces(void) const = 0;
protected:
   t_direction m_direction;
   /*address in configuration structure for out and in_out direction*/
   void* m_p_cfg;
   /*its descriptor name in text type file (in entry or output)*/
   std::string m_descriptorName;
};

#endif /* COMMON_PARAMMERE_H_ */
