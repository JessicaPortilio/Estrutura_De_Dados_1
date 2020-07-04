# include "acidente.h"
// ---- LISTA IMPREMENTADA POR MEIO DE ARRAJO --- -
const int Tmax = 8000;
typedef int Apontador;

typedef struct
{
    TInfo Item [Tmax];
    Apontador Primeiro;
    Apontador Ultimo;
} TLista;
// ---------------------------------------------
void Cria ( TLista& Lista )
{
    Lista.Primeiro = 0;
    Lista.Ultimo = Lista.Primeiro;
}
// ---------------------------------------------
bool Vazia ( TLista Lista )
{
    return Lista.Primeiro == Lista.Ultimo ? true : false;
}
// ---------------------------------------------
bool Cheia ( TLista Lista )
{
    return Lista.Ultimo >= Tmax ? true : false;
}
// ---------------------------------------------
void InsereInicio ( TLista & Lista, TInfo Item )
{
    if ( Cheia ( Lista ))
        cout << " Erro : A lista est´a cheia " << endl;
    else
    {
        for (int aux = Lista.Ultimo; aux >= Lista.Primeiro +1; aux--)
            Lista.Item[aux] = Lista.Item [aux-1];
        Lista.Item[Lista.Primeiro] = Item;
        Lista.Ultimo++;
    }
}
// ---------------------------------------------
void InserePosicao ( TLista& Lista, int p, TInfo Item )
{
    if (( Cheia ( Lista )) || (p >= Lista.Ultimo ) )
        cout << " Erro : A lista esta cheia ou posicao nao invalida." << endl;
    else
    {
        for (int aux = Lista.Ultimo; aux >= p+1; aux--)
            Lista.Item[aux] = Lista.Item[aux-1];
        Lista.Item[p] = Item;
        Lista.Ultimo++;
    }
}
// ---------------------------------------------
void InsereFinal ( TLista& Lista, TInfo Item )
{
    if ( Cheia ( Lista ))
        cout << " Erro : A lista esta cheia " << endl ;
    else
    {
        Lista.Item[Lista.Ultimo] = Item;
        Lista.Ultimo++;
    }
}
// ---------------------------------------------
void RemoveInicio ( TLista& Lista )
{
    if ( Vazia ( Lista ))
        cout << " Erro : A lista esta vazia .\n" << endl ;
    else
    {
        for (int aux = Lista.Primeiro; aux < Lista.Ultimo-1; aux++)
            Lista.Item[aux] = Lista.Item[aux+1];
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void RemovePosicao ( TLista& Lista, int p)
{
    if (( Vazia ( Lista )) || (p >= Lista.Ultimo))
    {
        cout << " Erro : A lista esta vazia ou posicao invalida.\n" << endl ;
    }
    else
    {
        for (int aux = p; aux < Lista.Ultimo-1; aux ++)
            Lista.Item[aux] = Lista.Item[aux+1];
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void RemoveFinal ( TLista& Lista )
{
    if ( Vazia ( Lista ))
        cout << " Erro : A lista esta vazia.\n" << endl ;
    else
    {
        Lista.Ultimo--;
    }
}
// ---------------------------------------------
void PesquisaRemove ( TLista& Lista, int Item )
{
    if ( Vazia ( Lista ))
        cout << " Erro : A lista esta vazia.\n" << endl ;
    else
    {
        int aux = Lista.Primeiro;
        while (( Lista.Item[aux].Chave != Item ) && ( aux < Lista.Ultimo-1) )
            aux ++;
        if ( Lista.Item[aux].Chave == Item )
        {
            cout << " Elemento removido = " << Lista.Item[aux].Chave << endl;
            RemovePosicao ( Lista, aux );
        }
        else
            cout << " Elemento nao encontrado " << endl ;
    }
}
// ---------------------------------------------
void Imprime ( TLista Lista )
{
    cout << " Itens na LISTA : " << endl;
    if ( Vazia ( Lista ))
        cout << " Lista esta vazia." << endl;
    else
    {
        for (int aux = Lista.Primeiro; aux < Lista.Ultimo; aux++)
        {
            cout << "\n-- ----- ----- ---- ----- ----- ---- ----- ---- ----- ---" << endl;
            cout << " Codigo ........: " << Lista.Item[aux].Chave << endl;
            cout << " Municipio .....: " << Lista.Item[aux].municipio << endl;
            cout << " Rodovia .......: " << Lista.Item[aux].Rodovia << endl;
            cout << " Data ..........: " << Lista.Item[aux].Data << endl;
            cout << " Dia da Semana .: " << Lista.Item[aux].Dia_Semana << endl;
            cout << " Horario .......: " << Lista.Item[aux].Horario << endl;
            cout << " Tipo ..........: " << Lista.Item[aux].Tipo_Acidente << endl;
            cout << " No Mortos .....: " << Lista.Item[aux].Mortos << endl;
            cout << " No Feridos ....: " << Lista.Item[aux].Feridos << endl;
            cout << " Detalhes ......: " << Lista.Item[aux].Descricao << endl;
        }
        cout << endl;
    }
    cout << "\nPRIMEIRO = " << Lista.Primeiro << endl;
    cout << " ULTIMO = " << Lista.Ultimo << endl;
    cout << " TMAX = " << Tmax << endl;
}
// ---------------------------------------------
