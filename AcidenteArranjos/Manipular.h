
// ------------------------------------------------------------------------
void carregaAcidentes ( TLista& lista);
void pesquisaAcidentes ( TLista& Lista, TInfo& Item);
// ------------------------------------------------------------------------
void carregaAcidentes ( ifstream &Entrada, TLista& lista )
{
    TInfo acid;
    string linhas, campo ;
    int n_linha = 0;
    int n_campo, pos ;

    while ((getline(Entrada, linhas)) && (n_linha < Tmax))
    {
        n_campo = 1;
        pos = 0;

        int tam_string = linhas.size();
        while(pos <= tam_string)
        {
            campo = "";
            while((linhas[pos] != ';') && ( pos <= tam_string))
            {
                campo = campo + linhas[pos];
                pos = pos+1;
            }
            pos = pos+1;
            switch ( n_campo )
            {
            case 1:
                acid.Codigo = campo ;
                break ;
            case 2:
                acid.Cidade = campo ;
                break ;
            case 3:
                acid.Rodovia = campo ;
                break ;
            case 4:
                acid.Data = campo ;
                break ;
            case 5:
                acid.Dia = campo ;
                break ;
            case 6:
                acid.Hora = campo ;
                break ;
            case 7:
                acid.TipoDeAcidente = campo ;
                break ;
            case 8:
                acid.QuantMortos = campo ;
                break ;
            case 9:
                acid.QuantFeridos = campo ;
                break ;
            case 10:
                acid.Descricao = campo ;
                break ;
            }
            n_campo = n_campo+1;
        }
        InsereFinal(lista, acid);
        n_linha = n_linha+1;
    }
}
// ------------------------------------------------------------------------
void pesquisaAcidentes ( TLista& Lista, TInfo& Item)
{
    string cod;
    cout << " Entre com o código do acidente a ser pesquisado: ";
    cin >> cod ;
    for (int i = 0; i < Tmax; i++)
        if (( Lista.Item[i].Codigo == cod ))
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
        }
    cout << " Acidente não Encontrado !!!" << endl ;
}
// ------------------------------------------------------------------------
void Salvar(ofstream &Saida, TLista& Lista)
{
    for(int i=Lista.Primeiro; i<Lista.Ultimo; i++)
    {
        Saida<<Lista.Item[i].Codigo+";";
        Saida<<Lista.Item[i].Cidade+";";
        Saida<<Lista.Item[i].Rodovia+";";
        Saida<<Lista.Item[i].Data+";";
        Saida<<Lista.Item[i].Dia+";";
        Saida<<Lista.Item[i].Hora+";";
        Saida<<Lista.Item[i].TipoDeAcidente+";";
        Saida<<Lista.Item[i].QuantMortos+";";
        Saida<<Lista.Item[i].QuantFeridos+";";
        Saida<<Lista.Item[i].Descricao+"\n";
    }
}
// ------------------------------------------------------------------------

