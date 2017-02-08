/*
 * Table.h
 *
 *  Created on: 9 janv. 2017
 *      Author: scapel
 */

#ifndef COMMON_TABLE_H_
#define COMMON_TABLE_H_

#include <vector>
#include <iostream>

#include "ParamMere.h"
#include "ParamInt.h"
#include "ParamFloat.h"

class ParamMere;

namespace std
{

class Table
{
public:
   Table(int size,ParamInt& val);
   Table(int size,ParamFloat& val);
   virtual ParamMere* getElement(int position) const;
   virtual ~Table();
protected:
   int m_size;
   std::vector<ParamMere*> m_tab;
};

} /* namespace std */

#endif /* COMMON_TABLE_H_ */
