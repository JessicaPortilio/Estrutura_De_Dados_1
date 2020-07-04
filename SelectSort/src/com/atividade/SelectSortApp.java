package com.atividade;

public class SelectSortApp {
	public static void main(String[] args)
	{
		int maxSize = 100; //tamnho do vetor
		ArraySel arr;	   //referência ao vetor
		arr = new ArraySel(maxSize); //criar o vetor
		
		arr.insert(11);
		arr.insert(9);
		arr.insert(7);
		arr.insert(5);
		arr.insert(3);
		arr.insert(1);
		
		arr.display();
		arr.selectionSort();
		arr.display();
		arr.contador();
	}
}
