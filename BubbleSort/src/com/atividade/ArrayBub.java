package com.atividade;

public class ArrayBub {
	private String[] a; //refer�ncia ao vetor a
	private int nElems; // n�mero de intes de dados
	private int comparacao=0;
	private int trocas=0;
	public ArrayBub(int max) //construtor
	{
		a = new String[max]; //cria o vetor
		nElems = 0; //sem itens ainda
	}
	
	public void insert(String value) //insere elemento no vetor
	{
		a[nElems] = value; //insere-o
		nElems++; //aumenta tamanho
	}
	
	public void display() //mostra conte�do do vetor
	{
		for(int j=0; j<nElems; j++) { //para cada elemento,
			System.out.print(a[j] + " ");} //mostra
		System.out.println("");
		
	}
	public void tempo() {

		System.out.println("Compara��o: "+comparacao);
		System.out.println("Trocas: "+trocas);
	}
	
	public void BubbleSort()
	{
		int out, in;
		
		for(out=nElems-1; out>0; out--) //lan�o externo (para tr�s)
			for(in=0; in<out; in++,comparacao++) //lan�o interno (para frente)
				if((a[in].compareTo(a[in+1])) > 0)  //fora de ordem?
				{
					swap(in, in+1); //troc�-los
					trocas++;
				}
	}
	private void swap(int one, int two)
	{
		String temp = a[one];
		a[one] = a[two];
		a[two] = temp;
	}
	
}
