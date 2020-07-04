#include <iostream>
using namespace std;
typedef struct
{
    int Chave;
    /*outros componentes*/
} TInfo;
struct NodoLista
{
    TInfo Item;
    struct NodoLista *Proximo;
};
typedef struct
{
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
} TLista;
typedef struct NodoLista *Apontador;
//------------------------------------------------------------------
void cria(TLista& Lista);
bool  vazia(TLista Lista);
void imprime(TLista Lista);
void InsereInicio(TLista& Lista, TInfo Item);
void InsereFinal(TLista& Lista, TInfo Item);
void InserePosicao(TLista& Lista, int pos, TInfo Item);
void RemoveInicio(TLista& Lista)
//------------------------------------------------------------------
void cria(TLista& Lista)
{
    Lista.Primeiro = (Apontador) malloc (sizeof(struct NodoLista));
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro -> Proximo = NULL;
}
//------------------------------------------------------------------
bool  vazia(TLista Lista)
{
    return Lista.Primeiro==Lista.Ultimo?true:false;
}
//------------------------------------------------------------------
void InsereInicio(TLista& Lista, TInfo Item)
{
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = Lista.Primeiro -> Proximo;
    Lista.Primeiro ->Proximo= p;

    if(p->Proximo == NULL)
        Lista.Ultimo = p;
}
//-------------------------------------------------------------------
void InsereFinal(TLista& Lista, TInfo Item)
{
     Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
     p->Item = Item;
     p->Proximo = Lista.Ultimo -> Proximo;
     Lista.Ultimo -> Proximo = p;
     if(p->Proximo == NULL)
        Lista.Ultimo = p;
}
//-------------------------------------------------------------------
void InserePosicao(TLista& Lista, int pos, TInfo Item)
{
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    Apontador ant = Lista.Primeiro;
    p->Item = Item;

    for(int i=0; i < pos; i++){
        ant = ant ->Proximo;
    }
    p -> Proximo = ant -> Proximo;
    ant -> Proximo = p;

    if(p->Proximo == NULL)
        Lista.Ultimo = p;
}
//-------------------------------------------------------------------
void RemoveInicio(TLista& Lista)
{
    if(vazia(Lista))
    {
        cout << "A lista está vazia!" << endl;
    }
    else
    {
        Apontador p = Lista.Primeiro->Proximo;
        cout << "Elemento Removido = " << p->Item.Chave;
        Lista.Primeiro->Proximo = p->Proximo;
        if(Lista.Primeiro->Proximo == NULL)
            Lista.Ultimo=Lista.Primeiro;
        free(p);
    }
}
//-------------------------------------------------------------------
void imprime(TLista Lista)
{
    cout << "Itens na Lista!" << endl;
    if(vazia(Lista))
    {
        cout << "Lista está vazia!" << endl;
    }
    else
    {
        Apontador aux;
        aux = Lista.Primeiro -> Proximo;
        while(aux != NULL)
        {
            cout << aux->Item.Chave << " ";
            aux = aux->Proximo;
        }
        aux = Lista.Primeiro -> Proximo;
    }
}
