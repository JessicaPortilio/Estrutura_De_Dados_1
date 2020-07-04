package com.atividade;

public class ArraySh {
	private String [] theArray; //referência ao vetor theArray
	private int nElems; ///número de itens de dados
	private int comparacao =0;
	private int troca=0;
	public ArraySh(int max) { //construtor
		theArray = new String[max]; //cria o vetor
		nElems = 0; //sem itens ainda
	}
	public void insert(String value) { //coloca elementos no vetor
		theArray[nElems] = value; // insere-o
		nElems++; //incrementa tamanho
	}
	public void display() { //exibe conteúdo do vetor
		for(int j=0; j<nElems; j++) //para cada elemento,
			System.out.print(theArray[j] + " "); //exibe-o
		System.out.println("");
	}
	public void tempo() {
		System.out.println("Comparação: "+comparacao);
		System.out.println("Trocas: "+troca);
	}
	public void ShellSort() {
		int inner, outer;
		String temp;
		
		int h = 1; //determina o valor inicial de h
		while(h <= nElems/3)
			h = h*3 + 1; //(1,4,13,40,121,...), atualizando o valor de h para o tamanho do vetor
		while(h>0)	//diminuindo h, até h=1
		{
			
			for(outer=h; outer<nElems; outer++) 
			{
				temp = theArray[outer]; //pega o valor do indice
				inner = outer; //pega o indice
				while((inner > h-1) && (theArray[inner-h].compareTo(temp) >= 0)) 
				{
					troca++;
					theArray[inner] = theArray[inner-h];
					inner -= h;
					
				}
				comparacao++;
				theArray[inner] = temp;
		    
			}
		h=(h-1)/3; //diminui h
		}
	}

}
