#include "funcoes.h"
#include "Manipular.h"
int main()
{
    setlocale(LC_ALL, "portuguese");

    TLista Lista;
    TInfo Item;
    int p;
    char opc;
    Cria(Lista);

    ifstream Entrada("acidentes.txt");
    carregaAcidentes(Entrada, Lista);
    Entrada.close();
    while((opc = menu()) != '9')
    {
        switch(opc)
        {
            case '1': //InsereInicio
                setDados(Item);
                InsereInicio(Lista,Item);
                break;
            case '2': //InserePosicao
                setDados(Item);
                setPosicao(p);
                InserePosicao(Lista,p-1,Item);
                break;
            case '3': //InsereFinal
                setDados(Item);
                InsereFinal(Lista,Item);
                break;
            case '4': //RemoveInicio
                RemoveInicio(Lista);
                break;
            case '5': //RemoveFinal
                RemoveFinal(Lista);
                break;
            case '6': //Pesquisa_Remove
                setDados(Item);
                PesquisaRemove(Lista,Item);
                break;
            case '7': //Imprime
                Imprime(Lista);
                break;
            case '8': //Pesquisar_Acidente
                pesquisaAcidentes(Lista,Item);
                break;
            default:
                cerr << "\nOpção inválida\n";

        }
    }
    ofstream Saida("acidentes.txt");
    Salvar(Saida, Lista);
    Saida.close();
    return(0);
}
