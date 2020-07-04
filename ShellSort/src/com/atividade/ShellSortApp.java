package com.atividade;

public class ShellSortApp {
	public static void main(String[] args)
	{
		int maxSize = 10; //tamanho do vetor
		ArraySh arr;
		arr = new ArraySh(maxSize); //cria o vetor
		
		arr.insert("J");
		arr.insert("I");
		arr.insert("H");
		arr.insert("G");
		arr.insert("F");
		arr.insert("E");
		arr.insert("D");
		arr.insert("C");
		arr.insert("B");
		arr.insert("A");
		
		arr.display(); //exibir vetor não ordenado
		arr.ShellSort(); //ordenação Shell do vetor
		arr.display(); //exibir vetor ordenado
		arr.tempo();
		
		
	}
}
