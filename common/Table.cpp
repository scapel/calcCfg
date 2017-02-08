/*
 * Table.cpp
 *
 *  Created on: 9 janv. 2017
 *      Author: scapel
 */

#include <Table.h>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "easylogging++.h"

#include "ParamMere.h"
#include "ParamInt.h"
#include "ParamFloat.h"

using namespace std;

/*Constructor for table of int*/
Table::Table(int size, ParamInt& val):m_size(size)
{

//   /*Retrieve attribute*/
   int value,min,max;

   ParamInt* valTemp = 0;
   /*description*/
   string desc;

   /*get value*/
   value = val.getValue();

   /*get module*/
   Module& module = val.getModule();

   /*get description*/
   desc = val.getDescripton();

   /*pop variable to put table instead into the module*/
   module.removeVar(val);

   /*get min max*/
   if (val.getBounces(min,max) != 0)
   {
      LOG(ERROR) << "Error for retrieve min,max value";
   }

   for (int i=0;i<size;i++)
   {
      /*Construct the descriptor for the element*/
      stringstream descStream;
      descStream << desc << "." << i;

      valTemp = new ParamInt(descStream.str(),module,value,min,max);
      /*variable to the table*/
      m_tab.push_back(valTemp);
   }
}
/*Constructor for table of float*/
Table::Table(int size, ParamFloat& val):m_size(size)
{

//   /*Retrieve attribute*/
   float value,min,max;

   ParamFloat* valTemp = 0;
   /*description*/
   string desc;
   string descTmp;

   /*get value*/
   value = val.getValue();

   /*get module*/
   Module& module = val.getModule();

   /*get description*/
   desc = val.getDescripton();

   /*pop variable to put table instead into the module*/
   module.removeVar(val);

   /*get min max*/
   if (val.getBounces(min,max) != 0)
   {
      LOG(ERROR) << "Error for retrieve min,max value";
   }

   for (int i=0;i<size;i++)
   {
      stringstream descStream;
      /*Construct the descriptor for the element*/
      descStream << desc << "." << i;
      valTemp = new ParamFloat(descStream.str(),module,value,min,max);
      /*variable to the table*/
      m_tab.push_back(valTemp);
   }
}

/*Return an element*/
ParamMere* Table::getElement(int position) const{
   if (position < (int)m_tab.size())
   {
      return (m_tab[position]);
   }
   else
   {
      /*Position is out of order*/
      return (0);
   }
}

Table::~Table()
{
   for (unsigned int position = 0; position<m_tab.size();position++){
      delete(m_tab[position]);
   }
}


