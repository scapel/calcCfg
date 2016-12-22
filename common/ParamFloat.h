/*
 * ParamFloat.h
 *
 *  Created on: 16 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_PARAMFLOAT_H_
#define COMMON_PARAMFLOAT_H_

#include <string>
#include <iostream>
#include "common.h"
#include "ParamMere.h"
#include "ParamInt.h"

class ParamFloat: public ParamMere
{
public:
   ParamFloat(t_direction direction,void* p_cfg, std::string descriptorName,float value,float min,float max);

   ParamFloat& operator+=(ParamFloat const& param);
   ParamFloat& operator+=(ParamInt const& param);
   ParamFloat& operator+=(int param);
   ParamFloat& operator+=(float param);

   ParamFloat& operator*=(ParamFloat const& param);
   ParamFloat& operator*=(ParamInt const& param);
   ParamFloat& operator*=(int param);
   ParamFloat& operator*=(float param);

   ParamFloat& operator/=(ParamFloat const& param);
   ParamFloat& operator/=(ParamInt const& param);
   ParamFloat& operator/=(int param);
   ParamFloat& operator/=(float param);


   virtual void printInfo(void) const;
   virtual void setValue(float const val);
   virtual float getValue(void) const;
   virtual bool testBounces(void) const;

   virtual ~ParamFloat();

protected:
   /*Value*/
   float m_value;
   float m_minValue;
   float m_maxValue;
};

ParamFloat operator+(ParamFloat const& param1,ParamFloat const& param2);
ParamFloat operator+(ParamFloat const& param1,float const& param2);
ParamFloat operator+(float const& param1,ParamFloat const& param2);

ParamFloat operator+(ParamFloat const& param1,ParamInt const& param2);
ParamFloat operator+(ParamInt const& param1,ParamFloat const& param2);
ParamFloat operator+(ParamFloat const& param1,int const& param2);
ParamFloat operator+(int const& param1,ParamFloat const& param2);


/*Mult*/
ParamFloat operator*(ParamFloat const& param1,ParamFloat const& param2);
ParamFloat operator*(ParamFloat const& param1,float const& param2);
ParamFloat operator*(float const& param1,ParamFloat const& param2);

ParamFloat operator*(ParamFloat const& param1,ParamInt const& param2);
ParamFloat operator*(ParamInt const& param1,ParamFloat const& param2);
ParamFloat operator*(ParamFloat const& param1,int const& param2);
ParamFloat operator*(int const& param1,ParamFloat const& param2);

/*div*/
ParamFloat operator/(ParamFloat const& param1,ParamFloat const& param2);
ParamFloat operator/(ParamFloat const& param1,float const& param2);
ParamFloat operator/(float const& param1,ParamFloat const& param2);

ParamFloat operator/(ParamFloat const& param1,ParamInt const& param2);
ParamFloat operator/(ParamInt const& param1,ParamFloat const& param2);
ParamFloat operator/(ParamFloat const& param1,int const& param2);
ParamFloat operator/(int const& param1,ParamFloat const& param2);


#endif /* COMMON_PARAMFLOAT_H_ */
