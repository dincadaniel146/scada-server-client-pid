/*########################################################################## */
/*        Variabile globale declaratii prototip functii >>>>SERVER           */
/*########################################################################## */

/*---------------------------------------------------------------------------*/
/* Declaratii prototip functii                                               */
/*---------------------------------------------------------------------------*/
int CVICALLBACK ServerTCP_INT_Comunicatie (unsigned handle, int event, int error,
							 void *callbackData);

static void ReportTCPError (void);
int transmisie_catre_client ();
int animatie_Bazin();

/*---------------------------------------------------------------------------*/
/* Variabile globale                                                         */
/*---------------------------------------------------------------------------*/
static unsigned int g_hconversation = 0;
static int          g_hmainPanel = 0;
static int			g_TCPError = 0;
double server_Te;
double server_Refk,server_Refk_1, client_uk,client_uk_1;
//Variabila Automat / Manual Server
double var_A_M;

//Variabila testare conectare Apl. Client
int conectare_Client;

//double yk,yk_1,C, uk, uk_1, tk_1, tk, Te, T;
//double C1,C2,yk2,yk2_1,yk3,yk3_1;
double yk,yk_1,C, uk, uk_1, tk_1, tk, Te, T,Tr,Tee1,Tee2;
double C1,C2,yk2,yk2_1,yk3,yk3_1;
double yEE2,yEE2_1,yTR1,yTR1_1,Cee1,Cee2,Ctr1,yTRk;