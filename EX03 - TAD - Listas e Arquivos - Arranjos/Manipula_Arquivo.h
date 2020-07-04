#ifndef MANIPULA_ARQUIVO_H_INCLUDED
#define MANIPULA_ARQUIVO_H_INCLUDED
// ------------------------------------------------------------------------
void carregaAcidentes ( TLista& lista);
void pesquisaAcidentes ( TLista& Lista, TInfo& Item);
// ------------------------------------------------------------------------
void carregaAcidentes ( ifstream &Entrada, TLista& lista )
{
    TInfo c;
    string linhas, campo ;
    int n_linha = 0;
    int n_campo, pos ;
    int n = 0;
    while ((getline(Entrada, linhas)) && (n_linha < Tmax))
    {
        n_campo = 1;
        pos = 0;
        n++;
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
                c.Codigo = campo ;
                break ;
            case 2:
                c.Cidade = campo ;
                break ;
            case 3:
                c.Rodovia = campo ;
                break ;
            case 4:
                c.Data = campo ;
                break ;
            case 5:
                c.Dia = campo ;
                break ;
            case 6:
                c.Hora = campo ;
                break ;
            case 7:
                c.TipoDeAcidente = campo ;
                break ;
            case 8:
                c.QuantMortos = campo ;
                break ;
            case 9:
                c.QuantFeridos = campo ;
                break ;
            case 10:
                c.Descricao = campo ;
                break ;
            }
            n_campo = n_campo+1;
        }
        InsereFinal(lista, c);
        n_linha = n_linha+1;
    }
    cout << n_linha << endl;
    getch();
}
// ------------------------------------------------------------------------
void pesquisaAcidentes ( TLista& Lista, TInfo& Item)
{
    string cod;
    cout << " Entre com o c�digo do acidente a ser pesquisado: ";
    cin >> cod ;
    for (int i = 0; i < Tmax; i++)
        if (( Lista.Item[i].Codigo == cod ))
        {
            cout << " C�digo: " << Lista.Item[i].Codigo << endl ;
            cout << " Cidade: " << Lista.Item[i].Cidade << endl ;
            cout << " Rodovia: " << Lista.Item[i].Rodovia << endl ;
            cout << " Data:  " << Lista.Item[i].Data << endl ;
            cout << " Dia: " << Lista.Item[i].Dia << endl ;
            cout << " Hora: " << Lista.Item[i].Hora << endl ;
            cout << " Tipo: " << Lista.Item[i].TipoDeAcidente << endl ;
            cout << " Mortos: " << Lista.Item[i].QuantMortos << endl ;
            cout << " Feridos: " << Lista.Item[i].QuantFeridos << endl ;
            cout << " Descri��o: " << Lista.Item[i].Descricao << endl ;
            getch();
        }
    cout << " Acidente n�o Encontrado !!!" << endl ;
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
#endif // MANIPULA_ARQUIVO_H_INCLUDED
