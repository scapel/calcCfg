//Version parametrisateur
#ifndef ONDS_CFG_H
#define ONDS_CFG_H


/******************************************************************/
/* interface du module filgen: filtre recursif general d'ordre k  */
/* s(n) =          a1.s(n-1)+a2.s(n-2)+ ... + sk.s(n-k)           */
/*        +b0.e(n)+b1.e(n-1)+b2.e(n-2)+ ... + bk.e(n-k)           */
/******************************************************************/
#define FILGEN_ORDRE 10
#define FIL_NBCOF (2*FILGEN_ORDRE+1)
/* structure de coef du filtre d'ordre k    */
/* { ordre =k, { b0,a1, b1, ... , ak, bk }} */
/* a priori les coefs doivent etre en pmda, */
/* mais ca marche quand meme en dmda        */
typedef struct
{ int ordre;
  float coef[FIL_NBCOF];
} FILGEN_COEF;

// parametres de brassage des entrées analogiques
// voir synoptique "Brassage des entrées capteur sur le PHOS"
// les indicateurs INV_POL_CAPT(X) sont réintégrés dans la conf ea_cfg
typedef struct {
   int CONF_FPGA; // Choix de la configuration FPGA:CONF_FPGA = 1 -> FPGA 2P-1H-1O CONF_FPGA = 0 -> FPGA 2O
   int USEC_REDR;
   int ISEC_REDR;
   int CHOIX_MESURE_UF;
} T_BRASSAGE_CFG;

  // POSH_PLP_CFG : structure de parametres de palpage pour les tensions USEC31 et USEC31_0
  // il existe 2 structures de ce type dans la strucure generale des parametres de 
  // l'onduleur synchronisé ond_s_cfg : ond_s_cfg.Usec_31_plp_cfg et ond_s_cfg.Usec_31_0_plp_cfg
  // voir synoptique :  Palpage Usec31 & Usec31_0
typedef struct {
	int IND_PLP_DOUBLE_FRONTS; // indicateur IND_PLP_DOUBLE_FRONTS : a duppliquer
   int IND_USEC_REDR;         // INDUSEC_REDR: vaut 1 dans ond_s_cfg.Usec_31_plp_cfg
                              //            vaut 0 pour ond_s_cfg.Usec_31_0_plp_cfg

	float ECART_COR_PLP_MAX;   // K_ECART_COR_PLP_MAX à duppliquer: cf synoptique: Calcul de la cohérence du palpage
	float T_mes_MIN;           // T_mes_MIN : a duppliquer : synoptique : Sur détection passages à zéro de Usec31
	float T_mes_MAX;           // T_mes_MAX : a duppliquer

	                            // coeff des filtres COEF_FIL_PERIODE_USEC31 et COEF_FIL_PERIODE_USEC31_0
	FDBM_T_F1_COEF COEF_FIL_PERIODE_SIG;       // COEF_FIL_PERIODE_USEC31 et COEF_FIL_PERIODE_USEC31_0
	FDBM_T_F1_COEF COEF_FIL_PERIODE_SIG_OBS;   // COEF_FIL_PERIODE_USEC31_OBS et COEF_FIL_PERIODE_USEC31_0_OBS

	FDBM_T_F1_COEF COEFF_FIL_SIG_RED;          // FIL_USEC31_RED et FIL_USEC31_0_RED :  Ordre 1

	FDBM_T_F1_COEF FIL_SIG_CRETE;              // FIL_USEC31_CRETE et FIL_USEC31_0_CRETE

	int IND_GAIN_COR_PLP;          // IND_GAIN_COR_PLP: a duppliquer dans les 2 structures
	float SEUIL_INF_SIG_CRETE;     // SEUIL_INF_USEC31_CRETE et SEUIL_INF_USEC31_0_CRETE
	float OMEGAT_MIN_SIG_CRETE;    // OMEGAT_MIN_USEC31_0_CRETE et OMEGAT_MIN_USEC31_CRETE

	int IND_DEMO_SIG_RED;   // IND_DEMO_USEC31_RED et IND_DEMO_USEC31_0_RED
	                        // voir synoptique Mesure de Usec31_crete & Usec31_0_crete

	float USIG_CRETE_FORCEE;      // USEC31_0_CRETE_FORCEE et USEC31_CRETE_FORCEE
	int IND_FORCE_USIG_CRETE;     // IND_FORCE_USEC31_0_CRETE et IND_FORCE_USEC31_CRETE

	int T_MAINT_PERTE_SIG; // T_delai_ft_desc a duppliquer dans les 2 structures:
	                     // pour maintien des booleens demo_perte_USEC31 et demo_perte_USEC31_0

} POSH_PLP_CFG;

