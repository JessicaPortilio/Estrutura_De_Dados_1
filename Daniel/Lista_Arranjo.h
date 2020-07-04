#ifndef LISTA_ARRANJO_H_INCLUDED
#define LISTA_ARRANJO_H_INCLUDED
#include <iostream>
#include <conio2.h>
using namespace std;

// --------------------------------------------------------------------
const int Tmax = 7000;
typedef int Apontador ;

typedef struct
{
    string Chave;
    string Municipio;
    string Rodovia;
    string Data;
    string Dia_Semana;
    string Horario;
    string Tipo_Acidente;
    string Mortos;
    string Feridos;
    string Descricao;
    int disponivel;
}TInfo;
int n_cadastrados = 0;

typedef struct
{
    TInfo Item [Tmax];
    Apontador Primeiro;
    Apontador Ultimo;
}TLista;
// --------------------------------------------------------------------
char menu ( TLista& lista );
void Cria ( TLista& Lista );
bool Vazia ( TLista Lista );
bool Cheia ( TLista Lista );
void InsereInicio ( TLista& Lista, TInfo Item );
void InserePosicao ( TLista& Lista, int p, TInfo Item );
void InsereFinal ( TLista& Lista, TInfo& Item );
void RemoveInicio ( TLista& Lista );
void RemovePosicao ( TLista& Lista, int p);
void RemoveFinal ( TLista& Lista );
void PesquisaRemove ( TLista& Lista, TInfo Item );
void Imprime ( TLista Lista );
// --------------------------------------------------------------------
char menu(TLista& lista)
{
    char opc;
    clrscr();
    Imprime(lista);

    cout << "\n Menu de escolhas\n\n"
         << " 1 - InsereInicio\n"
         << " 2 - InserePosição\n"
         << " 3 - InsereFinal\n"
         << " 4 - RemoveInicio\n"
         << " 5 - RemoveFinal\n"
         << " 6 - Pesquisa_Remove\n"
         << " 7 - Imprime\n"
         << " 8 - Finalizar\n\n"
         << " Escolha uma opção: ";
    cin >> opc;
    return toupper(opc);
}
// ---------------------------------------------
void Cria ( TLista& Lista )
{
    Lista.Primeiro = 0;
    Lista.Ultimo = Lista.Primeiro ;
}
// ---------------------------------------------
bool Vazia ( TLista Lista )
{
    return Lista.Primeiro == Lista.Ultimo ? true : false ;
}
// ---------------------------------------------
bool Cheia ( TLista Lista )
{
    return Lista.Ultimo >= Tmax ? true : false ;
}
// ---------------------------------------------
void setDados ( TInfo & item )
{
    cout << "\n Informe o Código : ";
    cin >> item.Chave ;
}
// ---------------------------------------------
void setPosicao (int& pos )
{
    cout << "\n Informe a Posição : ";
    cin >> pos ;
}
// ---------------------------------------------
void InsereInicio ( TLista & Lista, TInfo Item )
{
    if ( Cheia ( Lista ))
        cout << " Erro: A lista está cheia! " << endl ;
    else
    {
        for (int aux = Lista.Ultimo; aux >= Lista.Primeiro+1; aux--)
            Lista.Item [ aux ] = Lista.Item [ aux-1];
        Lista.Item [ Lista.Primeiro ] = Item ;
        Lista.Ultimo++;
    }
}
// ---------------------------------------------
void InserePosicao ( TLista& Lista, int p, TInfo Item )
{
    if (( Cheia ( Lista )) || (p >= Lista.Ultimo ) )
        cout << " Erro: A lista está cheia ou posição inválida. " << endl;
    else
    {
        for (int aux = Lista.Ultimo; aux >= p+1; aux--)
            Lista.Item [ aux ] = Lista.Item [aux-1];
        Lista.Item [p] = Item ;
        Lista.Ultimo++;
    }
}
// ---------------------------------------------
void InsereFinal ( TLista& Lista, TInfo& Item)
{
    if ( Cheia ( Lista ))
        cout << " Erro: A lista está cheia " << endl ;
    else
    {
        Lista.Item[Lista.Ultimo] = Item ;
        Lista.Ultimo++;
    }
}
// ---------------------------------------------
void RemoveInicio ( TLista & Lista )
{
    if ( Vazia ( Lista ))
        cout << " Erro: A lista está vazia.\n" << endl ;
    else
    {
        for (int aux = Lista . Primeiro ; aux < Lista . Ultimo -1; aux ++)
            Lista . Item [ aux ] = Lista . Item [ aux +1];
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void RemovePosicao ( TLista & Lista, int p)
{
    if (( Vazia ( Lista )) || (p >= Lista.Ultimo ) )
    {
        cout << " Erro: A lista está vazia ou posição inválida.\n" << endl ;
    }
    else
    {
        for (int aux = p; aux < Lista.Ultimo-1; aux++)
            Lista.Item [ aux ] = Lista.Item [ aux+1];
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void RemoveFinal ( TLista & Lista )
{
    if ( Vazia ( Lista ))
        cout << " Erro: A lista está vazia.\n" << endl ;
    else
    {
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void PesquisaRemove ( TLista & Lista, TInfo Item )
{
    if ( Vazia ( Lista ))
        cout << " Erro: A lista está vazia.\n" << endl ;
    else
    {
        int aux = Lista . Primeiro ;
        while (( Lista.Item[ aux ].Chave != Item.Chave ) && ( aux < Lista.Ultimo-1) )
            aux ++;
        if ( Lista.Item[ aux ].Chave == Item.Chave )
        {
            cout << " Elemento removido = " << Lista.Item[ aux ].Chave <<
                 endl ;
            RemovePosicao ( Lista, aux );
        }
        else
            cout << " Elemento não encontrado " << endl ;
    }
}
// ---------------------------------------------
void Imprime ( TLista Lista )
{
    cout << " Itens na LISTA : " << endl ;
    if ( Vazia ( Lista ))
        cout << " Lista está vazia. " << endl ;
    else
    {
        for (int aux = Lista.Primeiro; aux < Lista.Ultimo; aux++)
            cout << " " << Lista.Item[ aux ].Chave << " " ;
        cout << endl ;
    }
    cout << "\n PRIMEIRO = " << Lista.Primeiro << endl ;
    cout << " ULTIMO = " << Lista.Ultimo << endl ;
    cout << " TMAX = " << Tmax << endl ;
}
// ---------------------------------------------
#endif // LISTA_ARRANJO_H_INCLUDED
