package com.atividade;

public class BubbleSortApp {
	public static void main(String[] args)
	{
		int maxSize = 100; //tamanho do vetor
		ArrayBub arr; //refer�ncia ao vetor
		arr = new ArrayBub(maxSize); //criar o vetor
		
	    //inserir 10 itens
		arr.insert("I");
		arr.insert("H");
		arr.insert("G");
		arr.insert("F");
		arr.insert("E");
		arr.insert("D");
		arr.insert("C");
		arr.insert("B");
		arr.insert("A");
		
		arr.display(); //exibir itens
		
		arr.BubbleSort(); //orden�-los m�todo bolha
		
		arr.display(); //exibi-los novamente
		arr.tempo();
	}
}
