/*
 * ParamInt.h
 *
 *  Created on: 12 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_PARAMINT_H_
#define COMMON_PARAMINT_H_

#include <string>
#include <iostream>
#include "common.h"
#include "ParamMere.h"

class ParamFloat;

class ParamInt: public ParamMere
{
public:
   /*Constructor OUT or IN_OUT*/
   ParamInt(t_direction direction,void* p_cfg, std::string descriptorName,Module& module,int value,int min,int max);
   /*Constructor IN*/
   ParamInt(std::string descriptorName,Module& module,int value,int min,int max);

   ParamInt& operator=(ParamInt const& param);
   ParamInt& operator=(ParamFloat const& param);
   ParamInt& operator=(int param);
   ParamInt& operator=(float param);


   ParamInt& operator+=(ParamInt const& param);
   ParamInt& operator+=(ParamFloat const& param);
   ParamInt& operator+=(int param);
   ParamInt& operator+=(float param);

   ParamInt& operator*=(ParamInt const& param);
   ParamInt& operator*=(ParamFloat const& param);
   ParamInt& operator*=(int param);
   ParamInt& operator*=(float param);

   ParamInt& operator/=(ParamInt const& param);
   ParamInt& operator/=(ParamFloat const& param);
   ParamInt& operator/=(int param);
   ParamInt& operator/=(float param);

   virtual void printInfo(void) const;
   virtual void setValue(int const val);
   virtual void setValue(float const val);
   virtual int getValue(void) const;

   virtual bool testBounces(void) const;
   int getBounces(int& min,int& max) const;

   virtual ~ParamInt();

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
