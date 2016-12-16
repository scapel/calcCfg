/*
 * Filter.h
 *
 *  Created on: 16 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_FILTER_H_
#define COMMON_FILTER_H_

#include <string>
#include <ParamMere.h>


class Filter: public ParamMere
{
public:
   Filter();

   virtual ~Filter();

protected:
   /*coef du filtre*/
   float m_coef_a1;
   float m_coef_b0;
   float m_coef_b1;


};

#endif /* COMMON_FILTER_H_ */
