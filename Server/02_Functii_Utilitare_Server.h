//######################################################################################
//#############    Functie de activare Regim de Lucru Automat / Manuaal    ############
//######################################################################################
int CVICALLBACK comutarea_Automat_Manual (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 GetCtrlVal (g_hmainPanel, MAINPNL_AUTOMAT_MANUAL, &var_A_M);
			 if (var_A_M==0)
			 {//Tratare Regim Automat
			 	//Se Dezctiveaza Potentiometru REFERINTA si Te
				SetCtrlAttribute (g_hmainPanel,MAINPNL_REFERINTA, ATTR_DIMMED,1); 
				SetCtrlAttribute (g_hmainPanel,MAINPNL_TE, ATTR_DIMMED,1);
				//Oprire Timer Server 
					SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_ENABLED, 0); 
					transmisie_catre_client();    
			 }
			 else
			 { //Tratare Regim Manual 
			 	//Se activeaza Potentiometru REFERINTA si Te
				SetCtrlAttribute (g_hmainPanel,MAINPNL_REFERINTA, ATTR_DIMMED,0); 
				SetCtrlAttribute (g_hmainPanel,MAINPNL_TE, ATTR_DIMMED,0);
				//Pornire Timer Server 
					SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_INTERVAL,server_Te);// Seteaza Timer 
					SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_ENABLED, 1); 
					transmisie_catre_client(); 
			 }
			 
			break;
	}
	return 0;
}
//######################################################################################
//#############    Functie stergerea casetei de mesaje primite de la Client ############
//######################################################################################
int CVICALLBACK ClearScreenCB (int panel, int control, int event,
							   void *callbackData, int eventData1,
							   int eventData2)
{
	if (event == EVENT_COMMIT)
		ResetTextBox (panel, MAINPNL_RECEIVE, "");
	return 0;
}


//######################################################################################
//#############    Functie de tratare mesaj EROARE la pornire Server      ##############
//######################################################################################
static void ReportTCPError (void)
{
	if (g_TCPError < 0)
		{
		char	messageBuffer[1024];
		sprintf(messageBuffer, 
			"TCP library error message: %s\nSystem error message: %s", 
			GetTCPErrorString (g_TCPError), GetTCPSystemErrorString());
		MessagePopup ("Error", messageBuffer);
		}
}
//######################################################################################
//#############    Functie de oprire Server din Butonul Stop      ##############
//######################################################################################
int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
//######################################################################################
//#############    Functie de oprire Server din Fereastra Windows     ##############
//######################################################################################
int CVICALLBACK MainPanelCB (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface (0);
	return 0;
}

//Refresh Grafice

int CVICALLBACK refresh_Graph (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{   case EVENT_COMMIT:
			DeleteGraphPlot (g_hmainPanel, MAINPNL_GRAPH, -1, VAL_IMMEDIATE_DRAW); 
			tk_1=0;
			tk=0;
			break;
	}
	return 0;
}