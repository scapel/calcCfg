/*
 * ParamInt.cpp
 *
 *  Created on: 12 déc. 2016
 *      Author: scapel
 */
#include <string>
#include <iostream>
#include "common.h"
#include <ParamMere.h>
#include <ParamInt.h>

using namespace std;

ParamInt::ParamInt(t_direction direction, void* p_cfg,
      string descriptorName, int value, int min, int max) :
      ParamMere(direction, p_cfg, descriptorName), m_value(value), m_minValue(
            min), m_maxValue(max)
{
   // TODO Auto-generated constructor stub

// Accesseur to the value
}
void ParamInt::setValue(int const val)
{
   m_value = val;
}

void ParamInt::printInfo(void) const{
   cout << m_value << " (" << m_descriptorName << ")" << endl;
}

bool ParamInt::testBounces(void) const{
   return (m_value <= m_maxValue && m_value >= m_minValue);
}


/*SHORT OPERATOR*/
/****************/
/*Addition      */
/****************/
ParamInt& ParamInt::operator+=(ParamInt const& param)
{
   m_value += param.m_value;
   return (*this);
}
ParamInt& ParamInt::operator+=(int param)
{
   m_value += param;
   return (*this);
}
ParamInt& ParamInt::operator+=(float param)
{
   m_value += (int)param;
   return (*this);
}
/****************/
/*Multiplication*/
/****************/
ParamInt& ParamInt::operator*=(ParamInt const& param)
{
   m_value *= param.m_value;
   return (*this);
}
ParamInt& ParamInt::operator*=(int param)
{
   m_value *= param;
   return (*this);
}
ParamInt& ParamInt::operator*=(float param)
{
   m_value *= (int)param;
   return (*this);
}

/****************/
/*Division*/
/****************/
ParamInt& ParamInt::operator/=(ParamInt const& param)
{
   m_value /= param.m_value;
   return (*this);
}
ParamInt& ParamInt::operator/=(int param)
{
   m_value /= param;
   return (*this);
}
ParamInt& ParamInt::operator/=(float param)
{
   m_value /= (int)param;
   return (*this);
}


/****************************************************************/
/*ADDITION*/
/****************************************************************/
/*ParamInt1+ParamInt2*/
ParamInt operator+(ParamInt const& param1,ParamInt const& param2){
   ParamInt copie(param1);
   copie += param2;
   return copie;
}
/*ParamInt1+N*/
ParamInt operator+(ParamInt const& param1,int const& param2){
   ParamInt copie(param1);
   copie += param2;
   return copie;
}
/*N+ParamInt1*/
ParamInt operator+(int const& param1,ParamInt const& param2){
   ParamInt copie(param2);
   copie += param1;
   return copie;
}
/****************************************************************/
/*MULTIPLICATION*/
/****************************************************************/
/*ParamInt*ParamInt2*/
ParamInt operator*(ParamInt const& param1,ParamInt const& param2){
   ParamInt copie(param1);
   copie *= param2;
   return copie;
}
/*ParamInt1*N*/
ParamInt operator*(ParamInt const& param1,int const& param2){
   ParamInt copie(param1);
   copie *= param2;
   return copie;
}
/*N*ParamInt1*/
ParamInt operator*(int const& param1,ParamInt const& param2){
   ParamInt copie(param2);
   copie *= param1;
   return copie;
}
/****************************************************************/
/*DIVISION*/
/****************************************************************/
/*ParamInt1/ParamInt2*/
ParamInt operator/(ParamInt const& param1,ParamInt const& param2){
   ParamInt copie(param1);
   copie /= param2;
   return copie;
}
/*ParamInt1/N*/
ParamInt operator/(ParamInt const& param1,int const& param2){
   ParamInt copie(param1);
   copie /= param2;
   return copie;
}
/*N/ParamInt1*/
ParamInt operator/(int const& param1,ParamInt const& param2){

   /*get property of param2 but set its value to param1*/
   ParamInt copie(param2);
   copie.setValue(param1);

   copie /= param2;
   return copie;
}

ParamInt::~ParamInt()
{
   // TODO Auto-generated destructor stub
}

