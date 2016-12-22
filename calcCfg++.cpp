//============================================================================
// Name        : calcCfg++.cpp
// Author      : sebC
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Module.h"
#include "ParamMere.h"
#include "ParamFloat.h"
#include "ParamInt.h"

using namespace std;

typedef struct{
   int val1;
   int val2;
   int val3;
   float fVal1;
   float fVal2;
   float fVal3;
}t_structParamInvOn;

t_structParamInvOn paramInvOn;


int main() {
   int nval1 = 10;
   float nfval1 = 3.14;


	cout << "Demonstration de calcCfg+" << endl;

	/*creation d'un module*/
	Module inv_on("inv_on_in","inv_on_out");

	/*Creation d'un paramètre*/
	ParamInt val1(IN,&paramInvOn.val1,"val1",10,0,100);
	ParamInt val2(IN,&paramInvOn.val2,"val2",23,0,100);
	ParamInt val3(IN,&paramInvOn.val3,"val3",1,0,100);

	ParamFloat fval1(IN_OUT,&paramInvOn.fVal1,"fVal1",3.89,-3.14,1000.0);
	fval1.printInfo();

	nfval1 /= nval1;
	cout << nfval1 << " (nfval1)" << endl;
	val1.printInfo();
	fval1.printInfo();
	fval1 = fval1 / val1;
	fval1.printInfo();
	fval1 = val1 + fval1;
	fval1.printInfo();
	return 0;
}
