#include <iostream>
using namespace std;
const int Tmax = 10;
typedef int Apontador;
typedef struct
{
    int Chave;
    /*outros componentes*/
} TInfo;
typedef struct
{
    TInfo Item[Tmax];
    Apontador Primeiro;
    Apontador Ultimo;
    int Total;
} TFila;
//------------------------------------------------------------------------
bool QisFull(TFila& Fila)
{
    return Fila.Total==Tmax?true:false;
}
//------------------------------------------------------------------------
bool QisEmpty(TFila& Fila)
{
    return Fila.Total==0?true:false;
}
//------------------------------------------------------------------------
void setDados(TInfo& Item)
{
    cout << "\nInforme o Código: ";
    cin >> Item.Chave;
}
//------------------------------------------------------------------------
void cria(TFila& Fila)
{
    Fila.Primeiro = 0;
    Fila.Ultimo = 0;
    Fila.Total = 0;
}
//------------------------------------------------------------------------
void adc (int& pos)
{
    pos++;
    if (pos>=Tmax)
        pos = 0;
}
//------------------------------------------------------------------------
void enQueue (TFila& Fila, TInfo Item)
{
    if (QisFull(Fila))
        cout << "Erro: A Fila está cheia" << endl;
    else
    {
        Fila.Item[Fila.Ultimo]=Item;
        adc(Fila.Ultimo);
        Fila.Total++;
    }
}
//------------------------------------------------------------------------
void deQueue (TFila& Fila)
{
    if (QisEmpty(Fila))
        cout << "Erro : A Fila está vazia.\n" << endl;
    else
    {
        adc(Fila.Primeiro);
        Fila.Total--;
    }
}
//------------------------------------------------------------------------

void imprime(TFila Fila)
{
    if (QisEmpty(Fila))
        cout << "Erro : A Fila está vazia.\n" << endl;
    else
    {
        int ax=0;
        while(ax<Fila.Total)
        {
            ax++;
            int p=Fila.Primeiro;
            adc(p);
        }
        cout << endl;
    }
    cout << "\nPRIMEIRO = " << Fila.Primeiro << endl;
    cout << "ULTIMO = " << Fila.Ultimo << endl;
    cout << "TOTAL = " << Fila.Total << endl;
    int i=0;
    while(i < Fila.Total)
    {
        i++;
        cout << Fila.Item[Fila.Primeiro].Chave << " ";
        adc(Fila.Primeiro);
    }
    cout << endl;
}
