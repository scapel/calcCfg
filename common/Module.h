/*
 * Module.h
 *
 *  Created on: 8 déc. 2016
 *      Author: scapel
 */

#ifndef MODULE_H_
#define MODULE_H_

#include <string>

class Module{
public:
   Module(std::string inputFileName,std::string outputFileName);
private:
   std::string m_inputFileName,m_outputFileName;
};



#endif /* MODULE_H_ */
