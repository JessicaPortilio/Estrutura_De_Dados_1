;
typedef struct NodoPilha *Apontador;
typedef struct
{
    int Chave;
    /*outros componentes*/
} TInfo;
struct NodoPilha
{
    TInfo Item;
    struct NodoPilha *Proximo;
};
typedef struct
{
    struct NodoPilha *Primeiro;
    struct NodoPilha *Ultimo;
} TPilha;

//------------------------------------------------------------------------------------
void Pilha(TPilha& Pilha)
{
    Pilha.Primeiro = (Apontador) malloc(sizeof(struct NodoPilha));
    Pilha.Ultimo = Pilha.Primeiro ;
    Pilha.Primeiro -> Proximo = NULL;
}
//------------------------------------------------------------------------------------
bool Vazia(TPilha Pilha)
{
    return Pilha.Primeiro == Pilha.Ultimo?true:false;
}
//------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
void Empilha (TPilha& Pilha, TInfo Item)
{

    Apontador p = (Apontador) malloc(sizeof(struct NodoPilha));
    p -> Item = Item;
    p -> Proximo = Pilha.Primeiro -> Proximo;
    Pilha.Primeiro -> Proximo = p;
    if (p -> Proximo == NULL)
        Pilha.Ultimo = p;
}
//-------------------------------------------------------------------------------------
void Desempilha (TPilha& Pilha)
{
    if (Vazia(Pilha))
        cout << "Erro: Pilha vazia.\n" << endl;
    else
    {
        Apontador p = Pilha.Primeiro -> Proximo;
        cout << "Elemento Removido = " << p -> Item.Chave << endl;
        Pilha.Primeiro -> Proximo = p -> Proximo;
        if (Pilha.Primeiro -> Proximo == NULL)
            Pilha.Ultimo = Pilha.Primeiro ;
        free(p);
    }

}
//--------------------------------------------------------------------------------------
void Imprime(TPilha Pilha)
{
    //cout << " Itens na Pilha : " << endl ;
    if (Vazia(Pilha))
        cout << "Lista está vazia." << endl ;
    else
    {
        Apontador aux;
        aux = Pilha.Primeiro -> Proximo;
        while(aux != NULL)
        {
            cout << aux -> Item.Chave << " ";
            aux = aux -> Proximo;
        }
        cout << endl ;
    }
}
//------------------------------------------------------------------------------
void Topo (TPilha& Pilha, TInfo Item)
{

    cout << "Está no Topo: " << Pilha.Primeiro -> Proximo -> Item.Chave << endl;


}
