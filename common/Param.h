/*
 * Param.h
 *
 *  Created on: 7 déc. 2016
 *      Author: scapel
 */

#ifndef PARAM_H_
#define PARAM_H_

#include <string>
#include "common.h"
#include "Module.h"




class Param {
public:
   /*Constructor*/

   /*int type without bounce*/
   Param (int value,t_direction direction,void* p_cfg, std::string desc,Module& module);
   /*int type with bounce*/
   Param (int value,t_direction direction,void* p_cfg, int minValue,int maxValue,std::string desc,Module& module);

   /*float type without bounce*/
   Param (float value,t_direction direction,void* p_cfg, std::string desc,Module& module);

//   Param (bool value,t_direction direction);

   /*print information*/
   void printInfo(void) const;

   /*get type*/
   t_type getType(void) const;

   /*get value*/
   void getValue(int& value) const;
   void getValue(float& value) const;
   void getValue(bool& value) const;

   /*operation*/
   /*+=*/
   Param& operator+=(Param const& param);
   /*=*/
   Param& operator=(Param const& param);
   Param& operator=(int const& intValue);
   Param& operator=(float const& intValue);

private:
   t_type m_type;
   t_direction m_direction;
   /*Value*/
   int m_intValue;
   float m_floatValue;
   bool m_boolValue;
   /*address in configuration structure*/
   void* m_p_cfg;
   /*bounces*/
   int m_minIntValue;
   float m_minFloatValue;
   int m_maxIntValue;
   float m_maxFloatValue;
   bool m_isBouncesMustBeTested;
   /*its descriptor name in text type file (in entry or output)*/
   std::string m_descriptorName;
   /*attached module*/
   Module& m_module;
};

Param operator+(Param& val1, Param& val2) ;


#endif /* PARAM_H_ */