typedef struct {           // page 45 haut droit: calcul de fs_mes_OK
	int T_fs_mes_OK;      // TODO a utiliser  // ++ correction: int T_fs_mes_OK; ++ cette partie n'avait pas été codée (haut droit p45): il manque tol_fs_mes_max et tol_fs_mes_min
   float tol_fs_mes_min;
   float tol_fs_mes_max;
} COMMON_PLP_CFG;

typedef struct
{
	FDBM_T_F1_COEF COEF_FIL_DELTA_USEC31_SYNC; // coeff filtrage (delta = fabs(usec1 - usec1_0))
	float SEUIL_DELTA_USEC_SYNC_MAX;           // seuil max sortie filtre 
	int T_delta_Usec_OK;                       // tempo de maintien après delta < seuil
	FDBM_T_F1_COEF COEF_FIL_DELTA_AG_USEC31;   // voir synoptique:  DEMO_AG_USEC
	                                           // pour filtrage ecart de phase USEC31 et USEC31_0
} POSH_SYNC_CFG;


typedef struct {
	int IND_CL_SUIVI; // Choix utilisation du pilotage desuivi en phase de limitation de courant
} POSH_PILOT;


typedef struct { // voir synoptique: Démodulation Scalaire Périodique du Courant
	FDBM_T_F1_COEF Coef_Pb1_Demo_Scal_Jd_Pri_Perio; // pour filtrage de Jd_pri_p
	FDBM_T_F1_COEF Coef_Pb1_Demo_Scal_Jq_Pri_Perio;  // pour filtrage de Jq_pri_p
} POSH_DEMO_CFG;

typedef struct {
//	int   N_imbal;       // nombre de termes a intégrer
//	float inv_N_imbal;   // inverse du terme précédent
   float   A_n_period_integ;// nombre de periodes d'intégration EN FLOTTANT
//	int   ISEC_REDR;     // indicateur mesure de courant primaire redressée =1, non redressé= 0
	float FQ_min_calc;   // frequence minimale pour réaliser le calcul
	float A_min_th;      // valeur crete min du courant efficace  mesuré pour faire le calcul
} POSH_IMBAL_CFG;


//////////////////////////////////////////////////////////////////////////////
//           Filtrage de la consigne  : voir synoptique p54/75
//////////////////////////////////////////////////////////////////////////////
typedef struct {float inc; float dec; } FDBM_T_rampe_delta;

typedef union {
		FDBM_T_rampe_delta start_tab[3]; // filt_cons_cfg.FS.start_tab
		struct {
			FDBM_T_rampe_delta soft;      // filt_cons_cfg.FS.start.soft
			FDBM_T_rampe_delta soft2;
			FDBM_T_rampe_delta fast;
		} start;
} RAMPE3;

typedef struct {
	int IND_SOFT_START_ACTIF;
	FDBM_T_rampe_delta FS_CONS_LIM;
	RAMPE3 FS;
	RAMPE3 U;
    int NBP_GAB_FS_USEC31RMS_CONS; // nombre de point du gabarit qui suit
	FDBM_T_GABARIT GAB_FS_USEC31RMS_CONS[10];     // gabarit 
	int IND_LOI_U_SUR_F;
	FDBM_T_F1_COEF COEF_FC_PB1_USEC31_RMS_CONS;

} FILT_CONS_CFG;                 // voir synoptique p54/75
//////////////////////////////////////////////////////////////////////////////
// MATRICES : synop. p 62/76
//////////////////////////////////////////////////////////////////////////////

typedef struct {
	FDBM_T_F1_COEF COEF_FLT_PREPO;    // modele du transformateur : synopt. p 62/76
	FDBM_T_F1_COEF COEF_FLT_DECPLG;   // matrice de découplage :    synopt. p 62/76
	float R;                          // parametres R et L de la page "MATRICES" :synopt. p 62/76
	float L;
	float Cf;                     // pour matrices de découplage et pilotage suivi
	float Cfp;							// Cf*(N2_SUR_N1*N2_SUR_N1)  
} MAT_MDL_CFG;

//////////////////////////////////////////////////////////////////////////////
// parametres pour eviter les divisions par 0
typedef struct {
	float Uf;
} ANTI_DIV_ZERO;


//////////////////////////////////////////////////////////////////////////////
// parametres pour la stabilisation de tension filtre
//typedef struct {
//	FDBM_T_F1_COEF COEF_PHOA_S_PB1_UF_STAB;
//	float KSTAB;
//	float L_B_UF_CONS_USEC31_STAB;
//	float L_H_UF_CONS_USEC31_STAB;
//} UF_STAB_CFG;

