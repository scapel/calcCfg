/******************************************************************************/
/* Interface de la machine : fdbm                                             */
/******************************************************************************/
#ifndef FDBM_H
#define FDBM_H

#ifdef  _INLINE
   #define __INLINE_FDBM static inline
#else
   #define __INLINE_FDBM extern
#endif

/******************************************************************************/
/* Declaration des variables d'interfaces et des types exportes               */
/******************************************************************************/
/* structure de coefficients d'un filtre general d'ordre 1                    */
typedef struct
               {
                   float a1;
                   float b0;
                   float b1;
               } FDBM_T_F1_COEF;

/* structure de donnees d'un filtre general d'ordre 1                         */
typedef struct
               {
                   float sortie;
                   float e0;
                   float e1;
               } FDBM_T_F1_DONNEES;

/******************************************************************************/
/* structure de coefficients d'un filtre general d'ordre 2                    */
typedef struct
               {
                   float a1;
                   float a2;
                   float b0;
                   float b1;
                   float b2;
               } FDBM_T_F2_COEF;

/* structure de donnees d'un filtre general d'ordre 2                         */
typedef struct
               {
                   float sortie;
                   float sortie1;
                   float e0;
                   float e1;
                   float e2;
               } FDBM_T_F2_DONNEES;

/******************************************************************************/
/* structure de donnees d'un gabarit                                          */
typedef struct
               {
                   float abs;
                   float ord;
                   float pente;
               } FDBM_T_GABARIT;

/******************************************************************************/
/* structure de donnees de la fonction hysteresis                             */
typedef struct {
                   float    smin_hyster;
                   float    smax_hyster;
                   unsigned int preced_hyster;
               } FDBM_T_HYSTER;


/******************************************************************************/
/* structure de coefficients d'un correcteur proportionnel integral           */
typedef struct {
                   float  coef0    ;
                   float  coef1    ;
                   float  smin     ;
                   float  smax     ;
               } FDBM_T_PILIM_COEF   ;

/* structure de donnees d'un correcteur proportionnel integral                */
typedef struct {
                   float  commande ;
                   float  consigne ;
                   float  mesure   ;
                   float  e0       ;
               } FDBM_T_PILIM_DONNEES ;

/******************************************************************************/
/* structure de coefficients du module d'asservissement par boucle PID        */
typedef struct {
                   float  coef0    ;
                   float  coef1    ;
                   float  coef2    ;
                   float  smin     ;
                   float  smax     ;
               } FDBM_T_PIDLIM_COEF   ;

/* structure de donnees du module d'asservissement par boucle PID             */
typedef struct {
                   float   commande ;
                   float   consigne ;
                   float   mesure   ;
                   float   e0       ;
                   float   e1       ;
               } FDBM_T_PIDLIM_DONNEES ;

/******************************************************************************/
/* structure de donnees de la fonction rampe                                  */
typedef struct {
                   float rampe_t;
                   float inc;
                   float dec;
               } FDBM_T_RAMPE;

/******************************************************************************/
/* structure de donnees de la fonction rampe a deux pentes                    */
typedef struct {
                   float rampe_t;
                   float inc[2];
                   float dec[2];
                   float pts_chgt[2];
               } FDBM_T_RAMPE2MD;

/******************************************************************************/
/* coefficient filtrage d'ordre 1 + ecretage                                  */
typedef struct  {
                 FDBM_T_F1_COEF filcoef;
                 float           val_max;
                 float           val_min;
                 float           val_max_fil;
                 float           val_min_fil;
                } FDBM_T_F1_ECR_COEF ;

/******************************************************************************/
/* coefficient filtrage d'ordre 2 + ecretage                                  */
typedef struct {
               FDBM_T_F2_COEF filcoef;
               float           val_max;
               float           val_min;
               float           val_max_fil;
               float           val_min_fil;
               } FDBM_T_F2_ECR_COEF;

/******************************************************************************/
/* compteurs d'ecretage min et max pour mise au point                         */
typedef struct  {
                 unsigned int sup;
                 unsigned int inf;
                } FDBM_CPT_ECRET;


