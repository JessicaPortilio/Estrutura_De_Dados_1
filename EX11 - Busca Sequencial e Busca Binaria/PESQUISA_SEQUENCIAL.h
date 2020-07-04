int Pesquisa_Sequencial(TLista l, TInfo chave, int ultimo)
{
    int cont = 0;
    for (int i = 0; i <= ultimo; i++)
    {
        if(l.Item[i].Chave == chave.Chave)
        {
            cont = i;
        }
    }
    return cont;
}
