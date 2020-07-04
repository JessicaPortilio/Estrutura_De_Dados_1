package estruturacao;

public class BublleSort
{
	//private String[] a; // refer�ncia ao vetor a
	private int nElems; // n�mero de intes de dados
	private int comparacao = 0;
	private int trocas = 0;

	public void tempo() {

		System.out.println("Compara��o: " + comparacao);
		System.out.println("Trocas: " + trocas);
	}
   
	public void BubbleSort(ListaDupEncad des) {
 
		Ligacao ult = des.getUltimo();// lan�o externo (para tr�s) // 
		while(ult != null)
		{
			ult = ult.anterior;
			Ligacao prim = des.getPrimeiro();
			while(prim != ult) // lan�o interno (para frente)
			{											
			
				if( (prim.filme.getTitulo().compareTo(prim.proximo.filme.getTitulo()) >0)) // fora de ordem?
				{
					swap(prim, prim.proximo); // troc�-los
					
				}
				prim=prim.proximo;
			}
			
		}
	}

	private void swap(Ligacao one, Ligacao two) {
		Ligacao temp = one;
		/*temp.anterior.proximo = temp.proximo;
		temp.proximo.proximo = temp;
		temp.proximo.anterior = temp.anterior;
		temp.proximo = temp.proximo.proximo;
		temp.anterior =  temp.proximo;*/
		one = two;
		two = temp;
	}

}
