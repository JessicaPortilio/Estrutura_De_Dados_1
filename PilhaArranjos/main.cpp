#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std
#include "Struct.h"
//--------------------------------------------------------------------------------
void setDados(TInfo& item)
{
    cout << "\nInforme o Código: ";
    cin >> item.Chave;
}
//---------------------------------------------------------------------------------
int main()
{
    setlocale(LC_ALL,"portuguese");
    TInfo item;

    TPilha P;

    Pilha(P);
    Imprime(P);


    system("cls");
    Imprime(P);
    int opc;
    char cont;
    do{
        system("cls");
    cout << "\nMenu :" << endl
         << "1 - Empilha \n"
         << "2 - Desempilha \n"
         << "3 - Imprime \n"
         << "4 - Topo \n"
         << "5 - Fim do programa \n"
         << " Opção: ";
    cin >> opc ;




        switch(opc)
        {
        case 1:
            setDados(item);
            Empilha(P, item);
            break;

        case 2:
            Desempilha(P);
            break;

        case 3:
            Imprime(P);
            break;
        case 4:
            Topo(P, item);
            break;
        case 5:
            exit(5);
        default:
            cerr << "Opção incorreta\n";
            break;
        }
        cout<< "Continuar(s/n)?";
        cin >> cont;

    }while(cont=='s'|| cont=='S');
    return 0;
}
