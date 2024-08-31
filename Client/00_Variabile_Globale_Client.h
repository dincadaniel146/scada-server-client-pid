/*########################################################################## */
/*        Variabile globale declaratii prototip functii >>>>SERVER           */
/*########################################################################## */

/*---------------------------------------------------------------------------*/
/* Declaratii prototip functii                                               */
/*---------------------------------------------------------------------------*/
int CVICALLBACK ClientTCP_INT_Comunicatie (unsigned handle, int event, int error,
                             void *callbackData);
static void ReportTCPError (void);

/*---------------------------------------------------------------------------*/
/* Variabile globale                                                         */
/*---------------------------------------------------------------------------*/
static unsigned int g_hconversation;
static int          g_hmainPanel;
static int			g_connected = 0;
static int			g_TCPError = 0;

//Variabila Automat / Manual Server
double var_A_M;

double client_Refk;
double client_Te, Te;
double yTr, epsk, epsk_1,epsk_2, tk, tk_1, yPIDk, yPIDk_1, yPIDk_2;

double alpha, Kr, Ti, Td; 
double p0, p1, p2, q0, q1, q2;
double a1, a2, b0, b1, b2;

float Refk, Refk_1, Refk_2, Refk0;   

int sel_ref;
double timp_rampa_tk, timp_sinus_tk,timp_rectangular_tk;
double T_sin, A_sin;
int comutare_Sin;
