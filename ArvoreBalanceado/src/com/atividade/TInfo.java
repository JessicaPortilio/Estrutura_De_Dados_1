package com.atividade;

public class TInfo {
	public int chave;
	String nome;

	public TInfo(int chave, String nome) {
		this.chave = chave;
		this.nome = nome;
	}

	public String toString(){ 
		return chave+"-"+nome; //return chave+" "; 
	}

	public int getChave() {
		return chave;
	}
}
