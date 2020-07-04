#include <locale>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "duplamente.h"
using namespace std;

int main()
{

    setlocale(LC_ALL, "portuguese");
    TLista Lista;
    TInfo Item;

    cria(Lista);

    char opc;
    int op;
    int pos;
    do
    {
        system("cls");
        cout << "         MENU " << endl
             << " 1 - Insere Início." << endl
             << " 2 - Insere Posição." << endl
             << " 3 - Insere Final." << endl
             << " 4 - Remove Início." << endl
             << " 5 - Remove Final." << endl
             << " 6 - Pesquisa/Remove." << endl
             << " 7 - Imprime." << endl
             << " 0 - Sair." << endl;
        cout << "Qual opção desejada: " << endl;
        cin >> op;
        switch(op)
        {
        case 1:
            setDados(Item);
            fflush(stdin);
            insereInicio(Lista, Item);
            break;
        case 2:
            setDados(Item);
            setPosicao(pos);
            fflush(stdin);
            inserePosicao(Lista, pos, Item);
            break;
        case 3:
            setDados(Item);
            insereFinal(Lista, Item);
            break;
        case 4:
            removeInicio(Lista);
            break;
        case 5:
            removeFinal(Lista);
            break;
        case 6:
            setDados(Item);
            pesquisaRemove(Lista, Item);
            break;
        case 7:
            cout << endl;
            imprime(Lista);
            imprimeContrario(Lista);
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Código invalido!" << endl;
            break;
        }
    cout << "Deseja continua (s/n)? " << endl;
    cin >> opc;
    }
    while(opc == 's' || opc == 'S');

    return 0;
}

