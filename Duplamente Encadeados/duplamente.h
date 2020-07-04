#include <iostream>
using namespace std;
typedef struct nodoLista *apontador;

typedef struct
{
    int Chave;
    /*outros componentes*/
} TInfo;

struct nodoLista
{
    TInfo Item;
    struct nodoLista *Anterior;
    struct nodoLista *Proximo;
};

typedef struct
{
    struct nodoLista *Primeiro;
    struct nodoLista *Ultimo;
} TLista;
//------------------------------------------------------------------------
void cria (TLista& Lista);
void setDados (TInfo& Item);
void setPosicao(int& pos);
bool vazia (TLista& Lista);
void insereInicio (TLista& Lista, TInfo Item);
void insereFinal (TLista& Lista, TInfo Item);
void inserePosicao (TLista& Lista, int pos, TInfo Item);
void removeInicio (TLista& Lista);
void removeFinal (TLista& Lista);
void pesquisaRemove (TLista& Lista, TInfo Item);
void imprime (TLista& Lista);
void imprimeContrario(TLista& Lista);
//------------------------------------------------------------------------
void cria (TLista& Lista)
{
    Lista.Primeiro = (apontador) malloc(sizeof(struct nodoLista));
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro -> Proximo = NULL;
    Lista.Ultimo -> Anterior = NULL;
}
//-------------------------------------------------------------------------
void setDados (TInfo& Item)
{
    cout << "\n Informe o código: ";
    cin >> Item.Chave;
}
//-------------------------------------------------------------------------
void setPosicao(int& pos)
{
    cout << "\n Informe a posição: ";
    cin >> pos;
}
//-------------------------------------------------------------------------
bool vazia (TLista& Lista)
{
    return Lista.Primeiro == Lista.Ultimo ? true : false;
}
//-------------------------------------------------------------------------
void insereInicio (TLista& Lista, TInfo Item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoLista));
    apontador aux;
    p -> Item = Item;
    p -> Anterior = NULL;
    p -> Proximo = Lista.Primeiro -> Proximo;
    aux -> Proximo = Lista.Primeiro -> Proximo;
    Lista.Primeiro -> Proximo = p;
    if(p->Proximo == NULL)
    {
        Lista.Ultimo = p;
    }
    else
    {
        aux->Proximo->Anterior=p;
    }
    free(aux);
}
//-------------------------------------------------------------------------
void insereFinal (TLista& Lista, TInfo Item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoLista));
    p->Item=Item;
    p->Proximo=NULL;
    if(vazia(Lista))
    {
        p->Anterior=Lista.Ultimo->Proximo;
    }
    else
    {
        p->Anterior=Lista.Ultimo;
    }
    Lista.Ultimo->Proximo=p;
    Lista.Ultimo=p;
}
//-------------------------------------------------------------------------
void inserePosicao (TLista& Lista, int pos, TInfo Item)
{
    if(pos==1)
    {
        fflush(stdin);
        insereInicio(Lista, Item);
    }
    else{
        apontador aux = Lista.Primeiro -> Proximo;
        int i = 1;
        while( (i < pos -1) && (aux != NULL) )
        {
            i++;
            aux = aux -> Proximo;
        }
        if((aux==NULL) || (pos < 1))
        {
            cout << "\n Erro: Posição não existe!" << endl;
        }
        else
        {
            apontador p = (apontador) malloc(sizeof(struct nodoLista));
            p->Item = Item;
            p->Proximo = aux->Proximo;
            p->Anterior = aux;
            aux->Proximo = p;

            if(p->Proximo == NULL)
                Lista.Ultimo = p;
            else
                p->Proximo->Anterior = p;
        }
    }
}
//---------------------------------------------------------------------------------
void removeInicio (TLista& Lista)
{
    if(vazia(Lista))
    {
        cout << "\n ERRO: A lista está vazia." << endl;
    }
    else
    {
        apontador p = Lista.Primeiro->Proximo;
        cout << "\n Elemento removido = " << p->Item.Chave << endl;
        Lista.Primeiro->Proximo = p->Proximo;
        if(Lista.Primeiro->Proximo == NULL)
        {
            Lista.Ultimo = Lista.Primeiro;
        }
        else
        {
            p->Proximo->Anterior = NULL;
        }
        free(p);
    }
}
//--------------------------------------------------------------------------
void removeFinal (TLista& Lista)
{
    if(vazia(Lista))
    {
        cout << "\n ERRO: A lista está vazia! " << endl;
    }
    else
    {
        apontador p = Lista.Primeiro->Proximo;
        if(p->Proximo == NULL)
        {
            removeInicio(Lista);
        }
        else
        {
            cout << "\n Elemento removido = " << Lista.Ultimo->Item.Chave << endl;
            Lista.Ultimo = Lista.Ultimo->Anterior;
            Lista.Ultimo->Proximo = NULL;
        }
        free(p);
    }
}
//--------------------------------------------------------------------------------------
void pesquisaRemove (TLista& Lista, TInfo Item)
{
    if(vazia(Lista))
    {
        cout << "\n Lista vazia, não há o que pesquisar!";
    }
    else
    {
        if(Lista.Primeiro->Proximo->Item.Chave == Item.Chave)
            removeInicio(Lista);
        else if(Lista.Ultimo->Item.Chave == Item.Chave)
            removeFinal(Lista);
        else
        {
            apontador aux = Lista.Primeiro->Proximo;
            while((aux->Item.Chave != Item.Chave) && (aux != NULL))
                aux = aux->Proximo;

            cout << "\n Elemento removido = " << aux->Item.Chave << endl;
            if(aux->Proximo == NULL)
                Lista.Ultimo = aux;
            else
            {
                aux->Anterior->Proximo = aux->Proximo;
                aux->Proximo->Anterior = aux->Anterior;
            }
        }
    }
}
//----------------------------------------------------------------------------------
void imprime (TLista& Lista)
{
    cout << " Itens na LISTA:\n";
    if(vazia(Lista))
        cout << " A lista está vazia!\n";
    else
    {
        apontador aux = Lista.Primeiro->Proximo;
        while(aux != NULL)
        {
            cout << " " << aux->Item.Chave;
            aux = aux->Proximo;
        }
        cout << endl;
    }
}
//------------------------------------------------------------------------------------
void imprimeContrario(TLista& Lista)
{
     cout << "\n Itens na LISTA INVERTIDA:\n";
    if(vazia(Lista))
        cout << " A lista está vazia!\n";
    else
    {
        apontador aux = Lista.Ultimo;
        while(aux != NULL)
        {
            cout << " " << aux->Item.Chave;
            aux = aux->Anterior;
        }
        cout << endl;
    }
}
