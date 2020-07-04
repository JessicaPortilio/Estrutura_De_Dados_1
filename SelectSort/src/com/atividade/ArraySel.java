package com.atividade;

public class ArraySel {
	private long [] a;    //referência ao vetor a
	private int nElems;   //número de itens de dados
	private int comparacao =0;
	private int trocas =0;
	//---------------------------------
	public ArraySel(int max)   //construtor
	{
		a = new long[max]; //cria o vetor
		nElems = 0;  //sem itens ainda
	}
	//---------------------------------
	public void insert(long value)  //insere elemento no vetor
	{
		a[nElems] = value; //insere-o
		nElems++;  //aumenta o tamanho
	}
	//------------------------------------
	public void display() //mostra o conteúdo do vetor
	{
		for(int j=0; j<nElems; j++)  //para cada elemento
			System.out.print(a[j] + " "); //mostrá-lo
		System.out.println("");
	
	}
	//------------------------------------
	public void selectionSort()
	{
		int out, in, min;
		for(out = 0; out<nElems-1; out++) //laço externo
		{
			min = out; //mínimo
			for(in=out+1; in<nElems; in++) { //laço interno
				comparacao++;
				if(a[in] < a[min]) //se min for maior
					
					min=in;  //temos um novo min
			}
				swap(out, min); //trocá-los	
		
		}
	}
	//--------------------------------------
	public void swap(int one, int two)
	{
		long temp = a[one];
		a[one] = a[two];
		a[two] = temp;
		System.out.println("Metodo swap: trocando " + a[one] + "com " + a[two]);
		trocas++;
		
	}
	public void contador()
	{
		System.out.println("Comparação: "+comparacao);
		System.out.println("Trocas: "+trocas);
	}
}
