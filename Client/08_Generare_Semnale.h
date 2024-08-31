//#############################################################################
//@@@	Generare semnale trapta, rampa, sinusoida 
// Aceste semnale continue vor fi considerante in aplicatiile viitoare ca fiind
//semnalul de Referinta pt. Bucla de reglare. Astfel, acestea trebuie sa comute 
//intr-o forma continua (fara socuri) de pe un tip pe altul...
//Va rog ca eventuale BUG-uri gasite sa le semnalati si poate...chiar sa le rezolvati
//############################################################################# 
double generare_semnal()
{
	double local_Refk;// local_Refk_1,local_Refk_2;
		double local_m, local_n;
		
		local_Refk=0;
	switch (sel_ref)
	{
		case 0: 	//generare Semnal Treapta
			//Se afizeaza controoalele grafice pentru selectie Treapta 
			SetCtrlAttribute (g_hmainPanel,MAINPNL_REFERINTA, ATTR_VISIBLE,1); 
				//Se ascund controalele grafice pentru selectie Rampa, Sinus 
				SetCtrlAttribute (g_hmainPanel,MAINPNL_M_PANTA, ATTR_VISIBLE,0);  
					SetCtrlAttribute (g_hmainPanel,MAINPNL_A_SINUS, ATTR_VISIBLE,0);  
					SetCtrlAttribute (g_hmainPanel,MAINPNL_T_SINUS, ATTR_VISIBLE,0);
			//Se citeste valoarea Treptei la momentul actual tk;
			GetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, &local_Refk);  
			break;
			
		case 1:  	//generare Semnal Rampa
			//Se afizeaza/ascund controoalele grafice pentru selectia curenta 
			SetCtrlAttribute (g_hmainPanel,MAINPNL_REFERINTA, ATTR_VISIBLE,0); 
				SetCtrlAttribute (g_hmainPanel,MAINPNL_M_PANTA, ATTR_VISIBLE,1);
					SetCtrlAttribute (g_hmainPanel,MAINPNL_A_SINUS, ATTR_VISIBLE,0);  
					SetCtrlAttribute (g_hmainPanel,MAINPNL_T_SINUS, ATTR_VISIBLE,0);
			//Se citeste valoarea pantei (tangenta) la momentul actual tk;    		
			GetCtrlVal (g_hmainPanel, MAINPNL_M_PANTA, &local_m);
			  local_n=Refk0;
			  local_Refk=local_m*timp_rampa_tk+local_n;
			  	timp_rampa_tk=timp_rampa_tk+client_Te;
			  
			break;
			
		case 2:  //generare Semnal Sinusoidal
			  SetCtrlAttribute (g_hmainPanel,MAINPNL_REFERINTA, ATTR_VISIBLE,0); 
				SetCtrlAttribute (g_hmainPanel,MAINPNL_M_PANTA, ATTR_VISIBLE,0);
					SetCtrlAttribute (g_hmainPanel,MAINPNL_A_SINUS, ATTR_VISIBLE,1);  
					SetCtrlAttribute (g_hmainPanel,MAINPNL_T_SINUS, ATTR_VISIBLE,1);
			if (comutare_Sin==0)
				{
					GetCtrlVal (g_hmainPanel, MAINPNL_A_SINUS, &A_sin);
					GetCtrlVal (g_hmainPanel, MAINPNL_T_SINUS, &T_sin);
				}
			else
				{ 	//se detecteaza trecerea prin Refk0 a sinusului pentru a permite comutarea
					//fara socuri SIN->SIN
					if( (Refk_2<Refk0)&&(Refk_1>=Refk0) ) //comutarea de jos in sus
					{	comutare_Sin=0;
						timp_sinus_tk=2*client_Te;
					}
					if( (Refk_2>Refk0)&&(Refk_1<=Refk0) )  //comutarea de sus in jos
					{	comutare_Sin=0;
						timp_sinus_tk=2*client_Te+T_sin/2;
					}
				}
			//formula de calcul pentru SIN  
			local_Refk=A_sin*sin(((2*Pi())/T_sin)*timp_sinus_tk)+Refk0;
			timp_sinus_tk=timp_sinus_tk+client_Te;
					
			break;
		default:
			break;
	}
	return local_Refk;
}
//#############################################################################
//@@@	Selectie TIP semnal: trapta, rampa, sinusoida  (pe intrerupere) 
//############################################################################# 
int CVICALLBACK selectie_semnal (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 GetCtrlVal (g_hmainPanel, MAINPNL_SEL_REF, &sel_ref);   ///// 
			 switch (sel_ref)
			 {
				 case 0:
			 		 //treapta
					 
					 break;
				 case 1:
					 //initializari la comutare rampa
			 		  	timp_rampa_tk=0;
			 	 		Refk0=client_Refk;
					 break;
				 case 2:
			 		 //sinusoida
					 timp_sinus_tk=0;
					 Refk0=client_Refk; 
					 break;
					 
				 default:
			 
					 break;
			 }
			 
			break;
	}
	return 0;
}
//#############################################################################
//@@@	Modificare panta rampa  (pe intrerupere) 
//############################################################################# 
int CVICALLBACK modificare_Panta (int panel, int control, int event,
								  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			timp_rampa_tk=0;
			Refk0=client_Refk;
			break;
	}
	return 0;
}
//#############################################################################
//@@@	Detectare moment de comutare SIN->SIN  (pe intrerupere) 
//############################################################################# 
int CVICALLBACK detectare_comutare_SIN (int panel, int control, int event,
										void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			comutare_Sin=1;
			break;
	}
	return 0;
}