//######################################################################################
//#############    BUTON    Start TIMER >>>INITIALIZARE APLICATIE SERVER   #############
//######################################################################################
int CVICALLBACK Start_Aplicatie (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{   
	switch (event)
	{
		case EVENT_COMMIT:
			   //Preluare Regim de lucru si Te la Pornirea aplicatiei
				GetCtrlVal (g_hmainPanel, MAINPNL_TE, &server_Te); 
			    GetCtrlVal (g_hmainPanel, MAINPNL_AUTOMAT_MANUAL, &var_A_M); 
				//Dezactiveaza Butonul START APLICATIE
				SetCtrlAttribute (g_hmainPanel,MAINPNL_START_APLICATIE, ATTR_DIMMED,1); 
				
		Te=server_Te;
		tk_1=0;
		tk=Te;
		T=31;
		C=Te/(Te+T);
		T=37;
		C1=Te/(Te+T);
		T=1;
		C2=Te/(Te+T);
		Tr=3.7;
		Ctr1=Te/(Te+Tr);
		Tee1=2;
		Tee2=5;
		Cee1=Te/(Te+Tee1);
		Cee2=Tee1/(Te+Tee2);
			//Setare si Pornire timer esantionare Server
				SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_INTERVAL,server_Te);// Seteaza Timer 
					SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_ENABLED, 1); 
//Implementare prelucrari PROCES pe Manual
			break;
	}
	return 0;
}
