//######################################################################################
//####       In aceasta Biblioteca de functii se vor introduce Toate blocurile 
//####       din schema-bloc implementata sub forma unor functii C
//####  ...dupa modelul de mai jos   
//######################################################################################

/*double iesire_Proces_ITV()
{
	double y_Regulator;
				y_Regulator=....
				....			
	return y_Regulator;
} */

/*double iesire_Traductor_Pert()
{
	double y_Traductor;
				y_Traductor=....relatia iterativa aferenta
				....			
	return y_Traductor;
} */

//double iesire_PID()
//{
	//double local_yPIDk;
	//Implementare PID, unde: 
		//local_yPIDk este variabila locala calculata la momentul de esantionare tk
		//yPIDk_1, yPIDk_2 sunt variabile globale calculate la momentele anterioare tk_1, tk_2
		//epsk, epsk_1, epsk_2 sunt variabilele globale ale erorii, calculate la momentele anterioare tk, tk_1, tk_2
		//a1,a2,b0,b1,b2 sunt parametrii PID calculati in fct. start_aplicatie()
		//local_yPIDk=-a1*yPIDk_1-a2*yPIDk_2+b0*epsk+b1*epsk_1+b2*epsk_2

//return local_yPIDk; 
//}