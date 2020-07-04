package com.atividade;

public class ArrayIns {
	private long[] a; //referência ao vetor a
	private int nElems; //número de itens de dados
	//-------------------------------------------
	public ArrayIns(int max) //Construtor
	{
		a = new long[max]; //cria o vetor
		nElems = 0; //sem itens ainda
	}
	//---------------------------------------------
	public void insert(long value) //inseere elemento no vetor
	{
		a[nElems] = value; //insere-o
		nElems++; //aumenta tamanho
	}
	//-----------------------------------------------
	public void display() //mostra o conteúdo do vetor
	{
		for(int j=0; j<nElems; j++) //para cada elemento 
			System.out.print(a[j] + " "); //mostrá-lo
		System.out.println(" ");
	}
	//------------------------------------------------
	public void selectionSort()
	{
		int in, out;
		
		for(out=1; out<nElems; out++) //out é a linha divisória
		{
			long temp = a[out]; //remove item marcado
			in = out;           //começa deslocamento em out
			while(in>0 && a[in-1] >=temp) //até que um seja menor,
			{
				a[in] = a[in-1];  //desloca item à direita
				--in; //vai uma posição à esquerda
			}
		a[in] = temp; //insere item marcado
		}
	}
}
