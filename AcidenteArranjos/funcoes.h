#include <iostream>
#include <conio2.h>
#include <windows.h>
#include <fstream>
using namespace std;

// --------------------------------------------------------------------
const int Tmax = 10;

typedef struct
{
    string Codigo;
    string Cidade;
    string Rodovia;
    string Data;
    string Dia;
    string Hora;
    string TipoDeAcidente;
    string QuantMortos;
    string QuantFeridos;
    string Descricao;

}TInfo;

typedef struct
{
    TInfo Item[Tmax];
    int Primeiro;
    int Ultimo;

}TLista;
// --------------------------------------------------------------------
char menu ();
void Cria ( TLista& Lista );
bool Vazia ( TLista& Lista );
bool Cheia ( TLista& Lista );
void setDados ( TInfo & item );
void setPosicao (int& pos );
void InsereInicio ( TLista& Lista, TInfo Item );
void InserePosicao ( TLista& Lista, int p, TInfo Item );
void InsereFinal ( TLista& Lista, TInfo Item );
void RemoveInicio ( TLista& Lista );
void RemovePosicao ( TLista& Lista, int p);
void RemoveFinal ( TLista& Lista );
void PesquisaRemove ( TLista& Lista, TInfo Item );
void Imprime ( TLista& Lista );
void carregaAcidentes ( ifstream &Entrada, TLista& lista );
void Salvar(ofstream &Saida, TLista& Lista);
// --------------------------------------------------------------------
char menu()
{
    char opc;
    system("CLS");
    cout << "\n        Menu\n\n"
         << " 1 - InsereInicio\n"
         << " 2 - InserePosição\n"
         << " 3 - InsereFinal\n"
         << " 4 - RemoveInicio\n"
         << " 5 - RemoveFinal\n"
         << " 6 - Pesquisa/Remove\n"
         << " 7 - Imprime\n"
         << " 8 - Pesquisar\n"
         << " 9 - Finalizar\n\n"
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
bool Vazia ( TLista& Lista )
{
    return Lista.Primeiro == Lista.Ultimo ? true : false ;
}
// ---------------------------------------------
bool Cheia ( TLista& Lista )
{
    return Lista.Ultimo >= Tmax ? true : false ;
}
// ---------------------------------------------
void setDados ( TInfo & item )
{
    cout << "\n Informe sobre o acidente: \n";
    fflush(stdin);

    cout << " Código: ";
    getline(cin, item.Codigo) ;

    cout << " Cidade: ";
    getline(cin, item.Cidade);

    cout << " Rodovia: ";
    getline(cin, item.Rodovia);

    cout << " Data:  ";
    getline(cin, item.Data);

    cout << " Dia: ";
    getline(cin, item.Dia);

    cout << " Hora: ";
    getline(cin, item.Hora);

    cout << " Tipo: ";
    getline(cin, item.TipoDeAcidente);

    cout << " Mortos: ";
    getline(cin, item.QuantMortos);

    cout << " Feridos: ";
    getline(cin, item.QuantFeridos);

    cout << " Descrição: ";
    getline(cin, item.Descricao);
}
// ---------------------------------------------
void setPosicao (int& pos )
{
    cout << "\n Informe a Posição: ";
    cin >> pos;
}
// ---------------------------------------------
void InsereInicio ( TLista & Lista, TInfo Item )
{
    if (Cheia( Lista))
    {
        cout << " Erro: A lista está cheia! " << endl ;
        system("pause");
    }
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
    {
        cout << " Erro: A lista está cheia ou posição inválida. " << endl;
        system("pause");
    }
    else
    {
        for (int aux = Lista.Ultimo; aux >= p+1; aux--)
            Lista.Item [ aux ] = Lista.Item [aux-1];
            Lista.Item [p] = Item ;
            Lista.Ultimo++;
    }
}
// ---------------------------------------------
void InsereFinal ( TLista& Lista, TInfo Item)
{
    if ( Cheia ( Lista ))
    {
        cout << " Erro: A lista está cheia!" << endl ;
        system("pause");
    }
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
    {
        cout << " Erro: A lista está vazia.\n" << endl ;
        system("pause");
    }
    else
    {
        for (int aux = Lista.Primeiro; aux < Lista.Ultimo-1; aux++)
            Lista.Item[aux] = Lista.Item[aux+1];

        cout << " Elemento removido " << endl << endl;
        cout << " Código: " << Lista.Item[Lista.Primeiro].Codigo << endl ;
        cout << " Cidade: " << Lista.Item[Lista.Primeiro].Cidade << endl ;
        cout << " Rodovia: " << Lista.Item[Lista.Primeiro].Rodovia << endl ;
        cout << " Data:  " << Lista.Item[Lista.Primeiro].Data << endl ;
        cout << " Dia: " << Lista.Item[Lista.Primeiro].Dia << endl ;
        cout << " Hora: " << Lista.Item[Lista.Primeiro].Hora << endl ;
        cout << " Tipo: " << Lista.Item[Lista.Primeiro].TipoDeAcidente << endl ;
        cout << " Mortos: " << Lista.Item[Lista.Primeiro].QuantMortos << endl ;
        cout << " Feridos: " << Lista.Item[Lista.Primeiro].QuantFeridos << endl ;
        cout << " Descrição: " << Lista.Item[Lista.Primeiro].Descricao << endl ;
        system("pause");
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void RemovePosicao ( TLista & Lista, int p)
{
    if (( Vazia ( Lista )) || (p >= Lista.Ultimo ) )
    {
        cout << " Erro: A lista está vazia ou posição inválida.\n" << endl ;
        system("pause");
    }
    else
    {
        for (int aux = p; aux < Lista.Ultimo-1; aux++)
            Lista.Item [aux] = Lista.Item [aux+1];
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void RemoveFinal ( TLista & Lista )
{
    if ( Vazia ( Lista ))
    {
        cout << " Erro: A lista está vazia.\n" << endl ;
        system("pause");
    }
    else
    {
        cout << " Elemento removido " << endl << endl;
        cout << " Código: " << Lista.Item[Lista.Ultimo].Codigo << endl ;
        cout << " Cidade: " << Lista.Item[Lista.Ultimo].Cidade << endl ;
        cout << " Rodovia: " << Lista.Item[Lista.Ultimo].Rodovia << endl ;
        cout << " Data:  " << Lista.Item[Lista.Ultimo].Data << endl ;
        cout << " Dia: " << Lista.Item[Lista.Ultimo].Dia << endl ;
        cout << " Hora: " << Lista.Item[Lista.Ultimo].Hora << endl ;
        cout << " Tipo: " << Lista.Item[Lista.Ultimo].TipoDeAcidente << endl ;
        cout << " Mortos: " << Lista.Item[Lista.Ultimo].QuantMortos << endl ;
        cout << " Feridos: " << Lista.Item[Lista.Ultimo].QuantFeridos << endl ;
        cout << " Descrição: " << Lista.Item[Lista.Ultimo].Descricao << endl ;
        system("pause");
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void PesquisaRemove ( TLista & Lista, TInfo Item )
{
    if ( Vazia ( Lista ))
    {
        cout << " Erro: A lista está vazia.\n" << endl ;
         system("pause");
    }
    else
    {
        int aux = Lista . Primeiro ;
        while (( Lista.Item[aux].Codigo != Item.Codigo ) && ( aux < Lista.Ultimo-1) )
            aux ++;
        if ( Lista.Item[aux].Codigo == Item.Codigo )
        {
            cout << " Elemento removido " << endl << endl;
            cout << " Código: " << Lista.Item[aux].Codigo << endl ;
            cout << " Cidade: " << Lista.Item[aux].Cidade << endl ;
            cout << " Rodovia: " << Lista.Item[aux].Rodovia << endl ;
            cout << " Data:  " << Lista.Item[aux].Data << endl ;
            cout << " Dia: " << Lista.Item[aux].Dia << endl ;
            cout << " Hora: " << Lista.Item[aux].Hora << endl ;
            cout << " Tipo: " << Lista.Item[aux].TipoDeAcidente << endl ;
            cout << " Mortos: " << Lista.Item[aux].QuantMortos << endl ;
            cout << " Feridos: " << Lista.Item[aux].QuantFeridos << endl ;
            cout << " Descrição: " << Lista.Item[aux].Descricao << endl ;
            system("pause");
            RemovePosicao ( Lista, aux );
        }
        else
            cout << " Elemento não encontrado!" << endl ;
    }
}
// ---------------------------------------------
void Imprime ( TLista& Lista )
{
    cout << " Itens na LISTA : \n" << endl ;
    if ( Vazia ( Lista ))
    {
        cout << " Lista está vazia. " << endl ;
        system("pause");
    }
    else
    {
        for (int i = Lista.Primeiro; i < Lista.Ultimo; i++)
        {
            cout << " Código: " << Lista.Item[i].Codigo << endl ;
            cout << " Cidade: " << Lista.Item[i].Cidade << endl ;
            cout << " Rodovia: " << Lista.Item[i].Rodovia << endl ;
            cout << " Data:  " << Lista.Item[i].Data << endl ;
            cout << " Dia: " << Lista.Item[i].Dia << endl ;
            cout << " Hora: " << Lista.Item[i].Hora << endl ;
            cout << " Tipo: " << Lista.Item[i].TipoDeAcidente << endl ;
            cout << " Mortos: " << Lista.Item[i].QuantMortos << endl ;
            cout << " Feridos: " << Lista.Item[i].QuantFeridos << endl ;
            cout << " Descrição: " << Lista.Item[i].Descricao << endl ;
             system("pause");
            cout << endl << endl;
        }
    }
    cout << "\n PRIMEIRO = " << Lista.Primeiro << endl ;
    cout << " ULTIMO = " << Lista.Ultimo << endl ;
    cout << " TMAX = " << Tmax << endl ;
}
// -------------------------------------------------
