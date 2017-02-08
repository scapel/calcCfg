/*
 * Filter.cpp
 *
 *  Created on: 16 déc. 2016
 *      Author: scapel
 */
#include "easylogging++.h"

#include "Filter.h"
#include "ParamMere.h"
#include "Filter.h"

using namespace std;

Filter::Filter(void* p_cfg, string descriptorName,Module& module,ParamFloat const &gain, ParamFloat const &ti, ParamFloat const &te):
      ParamMere(DIR_OUT, p_cfg, descriptorName,module,3)
{}

Filter::~Filter()
{}

LowPassFilter::LowPassFilter(void* p_cfg, string descriptorName,Module& module,ParamFloat const &gain, ParamFloat const &ti, ParamFloat const &te):
      Filter(p_cfg,descriptorName,module,gain,ti,te)
{
   /*calcul avec des doubles, on cast au dernier moment*/
   double dTi = (double)ti.getValue(),dTe=(double)te.getValue(),dGain=(double)gain.getValue();

   ((FDBM_T_F1_COEF*)m_p_value)->a1 = (float)(dTi/(dTe+dTi));
   ((FDBM_T_F1_COEF*)m_p_value)->b0 = (float)(dGain*dTe/(dTe+dTi));
   ((FDBM_T_F1_COEF*)m_p_value)->b1 = 0.0f;
}
void* LowPassFilter::getAdressOfValue(void){
   return (m_p_value);
}

bool LowPassFilter::testBounces(void) const {return 1;}

void LowPassFilter::printInfo(void) const{
   LOG(INFO) << "Low Pass Filter, a1: " <<  ((FDBM_T_F1_COEF*)m_p_value)->a1 << " b0: " <<((FDBM_T_F1_COEF*)m_p_value)->b0 << " b1: " << ((FDBM_T_F1_COEF*)m_p_value)->b1 << " (" << m_descriptorName << ")" ;
}

