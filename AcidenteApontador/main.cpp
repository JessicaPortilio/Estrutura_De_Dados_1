#include "funcoes.h"
#include "Manipular.h"
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
            case '1':
                setDados(item);
                insereInicio(lista, item);
                break;

            case '2':
                setDados(item);
                setPosicao(p);
                inserePosicao(lista, item, p);
                break;

            case '3':
                setDados(item);
                insereFinal(lista, item);
                break;

            case '4':
                removeInicio(lista);
                break;

            case '5':
                removeFinal(lista);
                break;

            case '6':
                setDados(item);
                pesquisaRemove(lista, item);
                break;

            case '7':
                imprime(lista);
                break;

            case '8':
                setDadosPesquisa(item);
                pesquisaAcidente(lista, item);
                break;

            default:
                break;
        }
    }

    return 0;
}