typedef struct {
	int   IND_STAB_FLT;
	int   IND_DECPL_BEAT;
	FDBM_T_F1_COEF COEF_PB1_UF_STAB;
	FDBM_T_F1_COEF FC_PB1_DUF_STAB;
	FILGEN_COEF    COEF_FL10_STAB;
	float KSTAB;
	float L_B_UF_CONS_USEC31_STAB;
	float L_H_UF_CONS_USEC31_STAB;
} UF_STAB_CFG;
//////////////////////////////////////////////////////////////////////////////
// parametres pour la fonction d'antibattement
typedef struct {
	int  IND_FQ_BEAT_SUP;  // indicateur pour calcul de FQ_fcat_fil; =0: prendre K_FQ_FCAT_BEAT ; =1: filtrer wr.SUP_FQ_fcat
	float K_FQ_FCAT_BEAT;  // valeur par defaut de FQ_fcat_fil
	FDBM_T_F1_COEF COEF_FLT_PB1_FCAT; // filtre ordre 1 pour filtrage wr.SUP_FQ_fcat pour calcul de FQ_fcat_fil
	FILGEN_COEF COEF_FL10_BEAT;       // filtre recursif général d'ordre 10
	int NBP_GAB_BEAT_FLT_DELAY;            // nombre de points du gabarit qui suit
	FDBM_T_GABARIT GAB_BEAT_FLT_DELAY[10]; // gabarit frequence->temps équivalent à l’avance de phase 
                                          //   introduit par le filtre d’ordre 10 à la fréquence 2*fcat
	float KBATT;               // gain correction mod pour calcul A_mod_batt
	float L_B_MOD_ANTI_BATT;   // borne inf pour limitation A_mod_batt
	float L_H_MOD_ANTI_BATT;   // borne sup pour limitation A_mod_batt
} BEAT_CFG;
//////////////////////////////////////////////////////////////////////////////
// parametres pour choix des mesures de chaque pilotage
typedef struct {
	int IND_COURANT;
	int IND_TENSION;
} MESURES_PILOTAGE_CFG;

//////////////////////////////////////////////////////////////////////////////
// parametres communs aux 3 pilotages PRINCIPAL, SUIVI et SYNCHRO
typedef struct {
	float N1_SUR_N2;
	float inv_Kp_PID_MOD;   //  = 1.0f/Kp_PID_MOD
	FDBM_T_PIDLIM_COEF coeff_PID_MOD;
	float SEUIL_D_USEC31_CRETE_CONS;
} PIL_COMMON_CFG;
//////////////////////////////////////////////////////////////////////////////
// parametres pour pilotage principal
typedef struct {
	int IND_PREPO_ACTIF;
	FDBM_T_PILIM_COEF COEFF_PI_J_LIM;
	float Kp_PI_J_LIM;

	float SEUIL_INF_USEC31_CRETE;

	int NBP_GAB_JD_FS_RED ;
	FDBM_T_GABARIT GAB_JD_FS_RED[10];
	float FS_RED_JD_ZERO;
	FDBM_T_F2_COEF COEF_PB2_FS_CONS;
	float Kp_PD_FS;
	FDBM_T_PIDLIM_COEF COEF_PD_FS;

	int NBP_GAB_JQ_USEC31_RED;
	FDBM_T_GABARIT GAB_JQ_USEC31_RED[10];
	float USEC31_RED_JQ_ZERO;
	FDBM_T_F2_COEF COEF_PB2_USEC31_CRETE_CONS;
	FDBM_T_PIDLIM_COEF COEF_PD_USEC;
} PIL_PRINC_CFG;

typedef struct {                  // parametres pilotage synchro synoptique p61/76
	int IND_PREPO_ACTIF;
	FDBM_T_PIDLIM_COEF COEF_PID_AG;                 // PD_FS
	float inv_Kp_PID_AG;            // inverse du gain du PID
} PIL_SYNCHRO_CFG ;


#define NBP_MAX_GAB_JDQ_CONS_GAIN 10
typedef struct { 
	int IND_PREPO_ACTIF;
	int IND_CHOIX_Jdq_cons;
	int NBP_GAB_JDQ_CONS_GAIN;
	FDBM_T_GABARIT  GAB_JDQ_CONS_GAIN[NBP_MAX_GAB_JDQ_CONS_GAIN];

	float inv_Kp_PI_Jd;   // 1.0/Kp_PI_Jd
	FDBM_T_PILIM_COEF COEFF_PI_Jd;
	float inv_Kp_PI_Jq;   // 1.0/Kp_PI_Jq
	FDBM_T_PILIM_COEF COEFF_PI_Jq;
}PIL_SUIVI_CFG ;    // parametres pilotage principal synoptique p57-58/76
#define NBP_MAX_GAB_MODMAX  10
typedef struct {
	int nbp;         // nombre de points utilisés du gabarit
	FDBM_T_GABARIT gabarit[NBP_MAX_GAB_MODMAX];
} MOD_MAX_CFG;

