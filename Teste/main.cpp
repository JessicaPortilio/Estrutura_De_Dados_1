#include <iostream>
#include <locale>
#include <stdlib.h>
#include "Lista.h"
using namespace std;
void setDados(TInfo& item)
{
    cout << "\nInforme o Codigo: ";
    cin >> item.Chave;
}
void setPosicao(int& pos)
{
    cout << "\nInforme a Posicao: ";
    cin >> pos;
}
int main()
{

    setlocale(LC_ALL, "portuguese");
    TLista l;
    TInfo item;
    int p;
    int op;
    char opc;
    cria(l);

    do
    {
    system("cls");
    imprime(l);
    cout << endl
         << "          Menu " << endl
         << "1 - Insere no Inicío\n"
         << "2 - Insere na Posição\n"
         << "3 - Insere no Final\n"
         << "4 - Remove do Inicío\n"
         << "5 - Remove do Final\n"
         << "6 - Pesquisa e Remove\n"
         << "7 - Imprime\n"
         << "8 - Fim do programa\n";


        cout << "Qual opção desejada: ";
        cin >> op;
        switch(op)
        {

        case 1:
            setDados(item);
            InsereInicio(l, item);
            break;

        case 2:
            setDados(item);
            setPosicao(p);
            InserePosicao(l, p, item);
            break;
        case 3:
            setDados(item);
            InsereFinal(l, item);
            break;
        case 4:
            RemoveInicio(l);
            break;
        case 5:
            //  RemoveFinal(l);
            break;
        case 6:
            setDados(item);
            // PesquisaRemove(l,item);
            break;
        case 7:
            imprime(l);
            break;
        case 8:
            exit(8);
            break;
        default:
            cout << "Operação invalida!" << endl;
        }
        cout << "Deseja continuar (s/n): " << endl;
        cin >> opc;
    }
    while(opc == 's' || opc == 'S');
}
