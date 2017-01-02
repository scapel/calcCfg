/*
 * Filter.h
 *
 *  Created on: 16 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_FILTER_H_
#define COMMON_FILTER_H_

#include <string>
#include "ParamMere.h"
#include "ParamFloat.h"
#include "fdbm.h"


class Filter: public ParamMere
{
public:
   Filter(void* p_cfg, std::string descriptorName,Module& module,ParamFloat const &gain, ParamFloat const &ti, ParamFloat const &te);
   virtual void printInfo(void) const = 0;
   virtual bool testBounces(void) const = 0;
   virtual void* getAdressOfValue(void) = 0;
   virtual ~Filter();

protected:
};

class LowPassFilter: public Filter
{
public:
   LowPassFilter(void* p_cfg, std::string descriptorName,Module& module,ParamFloat const &gain, ParamFloat const &ti, ParamFloat const &te);
   virtual void printInfo(void) const;
   virtual bool testBounces(void) const;
   virtual void* getAdressOfValue(void);
protected:
   /*coef du filtre*/
   //FDBM_T_F1_COEF m_coef;
};

#endif /* COMMON_FILTER_H_ */
