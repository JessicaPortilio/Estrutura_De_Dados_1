;const int Tmax = 10;
typedef int Apontador;
typedef struct {
    int Chave;
    /*outros componentes*/
    } TInfo;

typedef struct {
    TInfo Item[Tmax];
    Apontador Topo;
    } TPilha;
//------------------------------------------------------------------------------------
void Pilha(TPilha& Pilha)
{
    Pilha.Topo=0;
}
//------------------------------------------------------------------------------------
bool Vazia(TPilha Pilha)
{
    return Pilha.Topo==0?true:false;
}
//------------------------------------------------------------------------------------
bool Cheia(TPilha Pilha)
{
    return Pilha.Topo >= Tmax?true:false;
}
//-------------------------------------------------------------------------------------
void Empilha (TPilha& Pilha , TInfo Item) {
    if (Cheia(Pilha))
        cout << "Erro: Pilha cheia" << endl;
    else Pilha.Item[++Pilha.Topo] = Item;
     }
//-------------------------------------------------------------------------------------
void Desempilha (TPilha& Pilha) {
    if (Vazia(Pilha))
        cout << "Erro: Pilha vazia.\n" << endl;
    else Pilha.Topo --;
    }
//--------------------------------------------------------------------------------------
void Imprime(TPilha Pilha)
{
    //cout << " Itens na Pilha : " << endl ;
    if (Vazia(Pilha))
        cout << "Lista está vazia." << endl ;
    else
    {
        for (int aux = Pilha.Topo ; aux < Pilha.Topo; aux++)
            cout << Pilha.Item[aux].Chave << " " ;
        cout << endl ;
    }
    cout << "\nQuantidade = " << Pilha.Topo << endl ;
    cout << " TMAX = " << Tmax << endl ;
}
//------------------------------------------------------------------------------
void Topo (TPilha& Pilha, TInfo Item)
{
    if (Cheia(Pilha))
        cout << "Erro: A lista está cheia." << endl ;
    else
    {
        printf("Topo: %d\n",Pilha.Item[Pilha.Topo])  ;

    }
}
