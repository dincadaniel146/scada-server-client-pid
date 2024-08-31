//######################################################################################
//######    Functie de Formatare Pachet de date pt RX-receptie de la Client ############
//######################################################################################
int receptie_de_la_client(char receiveBuf[256],int  dataSize )
{
	if ((dataSize = ServerTCPRead (g_hconversation, receiveBuf,dataSize, 10))< 0)
          { SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, "Receive Error\n"); }
    else
    {
            	receiveBuf[dataSize] = '\0';
					ResetTextBox (g_hmainPanel, MAINPNL_RECEIVE, "");
            	SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, receiveBuf);
			//Extragere Date din pachetul receptionat
			//selectare din receivebuf>>valoare data nr 1 
				Scan (&receiveBuf[0], "%s>%f[w10]", &server_Refk);
            //selectare din receivebuf>>valoare data nr 2    	
                Scan (&receiveBuf[11], "%s>%f[w10]", &server_Te);
			
		       Scan (&receiveBuf[22], "%s>%f[w10]", &client_uk);  
				
				SetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, server_Refk);  	
				SetCtrlVal (g_hmainPanel, MAINPNL_TE, server_Te);
//#############################################################################		
//Bloc de program pt. Prelucrare PROCES pe automat
//Aici se poate prelucra raspunsul procesului>>>>RELATIILE iterative
//@@@@@@@@ Esantionare de la comunicatia pe intreruperi de la Client
//############################################################################
				//GetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, &server_Refk);
				uk=client_uk;
				
				yEE2=yEE2_1+Cee1*(uk-yEE2_1)+Cee2*(uk-uk_1);
				
				yk=yk_1+C*(yEE2-yk_1);
				yk2=yk2_1+C1*(yk-yk2_1);
				yk3=yk3_1+C2*(yk2-yk3_1);
				
				yTR1=yTR1_1+Ctr1*(yk3-yTR1_1);
		
                 PlotLine (g_hmainPanel, MAINPNL_GRAPH_2, tk_1, uk_1, tk, uk, VAL_RED);  
			     PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, server_Refk_1, tk, server_Refk, VAL_BLUE); 
				 PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, yTR1_1, tk,yTR1, VAL_GREEN); 
				 

			    transmisie_catre_client(); 
				//Elemente de schema sinoptica functie utilitara
				animatie_Bazin(yk3); 
				yk_1=yk;
				yk2_1=yk2;
				yk3_1=yk3;
				yEE2_1=yEE2;
				yTR1_1=yTR1;
				uk_1=uk;
				client_uk_1=client_uk;
				
				server_Refk_1= server_Refk;
				
			    tk_1=tk;
			    tk=tk+Te;
	}
return 0;
}
