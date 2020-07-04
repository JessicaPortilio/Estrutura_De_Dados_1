package arvoreBinaria;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		TArvore T1 = new TArvore(); //cria a √°rvore
		TInfo item = new TInfo(49,"Al√≠cia"); //cria um novo objeto com essa chave e nome, fun√ß√£o chamada na classe TInfo.
		T1.insere(item); //essa chamada vai pra classe TArvore.
		item.chave = 20; item.nome = "Alan"; //ja tem uma instancia√ß√£o para TInfo item, agr s√≥ sobrescrever para adicionar um novo item
		T1.insere(item);
		item.chave = 50; item.nome = "Liliane";
		T1.insere(item);
		
		String opc;
		
		do {
		TNodo tn = T1.T; // tn recebe a ra√≠z 
		Scanner input = new Scanner(System.in);
		int num, opcMenu;
		
		// MENU
		System.out.println("1. Inserir");
		System.out.println("2. Pesquisar");
		System.out.println("3. Remover");
		System.out.println("4. Em Ordem");
		System.out.println("5. PrÈ Ordem");
		System.out.println("6. PÛs Ordem");
		System.out.print("Informe sua opÁ„o: ");
		opcMenu = input.nextInt();
		
		switch(opcMenu) {
		case 1:
			System.out.print("Informe o nome: ");
			String nome = input.nextLine();
			input.nextLine();
			System.out.print("Informe a chave: ");
			int chave = input.nextInt();
			item.chave = chave; item.nome = nome;
			T1.insere(item);
			System.out.println("Item inserido com sucesso!");
			break;
			
		case 2:
			System.out.print("Informe o item: ");
			num = input.nextInt();

			tn = T1.pesquisa(num);
			if(tn == null)
				System.out.println("Item n√£o encontrado.");
			else {
				System.out.println("Impress√£o na principal");
				System.out.println("chave: " + tn.item.chave);
				System.out.println("nome.: " + tn.item.nome);
			}
			break;
			
		case 3:
			System.out.print("Informe a chave a ser removida: ");
			int numCase3 = input.nextInt();
			T1.Remove(tn, numCase3);
			if(tn == null)
				System.out.println("Chave inexistente!");
			else
				System.out.println("Chave removida com sucesso!");
			break;
			
		case 4:
			System.out.println("Em Ordem: ");
			T1.emOrdem(tn);
			break;
			
		case 5:
			T1.preOrdem(tn);
			break;
			
		case 6:
			T1.posOrdem(tn);
			break;
			
		default:
			System.out.println("OpÁ„o invalida.");
		}
		
		
		System.out.println("De novo? (s/n): ");
		opc = input.next();
		
		} while(opc.equals("s"));
	}
}
