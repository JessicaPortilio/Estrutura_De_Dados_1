package com.atividade;

public class ArrayIns {
	private long[] a; //refer�ncia ao vetor a
	private int nElems; //n�mero de itens de dados
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
	public void display() //mostra o conte�do do vetor
	{
		for(int j=0; j<nElems; j++) //para cada elemento 
			System.out.print(a[j] + " "); //mostr�-lo
		System.out.println(" ");
	}
	//------------------------------------------------
	public void selectionSort()
	{
		int in, out;
		
		for(out=1; out<nElems; out++) //out � a linha divis�ria
		{
			long temp = a[out]; //remove item marcado
			in = out;           //come�a deslocamento em out
			while(in>0 && a[in-1] >=temp) //at� que um seja menor,
			{
				a[in] = a[in-1];  //desloca item � direita
				--in; //vai uma posi��o � esquerda
			}
		a[in] = temp; //insere item marcado
		}
	}
}
