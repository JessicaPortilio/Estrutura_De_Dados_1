package com.atividade;

public class Principal {
	public static void main(String[] args) {
		int maxSize = 100; //tamanho do vetor;
		ArrayIns arr;      //referÍncia ao vetor;
		arr = new ArrayIns(maxSize); //criar o vetor
		
		arr.insert(77);
		arr.insert(99);
		arr.insert(44);
		arr.insert(55);
		arr.insert(22);
		arr.insert(88);
		arr.insert(11);
		arr.insert(00);
		arr.insert(66);
		arr.insert(33);
		
		arr.display();
		arr.selectionSort();
		arr.display();
		
	}
}
