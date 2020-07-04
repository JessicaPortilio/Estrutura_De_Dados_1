package estruturacao;

import filmes.Filmes;

public class ListaDupEncad
{
	private Ligacao primeiro;
	private Ligacao ultimo;
	private int totalFilmes = 0;

	public ListaDupEncad()
	{
		primeiro = null;
		ultimo = null;
	}
	
	public Ligacao getPrimeiro()
	{
		return this.primeiro;
	}
	
	public Ligacao getUltimo()
	{
		return this.ultimo;
	}
	
	public void setPrimeiro(Ligacao primeiro)
	{
		this.primeiro = primeiro;
	}
	
	public void setUltimo(Ligacao ultimo)
	{
		this.ultimo = ultimo;
	}

	public boolean vazia()
	{
		return primeiro == null;
	}

	public void insereInicio(Filmes chave)
	{
		Ligacao novaLigacao = new Ligacao(chave);

		if (vazia())
			ultimo = novaLigacao;
		else
			primeiro.anterior = novaLigacao;
		novaLigacao.proximo = primeiro;
		primeiro = novaLigacao;
	}

	public void insereFinal(Filmes chave)
	{
		Ligacao novaLigacao = new Ligacao(chave);
		if (vazia())
		{
			primeiro = novaLigacao;
		} else
		{
			ultimo.proximo = novaLigacao;
			novaLigacao.anterior = ultimo;
		}
		ultimo = novaLigacao;
	}

	public Ligacao removeInicio()
	{
		Ligacao temp = primeiro;
		if (primeiro.proximo == null)
			ultimo = null;
		else
			primeiro.proximo.anterior = null;
		primeiro = primeiro.proximo;
		return temp;
	}

	public Ligacao removeFinal()
	{
		Ligacao temp = ultimo;
		if (primeiro.proximo == null)
			primeiro = null;
		else
			ultimo.anterior.proximo = null;
		ultimo = ultimo.anterior;
		return temp;

	}

	public boolean inserePosicao(Filmes chave, Filmes dd)
	{
		Ligacao atual = primeiro;
		while (atual.filme != chave)
		{
			atual = atual.proximo;
			if (atual == null)
				return false;
		}
		Ligacao newLigacao = new Ligacao(dd);
		if (atual == ultimo)
		{
			newLigacao.proximo = null;
			ultimo = newLigacao;
		} else
		{
			newLigacao.proximo = null;
			atual.proximo.anterior = newLigacao;
		}
		newLigacao.anterior = atual;
		atual.proximo = newLigacao;
		return true;
	}

	public void pesquisaS(String chave)
	{
		Ligacao atual = primeiro;
		while (atual != null)
		{
			if (atual.filme.getTitulo().equals(chave)) {
				System.out.println(atual.filme.getIdFilme());
				imprimir(atual.filme);
			}
			atual = atual.proximo;
		}
	}
	
	public void pesquisaB(String chave, Ligacao auxBolha[]) {
		int meio, inicio = 0, fim = auxBolha.length-1;
		
		
		while(inicio <= fim) {
			System.out.println("Entrei no whiel");
			meio = (inicio + fim)/2;
			//if(auxBolha[meio].filme.getTitulo().compareTo(chave)==0)
			if(auxBolha[meio].filme.getTitulo().contains(chave)){
				imprimir(auxBolha[meio].filme);
				inicio = fim + 1;
			}
			else if(auxBolha[meio].filme.getTitulo().compareTo(chave) < 0) {
				inicio = meio + 1;
			}
			else if(auxBolha[meio].filme.getTitulo().compareTo(chave) > 0){
				fim = meio - 1;
			}
		}
	}
	
	public void imprimir(Filmes filme){
		System.out.println("Nome.............: " + filme.getTitulo());
		System.out.println("Data Lançamento..: " + filme.getDataLancamento());
		System.out.println("Tempo de Execução: " + filme.getTempoFilme());
		System.out.println("Sinopse..........: " + filme.getSinopse());
	}

	public void imprimeContrario()
	{ // imprime de tras pra frente
		System.out.print("List (ultimo->primeiro): ");
		Ligacao atual = ultimo;
		while (atual != null)
		{
			atual.linkExibicao();
			atual = atual.anterior;
		}
		System.out.println("");
	}

	public void imprimeOrdem()
	{ // imprime do primeiro ao ultimo
		System.out.print("List (primeiro->ultimo): \n");
		int i = 1;
		Ligacao atual = primeiro;
		while (i < getTotalFilmes())
		{
			System.out.print(i + " - ");
			atual.linkExibicao();
			atual = atual.proximo;
			i++;
		}
	}

	public int getTotalFilmes()
	{
		return totalFilmes;
	}

	public void setTotalFilmes(int totalFilmes)
	{
		this.totalFilmes = totalFilmes;
	}
}
