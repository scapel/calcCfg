/*
 * ParamInt.h
 *
 *  Created on: 12 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_PARAMINT_H_
#define COMMON_PARAMINT_H_

#include <string>
#include "common.h"
#include <ParamMere.h>



class ParamInt: public ParamMere
{
public:
   ParamInt(t_direction direction,void* p_cfg, std::string descriptorName,int value,int min,int max);

   virtual ~ParamInt();

   ParamInt& operator+=(ParamInt const& param);
   ParamInt& operator+=(int param);
   ParamInt& operator+=(float param);

   ParamInt& operator*=(ParamInt const& param);
   ParamInt& operator*=(int param);
   ParamInt& operator*=(float param);

   ParamInt& operator/=(ParamInt const& param);
   ParamInt& operator/=(int param);
   ParamInt& operator/=(float param);

   virtual void printInfo(void) const;
   virtual void setValue(int const val);
   virtual bool testBounces(void) const;

protected:
   /*Value*/
   int m_value;
   int m_minValue;
   int m_maxValue;
};

ParamInt operator+(ParamInt const& param1,ParamInt const& param2);
ParamInt operator+(ParamInt const& param1,int const& param2);
ParamInt operator+(int const& param1,ParamInt const& param2);

ParamInt operator*(ParamInt const& param1,ParamInt const& param2);
ParamInt operator*(ParamInt const& param1,int const& param2);
ParamInt operator*(int const& param1,ParamInt const& param2);

ParamInt operator/(ParamInt const& param1,ParamInt const& param2);
ParamInt operator/(ParamInt const& param1,int const& param2);
ParamInt operator/(int const& param1,ParamInt const& param2);

#endif /* COMMON_PARAMINT_H_ */
