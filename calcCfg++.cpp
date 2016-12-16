//============================================================================
// Name        : calcCfg++.cpp
// Author      : sebC
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Module.h"
//#include "Param.h"
#include "ParamInt.h"

using namespace std;

typedef struct{
   int val1;
   int val2;
   int val3;
}t_structParamInvOn;

t_structParamInvOn paramInvOn;


int main() {
	cout << "Demonstration de calcCfg+" << endl;

	/*creation d'un module*/
	Module inv_on("inv_on_in","inv_on_out");

	/*Creation d'un paramètre*/
	ParamInt val1(IN,&paramInvOn.val1,"val1",10,0,100);
	ParamInt val2(IN,&paramInvOn.val2,"val2",23,0,100);
	ParamInt val3(IN,&paramInvOn.val3,"val3",1,0,100);



	return 0;
}