//////////////////////////////////////////////////////////////////////////////
// @@Détection logicielle des Sur-courants & Calcul des consignes de limitation de courant
// parametres
typedef struct {
	float seuil_bas;
	float seuil_haut;
} HYST_L_H;

typedef struct {
	HYST_L_H HYST_JPRI_SCAL_FIL;
	HYST_L_H HYST_USEC_PERIO;
//	float SEUIL_U_MAX;                 // =>   HYST_USEC_PERIO.seuil_haut

//	float SEUIL_J_MAX;                 // =>   HYST_JPRI_SCAL_FIL.seuil_haut
	float K_J_CONS_LIM;
	int IND_CHOIX_COURANT_J_CONS_LIM;
} CONSLIM_SURCOURANT_CFG;

//////////////////////////////////////////////////////////////////////////////
// parametres @@Surveillance tension d' entrée hacheur et @@Surveillance captation
typedef struct {
   FDBM_T_F1_COEF COEF_HAUX_PB1_UF_SPT;      //< Coefficients pour le filtre de perte de tension ligne
   int      T_MNT_PUL;                       ///< Temps de maintient de la perte de tension ligne
   int      T_RETOUR_ULIGNE;                 ///< Tempo avant de déclarer le retour de la tension ligne
   HYST_L_H S_UF_DIVERGENCE;                 ///< hysteris de divergence de la tension ligne
   HYST_L_H S_UF_BAS;                        ///< hysteris sur la tension ligne
} PUL_CFG;

//////////////////////////////////////////////////////////////////////////////
#pragma pack(push, 4)
typedef
struct {
   T_BRASSAGE_CFG Brass_cfg;
	POSH_PLP_CFG Usec_31_plp_cfg;     // structure de parametres de palpage pour la tension USEC31
	POSH_PLP_CFG Usec_31_0_plp_cfg;   // structure de parametres de palpage pour la tension USEC31_0
	COMMON_PLP_CFG common_plp_cfg;
	POSH_SYNC_CFG sync_cfg;           // structure ... pour la fonction ETAT_SYNC 
	POSH_DEMO_CFG demo_cfg;           // structure     pour la demodulation des courants
	POSH_IMBAL_CFG imbal_cfg;         // structure ... pour la detection de desiquilibre courant phase 
	POSH_PILOT pilot;
	FILT_CONS_CFG filt_cons_cfg;      // structure pour filtrage de la consigne 
	MAT_MDL_CFG mat_mdl_cfg;          // modeles pour transformateur, matrices de découplage et inverse
	ANTI_DIV_ZERO anti_div_zero;      // pour eviter les diviions par 0;
	UF_STAB_CFG uf_stab_cfg;          // parametres stabilisation de tension filtre

	BEAT_CFG beat_cfg;

	MESURES_PILOTAGE_CFG CHOIX_P_PRINCIPAL;  // choix des mesures pour chaque pilotage : pour principal
	MESURES_PILOTAGE_CFG CHOIX_P_SUIVI;      // .. . pour pilotage de suivi
	MESURES_PILOTAGE_CFG CHOIX_P_SYNCHRO;     // .. . pour pilotage de synchronisation
                                                   // parametres
	CONSLIM_SURCOURANT_CFG  conslim_surcourant_cfg; // @@Détection logicielle des Sur-courants 
	                                                // & Calcul des consignes de limitation de courant

	PIL_COMMON_CFG pil_common_cfg;    // parametres communs aux 3 pilotages PRINCIPAL, SUIVI, SYNCHRO
	PIL_PRINC_CFG pil_princ_cfg;      // parametres pilotage principal synoptique p57-58/76

	PIL_SYNCHRO_CFG pil_synchro_cfg;  // parametres pilotage synchro synoptique p61/76
	PIL_SUIVI_CFG pil_suivi_cfg;      // parametres pilotage principal synoptique p57-58/76
	MOD_MAX_CFG mod_max;              // gabarit modmax(fs)
	PUL_CFG pul_cfg;                  // parametres @@Surveillance tension d' entrée hacheur
	                                  //  et @@Surveillance captation
//	char toto;
   HYST_L_H UF_BROSSE_COMMUT_SEUIL_FPGA; ///< hysteris sur la tension ligne


} OND_S_CFG;
#pragma pack(pop)

extern OND_S_CFG ond_s_cfg;

//!todo add protection anti-padding to be sure their is no space in memory between data (each are on 32 bits)
//#define EXPECTED_OND_S_CFG_SIZE (sizeof(int) * nb_vars_out_or_in_out)
//static_assert(sizeof(OND_S_CFG) == EXPECTED_FOO_SIZE, "Using padding!");
//static_assert (false,"coucou");
#endif
