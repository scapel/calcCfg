/*
 * Module.h
 *
 *  Created on: 8 déc. 2016
 *      Author: scapel
 */

#ifndef MODULE_H_
#define MODULE_H_

#include <string>
#include <vector>
#include "ParamMere.h"

class ParamMere;

class Module{
public:
   Module(std::string inputFileName,std::string outputFileName,void* p_cfg, int size);
   virtual void addVar(ParamMere *param);
   virtual void generate(void) const;
   virtual void printInfo(void) const;
   virtual ~Module();
private:
   std::string m_inputFileName,m_outputFileName;
   void* m_p_cfg;
   int m_size;//<!size of the associated structure
   std::vector<ParamMere*> m_listVars;
};



#endif /* MODULE_H_ */
