package com.atividade;

public class NodaArvore {
	public class Tarvor {
		public TNodo T;

	public void Tarvore() {
		T = null;
	  }
	}

	public class TNodo {
		TNodo esq;
		TInfo item;
		TNodo dir;
		TNodo pai;

		public TNodo(TInfo item, TNodo pai) {
			this.item = new TInfo(item.chave, item.nome);
			this.esq = null;
			this.dir = null;
			this.pai = pai;
		}
	}

	public class TInfo {
		public int chave;
		String nome;

		public TInfo(int chave, String nome) {
			this.chave = chave;
			this.nome = nome;
		}
	}
}
