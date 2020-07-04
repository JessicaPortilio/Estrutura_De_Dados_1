#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <iostream>
#include "struct.h"
using namespace std;

int main()
{
    TInfo item;
    TFila Fila;
    int op;
    char opc;
    setlocale(LC_ALL,"portuguese");
    cria(Fila);
    do
    {
        system("CLS");
        cout << "       Menu" << endl
             << " 1 - Enfileira" << endl
             << " 2 - Desenfileira" << endl
             << " 3 - Imprime" << endl
             << " 0 - Sair" << endl;
        cout << "Qual opção desejada? ";
        cin >> op;

        switch(op)
        {
        case 1:
              setDados(item);
              enQueue(Fila, item);
            break;
        case 2:
              deQueue(Fila);
            break;
        case 3:
            imprime(Fila);
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Opção invalida!" << endl;
        }
        cout << "Deseja continuar (s/n)? ";
        cin >> opc;
    }
    while(opc == 's' || opc == 'S');
    return 0;
}
