package arvoreBinaria;

public class TArvore {
	public TNodo T;
	public TArvore() {
		T = null;
	}
	
	public void insere(TInfo item) {
		T = insere(T,item,null); // esse metodo so serve pra chamar uma sobrecarga dele
	}
	
	public TNodo insere (TNodo T, TInfo item, TNodo pai) {
		if(T == null) // se nao tiver ninguem na arvore ainda
			T = new TNodo(item, pai); // a arvore recebe o item que foi passado por parametro
		else { // mas se nao
			pai = T; // o pai desse item vai receber o Nodo de cima 
			if(item.chave < T.item.chave) // mas precisa conferir se ele vai pra esquerda ou pra direita desse pai
				T.esq = insere(T.esq, item, pai);
			else if(item.chave > T.item.chave)
				T.dir = insere(T.dir, item, pai);
		}
		return T; // depois de finalizar tudo retorna com a arvore atualizada.
		// a função recursiva serve pra ele percorrer todos os Nodos da árvore para saber onde ele será "instalado"
	}
	
	
	
	public TNodo pesquisa(int item) {
		return pesquisa(T, item); // mais um metodo que so serve pra chamar sua sobrecarga
	}
	
	public TNodo pesquisa(TNodo T, int item) {
		if(T == null) { // se a arvore tiver vazia nao tem como retornar nada
			return T; // então retorna null ja que T = null
		} else { // mas se ja tiver alguem
			if(item == T.item.chave) // vejo se o que o usuario deseja é da mesma chave em que estou na minha árvore
				return T; // caso sim retorno o nodo da árvore.
			else
				if(item < T.item.chave) // caso nao seja igual vejo se é maior ou menor do que o que o usuario deseja pra saber
										// se vou pra direita ou pra esquerda
					T = pesquisa(T.esq, item); // caso seja chamo o metodo novamente passando um novo nodo: "T.esq" até achar o item
				else if (item > T.item.chave)
					T = pesquisa(T.dir, item);
				else // ooou.. nao encontrar o item e retornar nnull, fiz uma condicional pra isso la no principal pra dar uma msg
					 // de erro
					return null; //retornando null sei que no item digitado pelo usuario nao foi encontrado na árvore.
		}
		return T; // e retorno a árvore atualizada.
	}
	
	
	
	public TNodo Remove(TNodo T, int X) {
		if (T == null) return T; // caso nao tenha nada na arvore nao da pra remover nada, logo retornamos T que vale null
		if(X == T.item.chave) // mas, quando encontrarmos na arvore o item para ser removido executamos o seuinte: 
		{ // lembrando que a parte de ir caminhando pela arvore está nesse else correspondente. (linha 102)
			TNodo  P = T; //criamos uma variavel tipo TNodo que recebe a árvore (T)
			if((T.esq == null) && T.dir == null) { // vemos se só tem a raíz
				if(T.pai == null) // caso sim atribuimos null à T
				{
					this.T = null;
					return T;
				} else // caso não  atribuimos null ao item que esteja no Nodo da direita ou da esquerda a depender do que o usuario
					   // informou.
					if(T.item.chave > T.pai.item.chave)
						T.pai.dir = null;
					else
						T.pai.esq = null;
			}
			else // caso tenha mais item do que apenas a raíz ...
				if(T.esq == null) { // vemos se tem filhos à esquerda
					if(T.pai != null) { // se sim verificamos ainda se o pai dele é null.. sinceramente nao entendi mt bem essa parte
						      			// porque se o pai não fosse null nem estariamos nessa condição agr
						if(T.dir != null) T.dir.pai = T.pai; 
						if(T.item.chave > T.pai.item.chave)
							T.pai.dir = T.dir;
						else
							T.pai.esq = T.dir;
					} else {
						this.T = T.dir;
						this.T.pai = null;
					}
				}
				else // caso nao tenha filhos à esquerda vemos se tem filhos à direita.
					if(T.dir == null) {
						if(T.pai != null) {
							if(T.esq != null) T.esq.pai = T.pai;
							if(T.item.chave > T.pai.item.chave)
								T.pai.dir = T.esq;
							else
								T.pai.esq = T.esq;
						} else {
							this.T = T.esq;
							this.T.pai = null;
						}
					}
					else
					{
						P = getMax(T.esq);
						T.item = P.item;
					}
		}
		else // caso tenha duvida na parte do andamento na arvore me avise que eu explico.
			if(X < T.item.chave)
				Remove(T.esq,X);
			else if(X > T.item.chave)
				Remove(T.dir,X);
			else
				return null;
		return T;
	}
	
	
	
	public TNodo getMax(TNodo X) { // nao tenho certeza mas parece que aqui ta meio que balanceando a arvore, porem nenhum metodo 
								   // chama esse método getMax
		if(T.dir == null) {
			if(T.esq != null) T.esq.pai = T.pai;
			if(T.item.chave > T.pai.item.chave)
				T.pai.dir = T.esq;
			else 
				T.pai.esq = T.esq;
			return T;
		}
		else 
			return getMax(T.dir);
	}
	
	
	
	public void emOrdem(TNodo T) {
		if(T != null) {
			emOrdem(T.esq);
			System.out.println(T.item.chave + " ");
			emOrdem(T.dir);
		}
	}
	
	public void preOrdem(TNodo T) {
		if(T != null){
			System.out.println(T.item.chave + " ");
			preOrdem(T.esq);
			preOrdem(T.dir);
		}
	}
	
	public void posOrdem(TNodo T) {
		if(T != null) {
			posOrdem(T.esq);
			posOrdem(T.dir);
			System.out.println(T.item.chave + " ");
		}
	}
}