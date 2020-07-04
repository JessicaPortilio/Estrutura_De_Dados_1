//----LISTA IMPLEMENTADA POR MEIO DE APONTADOR ---typedef struct NodoLista *Apontador;
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
//--------------------------------------------

void Cria (TLista& Lista);
bool Vazia (TLista Lista);
void InsereInicio (TLista& Lista, TInfo Item);
void RemoveInicio (TLista& Lista);
void Imprime (TLista Lista);
void InsereFinal (TLista& Lista ,TInfo Item);
void RemoveFinal (TLista& Lista);
void InserePosicao(TLista& Lista,int pos, TInfo Item);
void PesquisaRemove(TLista& Lista, TInfo Item);
//--------------------------------------------
void Cria (TLista& Lista)
{
    Lista.Primeiro = (Apontador) malloc(sizeof(struct NodoLista));
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro ->Proximo = NULL;
}
//--------------------------------------------
bool Vazia (TLista Lista)
{
    return Lista.Primeiro==Lista.Ultimo?true:false;
}
//--------------------------------------------
void InsereInicio (TLista& Lista, TInfo Item)
{
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = Lista.Primeiro ->Proximo;
    Lista.Primeiro ->Proximo = p;
    if (p->Proximo == NULL)
        Lista.Ultimo = p;
}
//--------------------------------------------
void InserePosicao(TLista& Lista,int pos, TInfo Item)
{
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    Apontador pant = Lista.Primeiro;
    p -> Item = Item;

    for(int i=0; i<pos; i++)
    {

        pant = pant -> Proximo;

    }
    p -> Proximo = pant -> Proximo;
    pant -> Proximo = p;

    if (p->Proximo == NULL)
        Lista.Ultimo = p;
}

//--------------------------------------------
void RemoveInicio (TLista& Lista)
{
    if (Vazia(Lista))
        cout << "Erro : A lista esta vazia.\n" << endl;
    else
    {
        Apontador p = Lista.Primeiro ->Proximo;
        cout << "Elemento Removido = " << p->Item.Chave << endl;
        Lista.Primeiro ->Proximo = p->Proximo;
        if (Lista.Primeiro ->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;
        free(p);
    }
}
//---------------------------------------------
void InsereFinal (TLista& Lista ,TInfo Item)
{
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = Lista.Ultimo ->Proximo;
    Lista.Ultimo ->Proximo = p;
    if (p->Proximo == NULL)
        Lista.Ultimo = p;
}
//--------------------------------------------
void RemoveFinal (TLista& Lista)
{
    if (Vazia(Lista))
        cout << "Erro : A lista esta vazia.\n" << endl;
    else
    {
        Apontador p = Lista.Primeiro;
        Apontador pUlt;

        while(p -> Proximo != NULL)
        {
            pUlt = p;
            p = p -> Proximo;
        }
        pUlt -> Proximo = NULL;
        Lista.Ultimo = pUlt;
        free(p);
        if (Lista.Primeiro ->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;

    }
}
//--------------------------------------------
void PesquisaRemove(TLista& Lista, TInfo Item)
{
    if (Vazia(Lista))
        cout << "Erro : A lista esta vazia.\n" << endl;
    else
    {
        Apontador aux = Lista.Primeiro;
        Apontador p = Lista.Primeiro -> Proximo;
        while(p != NULL)
        {
            if(p->Item.Chave==Item.Chave)
            {
                aux->Proximo = p->Proximo;
            }
                aux = aux->Proximo;
                p=p->Proximo;

        }
        if (Lista.Primeiro ->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;
        free(p);
        free(aux);
    }
}
//--------------------------------------------
void Imprime (TLista Lista)
{
    cout << "Itens na LISTA: " << endl;
    if (Vazia(Lista))
        cout << "Lista esta vazia." << endl;
    else
    {
        Apontador aux;
        aux = Lista.Primeiro ->Proximo;
        while (aux != NULL)
        {
            cout << aux->Item.Chave << " ";
            aux = aux->Proximo;
        }
        aux = Lista.Primeiro -> Proximo;
        cout << endl;
    }
}
//--------------------------------------------


