#include "Lista_Arranjo.h"
#include "Manipula_Arquivo.h"
#include <windows.h>
#include <fstream>
int main()
{setlocale(LC_ALL, "portuguese");

    TLista l;
    TInfo item;
    int p;
    char opc;
    Cria(l);

    ifstream inAcidentes("acidentes.txt", ios::in);
    if (!inAcidentes )
    {
        cerr << " Arquivo acidentes.txt não pode ser aberto." << endl ;
        getch();
        exit(1) ;
    }

    carregaAcidentes(inAcidentes,l);
    inAcidentes.close();

    while((opc = menu(l)) != '8')
    {
        switch(opc)
        {
            case '1': //InsereInicio
                setDados(item);
                InsereInicio(l,item);
                break;
            case '2': //InserePosicao
                setDados(item);
                setPosicao(p);
                InserePosicao(l,p,item);
                break;
            case '3': //InsereFinal
                setDados(item);
                InsereFinal(l,item);
                break;
            case '4': //RemoveInicio
                RemoveInicio(l);
                break;
            case '5': //RemoveFinal
                RemoveFinal(l);
                break;
            case '6': //Pesquisa_Remove
                setDados(item);
                PesquisaRemove(l,item);
                break;
            case '7': //Imprime
                Imprime(l);
                break;
            default:
                textcolor(12);
                cerr << "\nOpção inválida\n";
                textcolor(WHITE);
                Sleep(1000);
        }
    }
    return 0;
}
