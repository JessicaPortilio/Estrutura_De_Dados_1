#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "funcoes.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");
    string res;
    int opc;
    TLista Lista;
    do{

                  system("cls");
    cout << "         MENU" << endl;
    cout << "--------------------" << endl;
    cout << "1 - Cria." << endl
         << "2 - InsereInicio." << endl
         << "3 - InserePosicao." << endl
         << "4 - InsereFinal." << endl
         << "5 - RemoveInicio." << endl
         << "6 - RemoveFinal." << endl
         << "7 - Pesquisa_Remove." << endl
         << "8 - Imprime." << endl
         << "0 - Sair." << endl;
    cout << "--------------------" << endl;
        printf("Informe sua opção: \n");
        scanf("%d", &opc);

        switch(opc){
            TInfo ultDado, priDado, item;
            int p, item7;

            case 1: cria(Lista); break;

            case 2: printf("Informe o dado que deseja inserir no início: ");
                    scanf("%d", &priDado);
                    insereInicio(Lista, priDado);
                    break;

            case 3: cout << "Informe a posição que deseja ser inserida: ";
                    cin >> p;
                    printf("Informe o dado que deseja inserir nessa posição: ");
                    scanf("%d", &item);
                    inserePosicao(Lista, p, item); break;

            case 4: printf("Informe o dado que deseja inserir no final: ");
                    scanf("%d", &ultDado);
                    insereFinal(Lista, ultDado);
                    break;

            case 5: removeInicio(Lista); break;

            case 6: removeFinal(Lista); break;

            case 7: printf("Informe o indice do vetor que deseja remover o seu respectivo dado: ");
                    scanf("%d", &item7);
                    pesquisaRemove(Lista, item7);
                    break;

            case 8: imprime(Lista); break;
            case 0: exit(0);
            default: cout << "Opção Invalida!";
        }

        cout << "Deseja escolher outra opção? (s/n): " << endl;
        cin >> res;
    }while(res == "S" || res == "s");
    return 0;
}
