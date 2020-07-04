#include "LISTA_APONTADOR.h"
#include "MANIPULA_ARQUIVO.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    TInfo item;
    int p;
    char opc;
    TLista lista;
    cria(lista);

    ifstream Entrada("acidentes.txt");
    carregaAcidentes(Entrada, lista);
    Entrada.close();

    while((opc = menu()) != '9')
    {
        switch(opc)
        {
            case '1': // InsereInicio
                setDados(item);
                insereInicio(lista, item);
                break;

            case '2': // InserePosição
                setDados(item);
                setPosicao(p);
                inserePosicao(lista, item, p);
                break;

            case '3': // InsereFinal
                setDados(item);
                insereFinal(lista, item);
                break;

            case '4': // RemoveInicio
                removeInicio(lista);
                break;

            case '5': // RemoveFinal
                removeFinal(lista);
                break;

            case '6': // Pesquisa_Remove
                setDados(item);
                pesquisaRemove(lista, item);
                break;

            case '7': // Imprime
                imprime(lista);
                break;

            case '8': // Pesquisar_Acidente
                setDadosPesquisa(item);
                pesquisaAcidente(lista, item);
                break;

            default:
                break;
        }
    }

    return 0;
}
