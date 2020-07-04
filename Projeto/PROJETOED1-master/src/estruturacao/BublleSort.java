package estruturacao;

public class BublleSort
{
	//private String[] a; // referência ao vetor a
	private int nElems; // número de intes de dados
	private int comparacao = 0;
	private int trocas = 0;

	public void tempo() {

		System.out.println("Comparação: " + comparacao);
		System.out.println("Trocas: " + trocas);
	}
   
	public void BubbleSort(ListaDupEncad des) {
 
		Ligacao ult = des.getUltimo();// lanço externo (para trás) // 
		while(ult != null)
		{
			ult = ult.anterior;
			Ligacao prim = des.getPrimeiro();
			while(prim != ult) // lanço interno (para frente)
			{											
			
				if( (prim.filme.getTitulo().compareTo(prim.proximo.filme.getTitulo()) >0)) // fora de ordem?
				{
					swap(prim, prim.proximo); // trocá-los
					
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
