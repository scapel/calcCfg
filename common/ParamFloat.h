/*
 * ParamFloat.h
 *
 *  Created on: 16 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_PARAMFLOAT_H_
#define COMMON_PARAMFLOAT_H_

#include <ParamMere.h>
#include <ParamInt.h>

class ParamFloat: public ParamMere
{
public:
   ParamFloat();

   ParamFloat& operator+=(ParamFloat const& param);
   ParamInt& operator+=(int param);
   ParamFloat& operator+=(float param);

   ParamFloat& operator*=(ParamFloat const& param);
   ParamInt& operator*=(int param);
   ParamFloat& operator*=(float param);

   ParamFloat& operator/=(ParamFloat const& param);
   ParamInt& operator/=(int param);
   ParamFloat& operator/=(float param);


   virtual void printInfo(void) const;
   virtual void setValue(float const val);
   virtual bool testBounces(void) const;

   virtual ~ParamFloat();

protected:
   /*Value*/
   float m_value;
   float m_minValue;
   float m_maxValue;
};

ParamFloat operator+(ParamInt const& param1,ParamInt const& param2);
ParamFloat operator+(ParamInt const& param1,int const& param2);
ParamFloat operator+(int const& param1,ParamInt const& param2);
ParamFloat operator*(ParamInt const& param1,ParamInt const& param2);
ParamFloat operator*(ParamInt const& param1,int const& param2);
ParamFloat operator*(int const& param1,ParamInt const& param2);
ParamFloat operator/(ParamInt const& param1,ParamInt const& param2);
ParamFloat operator/(ParamInt const& param1,int const& param2);
ParamFloat operator/(int const& param1,ParamInt const& param2);

#endif /* COMMON_PARAMFLOAT_H_ */
