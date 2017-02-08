//============================================================================
// Name        : calcCfg++.cpp
// Author      : sebC
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

#include "easylogging++.h"

#include "strOperation.h"

#include "Module.h"

#include "fdbm.h"
#include "onds_cfg.h"

#include "ParamMere.h"
#include "ParamFloat.h"
#include "ParamInt.h"
#include "Filter.h"
#include "Table.h"


using namespace std;

OND_S_CFG ond_s_cfg;

//! initalize the log system
INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[]) {

   START_EASYLOGGINGPP(argc, argv);
   char* option;
   bool isDebugActived = false;
   //! Configuration number
   int confNumber = -1;

   /* Analyze arguments */
   if (argc > 2)
   {
      /* analyze all the argument */
      for (int i = 1; i < argc; i++)
      {
         /*Conversion char* to string*/
         stringstream ss;
         ss.str(argv[i]);
         string argS = ss.str();

         string debug("-debug");
         string numConf("-numConf");

         /*Debug mode?*/
         if (argS.compare(debug) == 0)
            isDebugActived = true;

         /*Extract configuration number*/
         if (confNumber < 0)
            confNumber = getNumericSuffix (argS, numConf);
      }
   }
   else
   {
      LOG(WARNING) << "The number of argument is not correct";
   }
   // Load configuration from file
   if (isDebugActived)
   {
      el::Configurations conf(".\\src\\log\\logCalCfgDebug.cfg");
      el::Loggers::reconfigureAllLoggers(conf);
   }
   else
   {
      el::Configurations conf(".\\src\\log\\logCalCfg.cfg");
      el::Loggers::reconfigureAllLoggers(conf);
   }
   //! Control the configuration number
   if (confNumber < 0)
   {
      LOG(ERROR)<<"Configuration number is not in the argument";
   }

   LOG(INFO) << "Demonstration de calcCfg+";

	ParamInt* p_var;
	/*creation d'un module*/
	//Module inv_on("C:\\workspace\\calcCfg++\\src\\trace\\02_4ONDS.txt","inv_on_out", &ond_s_cfg, (sizeof(OND_S_CFG)/sizeof(int)) );
	Module inv_on(".\\src\\trace\\02_4ONDS.txt",".\\src\\bin\\02_4OND.bin", &ond_s_cfg, (sizeof(OND_S_CFG)/sizeof(int)) );
	/*Creation de paramètres*/
	ParamInt val("val",inv_on,5,0,10);
	ParamFloat valFloat("valFloat",inv_on,2.5,-1.0,5.0);
	//ParamInt tabVal[2]={val,val};
	/*Attention, val va être désaffecté du module*/
	Table tabVal(20,val);
	Table tabValFloat(13,valFloat);
	p_var = (ParamInt*)tabVal.getElement(2);
	p_var->printInfo();
	tabVal.getElement(2)->printInfo();

	ParamInt version_1("VERSION.1",inv_on,0,1000000000,0);
	//ParamFloat Ti_Tmes_Usec31_0("Ti_Tmes_Usec31_0",inv_on,-10,10000,0);
	ParamInt IND_PLP_DOUBLE_FRONTS(DIR_IN_OUT,&(ond_s_cfg.Usec_31_0_plp_cfg.IND_PLP_DOUBLE_FRONTS),"IND_PLP_DOUBLE_FRONTS",inv_on,0,0,10);
	inv_on.readInputFile();
//	ParamInt tabValEssai("val",inv_on,5,0,10);tabValEssai.tab(10);


//	ParamInt val1("val1",inv_on,5,0,10);
//   ParamInt val2("val2",inv_on,1,0,10);
//	ParamInt CONF_FPGA(OUT,&(ond_s_cfg.Brass_cfg.CONF_FPGA),"CONF_FPGA",inv_on,0,0,10);



	/*Affichage d'informations sur les paramètres*/
//	val1.printInfo();
//	val2.printInfo();
//	CONF_FPGA.printInfo();

	/*exemple d'operation sur les paramètres*/
//	CONF_FPGA = val1 + val2;
//	CONF_FPGA.printInfo();

	/*exemple de déclaration d'un filtre*/
//	ParamFloat gain("gain",inv_on,10.0,0,100);
//	ParamFloat ti("ti",inv_on,10.0e-3,0,100);
//	ParamFloat te("te",inv_on,500.0e-6,0,100);
//	LowPassFilter filtre(&ond_s_cfg.beat_cfg.COEF_FLT_PB1_FCAT,"Filtre.nomMMAP",inv_on,gain,ti,te);
//	filtre.printInfo();

	/*Information sur le module*/
	inv_on.printInfo();

	/*generation des fichiers de sorties associées au module*/
	inv_on.generate();

	return 0;
}