/******************************************************************************/
/* Definition des prototypes des fonctions externes                           */
/******************************************************************************/

/* Minimum de deux variables relles                                           */
__INLINE_FDBM  float FDBM_minc_reel(const float val1, const float val2);

/* Maximum de deux variables reelles                                          */
__INLINE_FDBM  float FDBM_maxc_reel(const float val1, const float val2);

/* Limitation d'une variable reelle entre 2 bornes reelles                    */
__INLINE_FDBM  float FDBM_limvar_reel( const float b_inf,
                                       const float b_sup,
                                       float const var);

/* Maximum de deux variables reelles avec compteur en cas de depassement      */
__INLINE_FDBM float FDBM_minc_cpt_reel( const float val1,
                                        const float val2,
                                        float *cpt);

/* Minimum de deux variables reelles avec compteur en cas de depassement      */
__INLINE_FDBM float FDBM_minc_cpt_reel( const float val1,
                                        const float val2,
                                        float *cpt);

/* Filtre general d'ordre 1                                                   */
extern float FDBM_filtre1(const FDBM_T_F1_COEF * const,
                                      FDBM_T_F1_DONNEES * const);

/* Initialisation d'un filtre d'ordre 1                                       */
extern void FDBM_filtre1_init( FDBM_T_F1_DONNEES * const,
                               const float, const float);

/* Double filtre d'ordre 1 */
extern float FDBM_filtre1x2( float val_in,
                             const FDBM_T_F1_COEF *filcoef,
                             FDBM_T_F1_DONNEES *fildon ) ;

/* Initialisation d'un double filtre d'ordre 1 */
extern void FDBM_filtre1x2_init(  float val_in_out,
                                  FDBM_T_F1_DONNEES *fildon ) ;

/* Filtre general d'ordre 2                                                   */
extern float FDBM_filtre2(const FDBM_T_F2_COEF * const,
                                FDBM_T_F2_DONNEES * const);

/* Initialisation d'un filtre d'ordre 2                                       */
extern void FDBM_filtre2_init( FDBM_T_F2_DONNEES * const,
                               const float, const float ,
                               const float , const float);

/* Gabarit                                                                 */
extern float FDBM_gabarit(const FDBM_T_GABARIT *, int, const float);
/* Init du gabarit                                                         */
extern void FDBM_gabarit_init(FDBM_T_GABARIT *, int);


/* Programme d'asservissement par boucle PI                                   */
extern float FDBM_pilim( const FDBM_T_PILIM_COEF * const,
                         FDBM_T_PILIM_DONNEES * const);

/* Programme d'asservissement par boucle PI, avec coefficient                 */
extern float FDBM_pilim_var( const FDBM_T_PILIM_COEF  * const ,
                     FDBM_T_PILIM_DONNEES * const , float);

/* Initialisation des variables d'asservissement par boucle PI                */
extern void FDBM_pilim_init(FDBM_T_PILIM_DONNEES * const, const float);

/* Programme d'asservissement par boucle PID                                  */
extern float FDBM_pidlim(const FDBM_T_PIDLIM_COEF * const,
                                                FDBM_T_PIDLIM_DONNEES * const);

/* Initialisation des variables d'asservissement par boucle PID               */
extern void FDBM_pidlim_init(FDBM_T_PIDLIM_DONNEES * const, const float);

/* Rampe                                                                      */
extern float FDBM_rampe(FDBM_T_RAMPE * const, const float);

/* Initialisation des variables de la rampe                                   */
extern void FDBM_rampe_init( FDBM_T_RAMPE * const, const float,
                             const float, const float);

/* Rampe a deux pentes                                                        */
extern float FDBM_rampe2md(FDBM_T_RAMPE2MD * const, const float);

/* Initialisation des variables de la rampe a deux pentes                     */
extern void FDBM_rampe2md_init( FDBM_T_RAMPE2MD * const, const float,
                                const float, const float, const float,
                                const float, const float, const float);

/* Initialisation d'un hysteresis.                                            */
extern void FDBM_hyster_init(FDBM_T_HYSTER *, float, float, unsigned int);

