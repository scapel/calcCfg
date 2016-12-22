/*
 * ParamFloat.cpp
 *
 *  Created on: 16 d�c. 2016
 *      Author: scapel
 */

#include <string>
#include <iostream>
#include "common.h"
#include "ParamMere.h"
#include "ParamFloat.h"

using namespace std;

//ParamFloat(t_direction direction,void* p_cfg, std::string descriptorName,float value,float min,float max);
ParamFloat::ParamFloat(t_direction direction, void* p_cfg,
      string descriptorName, float value, float min, float max) :
      ParamMere(direction, p_cfg, descriptorName), m_value(value), m_minValue(
            min), m_maxValue(max)
{
   // TODO Auto-generated constructor stub
}

void ParamFloat::setValue(float const val)
{
   m_value = val;
}
float ParamFloat::getValue(void) const
{
   return(m_value);
}
void ParamFloat::printInfo(void) const{
   cout << m_value << " (" << m_descriptorName << ")" << endl;
}
bool ParamFloat::testBounces(void) const{
   return (m_value <= m_maxValue && m_value >= m_minValue);
}


/*SHORT OPERATOR*/
/****************/
/*Addition      */
/****************/
ParamFloat& ParamFloat::operator+=(ParamFloat const& param)
{
   m_value += param.m_value;
   return (*this);
}
ParamFloat& ParamFloat::operator+=(ParamInt const& param)
{
   m_value += param.getValue();
   return (*this);
}
ParamFloat& ParamFloat::operator+=(float param)
{
   m_value += param;
   return (*this);
}
ParamFloat& ParamFloat::operator+=(int param)
{
   m_value += (float)param;
   return (*this);
}
/****************/
/*Multiplication*/
/****************/
ParamFloat& ParamFloat::operator*=(ParamFloat const& param)
{
   m_value *= param.m_value;
   return (*this);
}
ParamFloat& ParamFloat::operator*=(ParamInt const& param)
{
   m_value *= param.getValue();
   return (*this);
}
ParamFloat& ParamFloat::operator*=(float param)
{
   m_value *= param;
   return (*this);
}
ParamFloat& ParamFloat::operator*=(int param)
{
   m_value *= (float)param;
   return (*this);
}

/****************/
/*Division*/
/****************/
ParamFloat& ParamFloat::operator/=(ParamFloat const& param)
{
   m_value /= param.m_value;
   return (*this);
}
ParamFloat& ParamFloat::operator/=(ParamInt const& param)
{
   m_value /= param.getValue();
   return (*this);
}
ParamFloat& ParamFloat::operator/=(int param)
{
   m_value /= (float)param;
   return (*this);
}
ParamFloat& ParamFloat::operator/=(float param)
{
   m_value /= (int)param;
   return (*this);
}


/****************************************************************/
/*ADDITION*/
/****************************************************************/
/*ParamInt1+ParamInt2*/
ParamFloat operator+(ParamFloat const& param1,ParamFloat const& param2){
   ParamFloat copie(param1);
   copie += param2;
   return copie;
}
/*ParamInt1+f*/
ParamFloat operator+(ParamFloat const& param1,float const& param2){
   ParamFloat copie(param1);
   copie += param2;
   return copie;
}
/*N+ParamInt1*/
ParamFloat operator+(float const& param1,ParamFloat const& param2){
   ParamFloat copie(param2);
   copie += param1;
   return copie;
}

/*ParamFloat+ParamInt2*/
ParamFloat operator+(ParamFloat const& param1,ParamInt const& param2){
   ParamFloat copie(param1);
   copie += param2;
   return copie;
}
/*ParamInt2+ParamFloat*/
ParamFloat operator+(ParamInt const& param1,ParamFloat const& param2){
   ParamFloat copie(param2);
   copie += param1;
   return copie;
}

/*ParamInt1+N*/
ParamFloat operator+(ParamFloat const& param1,int const& param2){
   ParamFloat copie(param1);
   copie += param2;
   return copie;
}
/*N+ParamInt1*/
ParamFloat operator+(int const& param1,ParamFloat const& param2){
   ParamFloat copie(param2);
   copie += param1;
   return copie;
}

/****************************************************************/
/*MULTIPLICATION*/
/****************************************************************/
/*ParamInt*ParamInt2*/
ParamFloat operator*(ParamFloat const& param1,ParamFloat const& param2){
   ParamFloat copie(param1);
   copie *= param2;
   return copie;
}
/*ParamInt1*N*/
ParamFloat operator*(ParamFloat const& param1,float const& param2){
   ParamFloat copie(param1);
   copie *= param2;
   return copie;
}
/*N*ParamInt1*/
ParamFloat operator*(float const& param1,ParamFloat const& param2){
   ParamFloat copie(param2);
   copie *= param1;
   return copie;
}

ParamFloat operator*(ParamFloat const& param1,ParamInt const& param2){
   ParamFloat copie(param1);
   copie *= param2;
   return copie;
}
ParamFloat operator*(ParamInt const& param1,ParamFloat const& param2){
   ParamFloat copie(param2);
   copie *= param1;
   return copie;
}
ParamFloat operator*(ParamFloat const& param1,int const& param2){
   ParamFloat copie(param1);
   copie *= param2;
   return copie;
}
ParamFloat operator*(int const& param1,ParamFloat const& param2){
   ParamFloat copie(param2);
   copie *= param1;
   return copie;
}



/****************************************************************/
/*DIVISION*/
/****************************************************************/
/*ParamInt1/ParamInt2*/
ParamFloat operator/(ParamFloat const& param1,ParamFloat const& param2){
   ParamFloat copie(param1);
   copie /= param2;
   return copie;
}
/*ParamInt1/N*/
ParamFloat operator/(ParamFloat const& param1,float const& param2){
   ParamFloat copie(param1);
   copie /= param2;
   return copie;
}
/*N/ParamInt1*/
ParamFloat operator/(float const& param1,ParamFloat const& param2){

   /*get property of param2 but set its value to param1*/
   ParamFloat copie(param2);
   copie.setValue(param1);
   copie /= param2;
   return copie;
}
ParamFloat operator/(ParamFloat const& param1,ParamInt const& param2){
   /*get property of param2 but set its value to param1*/
   ParamFloat copie(param1);
   copie /= param2;
   return copie;
}
ParamFloat operator/(ParamInt const& param1,ParamFloat const& param2){
   /*recupere les memes attribues que le param2*/
   ParamFloat copie(param2);
   /*on y colle la value de l'int cast�*/
   copie.setValue((float)param1.getValue());
   copie /= param2;
   return copie;
}
ParamFloat operator/(ParamFloat const& param1,int const& param2)
{
   /*recupere les memes attribues que le param2*/
   ParamFloat copie(param1);
   copie /= param2;
   return copie;
}
ParamFloat operator/(int const& param1,ParamFloat const& param2)
{
   /*recupere les memes attribues que le param2*/
   ParamFloat copie(param2);
   /*on y colle la value de l'int cast�*/
   copie.setValue((float)param1);
   copie /= param2;
   return copie;
}


ParamFloat::~ParamFloat()
{
   // TODO Auto-generated destructor stub
}


