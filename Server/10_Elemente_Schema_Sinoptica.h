//Schema sinoptica animata
int animatie_Bazin()
{
			//SetCtrlVal (g_hmainPanel, MAINPNL_NUMERICTANK, server_Refk);
			SetCtrlVal (g_hmainPanel, MAINPNL_NUMERICTANK, yk); 
			if(server_Refk<20)
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 1);
			}
			if((server_Refk>=20)&&(server_Refk<40))
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 1); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
			if((server_Refk>=40)&&(server_Refk<60))
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 1); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
			if((server_Refk>=60)&&(server_Refk<80))
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 1); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
			if(server_Refk>=80)
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 1);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
return 0;
}
