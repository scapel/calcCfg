//============================================================================
// Name        : calcCfg++.cpp
// Author      : sebC
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Module.h"

#include "fdbm.h"
#include "onds_cfg.h"

#include "ParamMere.h"
#include "ParamFloat.h"
#include "ParamInt.h"
#include "Filter.h"

using namespace std;

OND_S_CFG ond_s_cfg;

int main() {


	cout << "Demonstration de calcCfg+" << endl;

	/*creation d'un module*/
	Module inv_on("inv_on_in","inv_on_out", &ond_s_cfg, (sizeof(OND_S_CFG)/sizeof(int)) );

	/*Creation d'un paramètre*/
	ParamInt val1("val1",inv_on,5,0,10);

   ParamInt val2("val2",inv_on,10,0,10);

	ParamInt CONF_FPGA(OUT,&(ond_s_cfg.Brass_cfg.CONF_FPGA),"CONF_FPGA",inv_on,0,0,10);

	val1.printInfo();
	val2.printInfo();
	CONF_FPGA.printInfo();
	CONF_FPGA = val1 + val2;
	CONF_FPGA.printInfo();

	ParamFloat gain("gain",inv_on,10.0,0,100);
	ParamFloat ti("ti",inv_on,10.0e-3,0,100);
	ParamFloat te("te",inv_on,500.0e-6,0,100);

	LowPassFilter filtre(&ond_s_cfg.beat_cfg.COEF_FLT_PB1_FCAT,"Filtre.nomMMAP",inv_on,gain,ti,te);
	filtre.printInfo();

	inv_on.printInfo();

	inv_on.generate();

	return 0;
}
