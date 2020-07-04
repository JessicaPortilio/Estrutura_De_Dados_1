int Pesquisa_Binaria (TLista l, TInfo acid, int n)
{
    int meio;
    if (Vazia(l))
        cout << "Erro: Lista vazia!\n";
    else
    {
        int inicio = 0;
        int fim = n;
        meio = (inicio+fim)/2;
        while ((l.Item[meio].Chave != acid.Chave) && (inicio != fim))
        {
            if (acid.Chave > l.Item[meio].Chave)
                inicio = meio + 1;
            else
                fim = meio;
            meio = (inicio+fim)/2;
        }
    }
    if (acid.Chave == l.Item[meio].Chave)
        return meio;
    else
        return -1;
}
