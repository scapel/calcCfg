/*
 * ParamMere.h
 *
 *  Created on: 12 d�c. 2016
 *      Author: scapel
 */

#ifndef COMMON_PARAMMERE_H_
#define COMMON_PARAMMERE_H_

#include <string>
#include "common.h"
#include "module.h"

class Module;

class ParamMere
{
public:
   ParamMere(t_direction direction,void* p_cfg,std::string m_descriptorName,Module& module,int size);
   virtual ~ParamMere();

   /*fonction purement virtuelle qui devra etre defini dans les enfants +=*/
   virtual void printInfo(void) const = 0;
   virtual bool testBounces(void) const = 0;
   virtual void* getAdressOfValue(void);
//   virtual void* getAdressInCfg(void);


protected:
   std::string directionString(void)const;
   /*in out or in out*/
   t_direction m_direction;
   /*address in configuration structure for out and in_out direction*/
   void* m_p_cfg;
   /*address of the parameter value*/
   void* m_p_value;
   /*its descriptor name in text type file (in entry or output)*/
   std::string m_descriptorName;
   /*size (unity:32bits for DSP)*/
   int m_size;
};


#endif /* COMMON_PARAMMERE_H_ */
