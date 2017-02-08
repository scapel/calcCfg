/*
 * strOperation.cpp
 *
 *  Created on: 7 févr. 2017
 *      Author: scapel
 */
#include <string>
#include <sstream>
#include <regex>

#include "easylogging++.h"

using namespace std;

int getNumericSuffix (string strToAnalyse, string strPrefix)
{
   int returnValue = -1;
   /** Contruction of regex expression*/
   stringstream ss;
   ss << ".*" << strPrefix << "([[:digit:]]+)" ;
   string regexpExpression = ss.str();
   /** Result of regex operation */
   smatch result;

   /*Extrait le numero de conf*/
   regex leading(regexpExpression);
   regex_search(strToAnalyse, result, leading);

   if (result[1].str().length() > 0)
      returnValue = stoi(result[1].str(),NULL);

   return returnValue;
//   if (regex_match (argS,leading_option))
//   {
//      LOG(DEBUG)<<"The string is found!";
//   }
}
