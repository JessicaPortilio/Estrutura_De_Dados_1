package com.atividade;

public class Principal {
	public static void main (String[] args) 
	{ 
		TArvore T1 = new TArvore();
	System.out.print("======VETOR======\n"); 
	int dados[] = {10,20,30,40,50,60}; 
	for (int i=0;i<6;i++) 
	{ 
		System.out.print(dados[i]+" "); 
	}
	System.out.print("\n\n======== INSER��O SEQUENCIAL ========\n"); 
	T1.inserirSEQ(dados , 0, 5); 
	T1.mostraArvore();
	System.out.print("\n\n======== INSER��O BIN�RIA ========\n");
	T1.T = null; T1.inserirBIN(dados , 0, 5); 
	T1.mostraArvore(); 
	} 
}
