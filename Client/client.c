/*---------------------------------------------------------------------------*/
/*                                                                           */
/* FILE:    client.c                                                         */
/*                                                                           */
/* PURPOSE: This is a skeleton program to demonstrate how you would write a  */
/*          a TCP Client application. This program connects to an established*/
/*          TCP server and communicates via a user interface panel.  This    */
/*          sample only communicates with one server, but illustrates how to */
/*          implement a callback function to respond to TCP events.          */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Include files                                                             */
/*---------------------------------------------------------------------------*/
#include <formatio.h>
#include <cvirte.h>
#include <stdio.h>
#include <stdlib.h>
#include <tcpsupp.h>
#include <string.h>
#include <utility.h>
#include <userint.h>
#include "client.h"
#include "toolbox.h"
#include <ansi_c.h>
/*---------------------------------------------------------------------------*/
/* Macros						                                             */
/*---------------------------------------------------------------------------*/
#define tcpChk(f) if ((g_TCPError=(f)) < 0) {ReportTCPError(); goto Done;} else

/*---------------------------------------------------------------------------*/
/* //INCLUDERE BIBLIOTECI DE FUNCTII						                                             */
/*---------------------------------------------------------------------------*/ 
#include "00_Variabile_Globale_Client.h"	//Functia declarare variabile globale Client    
#include "01_Initializare_Aplicatie_Client.h"
#include "02_Functii_Utilitare_Client.h"
#include "04_Formatare_Transmisie_TCP_TX_catre_server.h" 
#include "05_formatare_TCP_RX_de_la_Server.h"
#include "06_receptie_TCP_INT_de_la_server.h" 
#include "07_Elemente_FEEDBACK.h"
#include "08_Generare_Semnale.h"
double generare_semnal();
//#########################################################
//###########      FUNCTIA PRINCIPALA  main     ###########
//#########################################################
int main (int argc, char *argv[])
{
    int  portNum;
    char tempBuf[256] = {0};
    char portNumStr[32];
    
    if (InitCVIRTE (0, argv, 0) == 0)
        return -1;
    if ((g_hmainPanel = LoadPanel(0, "client.uir", MAINPNL)) < 0)
        goto Done;
    DisableBreakOnLibraryErrors();
    /* Prompt for the name of the server to connect to */
    PromptPopup ("Server Name?",
                 "Type the name of the machine running the sample server "
                 "application.\n\n(example: abc.xyz.com or xxx.xxx.xxx.xxx)",
                 tempBuf, 255);
    /* Prompt for the port number on the server */
    PromptPopup ("Port Number?",
                 "Type the port number that was set when starting the sample "
                 "server application.\n\n(example: 10000)",
                 portNumStr, 31);
    portNum = atoi (portNumStr); 
    /* Attempt to connect to TCP server... */
    SetWaitCursor (1);
    if (ConnectToTCPServer (&g_hconversation, portNum, tempBuf, ClientTCP_INT_Comunicatie, NULL, 5000) < 0)
        MessagePopup("TCP Client", "Connection to server failed !");
    else
        {
        SetWaitCursor (0);
        g_connected = 1;
        
        /* We are successfully connected -- gather info */
        SetCtrlVal (g_hmainPanel, MAINPNL_CONNECTED, 1);
  		if (GetTCPHostAddr (tempBuf, 256) >= 0)
        	SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_IP, tempBuf);
        if (GetTCPHostName (tempBuf, 256) >= 0)
	        SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_NAME, tempBuf);
        tcpChk (GetTCPPeerAddr (g_hconversation, tempBuf, 256));
        SetCtrlVal (g_hmainPanel, MAINPNL_SERVER_IP, tempBuf);
        tcpChk (GetTCPPeerName (g_hconversation, tempBuf, 256));
        SetCtrlVal (g_hmainPanel, MAINPNL_SERVER_NAME, tempBuf);
        
        /* display the panel and run the UI */
        DisplayPanel (g_hmainPanel);
		//initializare parametrii PID
		GetCtrlVal (g_hmainPanel, MAINPNL_TE, &client_Te);
			Refk=0; Refk_1=0;  Refk_2=0; 

            sel_ref=0; 
            Te=client_Te;
            tk_1=0;
            tk=Te;
			GetCtrlVal (g_hmainPanel, MAINPNL_KR, &Kr);  
				GetCtrlVal (g_hmainPanel, MAINPNL_TI, &Ti);  
					GetCtrlVal (g_hmainPanel, MAINPNL_TD, &Td);  
			//Kr=1;  Ti=0.9;  Td=0; 
			//PID
			alpha=0.1;
			p0=Kr*((4/(Te*Te))*(alpha*Td*Ti+Ti*Td) + (2/Te)*(Ti+alpha*Td) + 1);
				p1=Kr*(-(8/(Te*Te))*(alpha* Td*Ti+Td*Ti)+2);
					p2=Kr*((4/(Te*Te))*(alpha*Td*Ti+Ti*Td) - (2/Te)*(Ti+alpha*Td) + 1); 
			
			q0=(4/(Te*Te))* Ti*alpha*Td + (2/Te)*Ti;
				q1=-(8/(Te*Te))* Ti*alpha*Td;
					q2=(4/(Te*Te))* Ti*alpha*Td - (2/Te)*Ti; 
			a1=q1/q0;  a2=q2/q0;
			b0=p0/q0;  b1=p1/q0; b2=p2/q0; 
		//Comutare pe sinus fara socuri>>>>doar dupa trecerea fct. Sin prin 0
			comutare_Sin=0;
				GetCtrlVal (g_hmainPanel, MAINPNL_A_SINUS, &A_sin);
				GetCtrlVal (g_hmainPanel, MAINPNL_T_SINUS, &T_sin);
			
        //SetActiveCtrl (g_hmainPanel, MAINPNL_STRING);
        RunUserInterface ();
        }
    
Done:
    /* Disconnect from the TCP server */
    if (g_connected)
    	DisconnectFromTCPServer (g_hconversation);

    /* Free resources and return */
    DiscardPanel (g_hmainPanel);
    CloseCVIRTE ();
	
    return 0;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$        Functia Timer  Esantionare Client   $$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
int CVICALLBACK esantionare_Client (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			if (var_A_M==0)
			{//Tratare Regim Automat
				//Citire valori potentiometru si Te
		
					//GetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, &client_Refk);	
					
					

					client_Refk=generare_semnal();
					GetCtrlVal (g_hmainPanel, MAINPNL_TE, &client_Te);
					epsk=client_Refk-yTr;
					
			
					yPIDk=-a1*yPIDk_1-a2*yPIDk_2+b0*epsk+b1*epsk_1+b2*epsk_2;


					
					transmisie_catre_server();
					
					
//#############################################################################		
//Bloc de program pt. Prelucrare Solutie de control automat PID
//Aici se poate prelucra raspunsul legii de reglare PID>>>>RELATIa iterativa
//@@@@@@@@ Esantionare de la Timer-Client
//############################################################################
				//Transmite comanda catre Server
			
			tk_1=tk;
			tk=tk+Te; 
			Refk_2=Refk_1;//operatie de reactualizare folosita si pentru detectarea trecerii prin "Ref0" a sinusului 
			Refk_1=client_Refk;
			
			epsk_2=epsk_1;
			epsk_1=epsk;
			
		    yPIDk_2=yPIDk_1;
			yPIDk_1=yPIDk;
			
			
			
			}
		
			break;
	}
	return 0;
}