/* Hysteresis : faux a l'etat bas.                                            */
extern unsigned int FDBM_hyster_sup(FDBM_T_HYSTER *, float);

/* Filtre d'ordre 1, avec ecretage avant et apres                             */
float FDBM_der_ecr_fil1( FDBM_T_F1_ECR_COEF *,
                         FDBM_T_F1_DONNEES *,
                         const float,
                         FDBM_CPT_ECRET *);

/* Filtre d'ordre 2, avec ecretage avant et apres                             */
float FDBM_der_ecr_fil2( FDBM_T_F2_ECR_COEF *,
                         FDBM_T_F2_DONNEES *,
                         const float,
                         FDBM_CPT_ECRET *);

/******************************************************************************/
/* Definition des macros                                                      */
/******************************************************************************/

#define FDBM_MINC(v1,v2) ((v1) < (v2) ? (v1) : (v2))

#define FDBM_MAXC(v1,v2) ((v1) < (v2) ? (v2) : (v1))

#define FDBM_LIMVAR(inf, sup, v) FDBM_MINC(FDBM_MAXC(v,inf),sup)

#define FDBM_MAXC_CPT(v1, v2, cpt) ((v1) > (v2) ? ((cpt) = (cpt) +1, (v1)) : (v2))

#define FDBM_MINC_CPT(v1, v2, cpt) ((v1) < (v2) ? ((cpt) = (cpt) +1, (v1)) : (v2))

/******************************************************************************/
/* Definition des prototypes des fonctions externes                           */
/******************************************************************************/

#if  !defined(FDBM_C)
        #if defined(_INLINE)
                #define INCLURE_SOURCE
        #endif
#else
        #define INCLURE_SOURCE
#endif

#ifdef INCLURE_SOURCE

/******************************************************************************/
/*                                                                            */
/*    Nom : FDBM_minc_reel                                                    */
/*                                                                            */
/*          Calcul du minimum de 2 variables reelles.                         */
/*                                                                            */
/******************************************************************************/
__INLINE_FDBM float FDBM_minc_reel(const float val1, const float val2)
{
 return(FDBM_MINC(val1, val2));
}

/******************************************************************************/
/*                                                                            */
/*    Nom : FDBM_maxc_reel                                                    */
/*                                                                            */
/*          Calcul du maximum de 2 variables reelles.                         */
/*                                                                            */
/******************************************************************************/
__INLINE_FDBM float FDBM_maxc_reel(const float val1, const float val2)
{
 return(FDBM_MAXC(val1, val2));
}

/******************************************************************************/
/*                                                                            */
/*    Nom : FDBM_limvar_reel                                                  */
/*                                                                            */
/*          Limitation en min et max d'une variable reelle.                   */
/*                                                                            */
/******************************************************************************/
__INLINE_FDBM float FDBM_limvar_reel( const float b_inf,
                                      const float b_sup,
                                      const float var)
{
 return(FDBM_LIMVAR(b_inf, b_sup, var));
}

/******************************************************************************/
/*                                                                            */
/*    Nom : FDBM_maxc_cpt_reel                                                */
/*                                                                            */
/*          Calcul du maximum de 2 variables reelles, avec incrementation     */
/*          d'un compteur en cas de depassement de la 2e variable.            */
/*                                                                            */
/******************************************************************************/
__INLINE_FDBM float FDBM_maxc_cpt_reel( const float val1,
                                        const float val2,
                                        float *cpt)
{
 return(FDBM_MAXC_CPT(val1,val2,*cpt));
}

/******************************************************************************/
/*                                                                            */
/*    Nom : FDBM_minc_cpt_reel                                                */
/*                                                                            */
/*          Calcul du minimum de 2 variables reelles, avec incrementation     */
/*          d'un compteur en cas de depassement de la 2e variable.            */
/*                                                                            */
/******************************************************************************/
__INLINE_FDBM float FDBM_minc_cpt_reel( const float val1,
                                        const float val2,
                                        float *cpt)
{
 return(FDBM_MINC_CPT(val1,val2,*cpt));
}

#endif /* INCLURE_SOURCE */
#undef _INLINE_FDBM
#undef INCLURE_SOURCE

#endif /* FDBM_H */
