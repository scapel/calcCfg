/*
 * ParamInt.cpp
 *
 *  Created on: 12 d�c. 2016
 *      Author: scapel
 */
#include <string>
#include <iostream>
#include "common.h"
#include "ParamMere.h"
#include "ParamInt.h"
#include "ParamFloat.h"

using namespace std;

ParamInt::ParamInt(t_direction direction, void* p_cfg,
      string descriptorName,Module& module, int value, int min, int max) :
      ParamMere(direction, p_cfg, descriptorName,module,1), m_value(value), m_minValue(
            min), m_maxValue(max)
{
   // m_p_value initialized in ParamMere constructor in case of direction OUT or IN OUT
   if (direction == IN)
      m_p_value = &m_value;
}

/*A simplest constructor For IN Value*/
ParamInt::ParamInt(string descriptorName,Module& module, int value, int min, int max) :
      ParamMere(IN, 0, descriptorName,module,1), m_value(value), m_minValue(
            min), m_maxValue(max)
{
   m_p_value = &m_value;
}


void ParamInt::setValue(int const val)
{
   *(int*)m_p_value = val;
}
int ParamInt::getValue(void) const
{
   return(*(int*)m_p_value);
}
void ParamInt::printInfo(void) const{
   cout << *(int*)m_p_value << " (" << m_descriptorName << "\\" << directionString() << ")" << endl;
}
bool ParamInt::testBounces(void) const{
   return (*(int*)m_p_value <= m_maxValue && *(int*)m_p_value >= m_minValue);
}


/*SHORT OPERATOR*/
/****************/
/*Affectation   */
/****************/
ParamInt& ParamInt::operator=(ParamInt const& param)
{
   *(int*)m_p_value = *(int*)param.m_p_value;
   return (*this);
}
ParamInt& ParamInt::operator=(ParamFloat const& param)
{
   *(int*)m_p_value = (int)param.getValue();
   return (*this);
}
ParamInt& ParamInt::operator=(int param)
{
   *(int*)m_p_value = param;
   return (*this);
}
ParamInt& ParamInt::operator=(float param)
{
   *(int*)m_p_value = (int)param;
   return (*this);
}
/****************/
/*Addition      */
/****************/
ParamInt& ParamInt::operator+=(ParamInt const& param)
{
   *(int*)m_p_value += *(int*)param.m_p_value;
   return (*this);
}
ParamInt& ParamInt::operator+=(ParamFloat const& param)
{
   *(int*)m_p_value += (int)param.getValue();
   return (*this);
}
ParamInt& ParamInt::operator+=(int param)
{
   *(int*)m_p_value += param;
   return (*this);
}
ParamInt& ParamInt::operator+=(float param)
{
   *(int*)m_p_value += (int)param;
   return (*this);
}
/****************/
/*Multiplication*/
/****************/
ParamInt& ParamInt::operator*=(ParamInt const& param)
{
   *(int*)m_p_value *= *(int*)param.m_p_value;
   return (*this);
}
ParamInt& ParamInt::operator*=(ParamFloat const& param){
   *(int*)m_p_value *= (int)param.getValue();
   return (*this);
}
ParamInt& ParamInt::operator*=(int param)
{
   *(int*)m_p_value *= param;
   return (*this);
}
ParamInt& ParamInt::operator*=(float param)
{
   *(int*)m_p_value *= (int)param;
   return (*this);
}

/****************/
/*Division*/
/****************/
ParamInt& ParamInt::operator/=(ParamInt const& param)
{
   *(int*)m_p_value /= *(int*)param.m_p_value;
   return (*this);
}
ParamInt& ParamInt::operator/=(ParamFloat const& param)
{
   *(int*)m_p_value /= (int)param.getValue();
   return (*this);
}
ParamInt& ParamInt::operator/=(int param)
{
   *(int*)m_p_value /= param;
   return (*this);
}
ParamInt& ParamInt::operator/=(float param)
{
   *(int*)m_p_value /= (int)param;
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

