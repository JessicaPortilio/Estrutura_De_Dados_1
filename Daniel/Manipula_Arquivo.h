#ifndef MANIPULA_ARQUIVO_H_INCLUDED
#define MANIPULA_ARQUIVO_H_INCLUDED
#include <fstream>
#define n_registro 7000
// ------------------------------------------------------------------------
void carregaAcidentes ( ifstream &f, TLista& lista)
{
    for (int i = 0; i < n_registro; i++)
        lista.Item[i].disponivel = 1;
    TInfo c;
    string linhas, campo ;
    int n_linha = 0;
    int n_campo, pos ;
    int n = 0;
    while (getline(f, linhas) &&(n_linha < n_registro))
    {
        n_campo = 1;
        pos = 0;
        n++;
        while(pos <= linhas.size())
        {
            campo = "";
            while((linhas[pos] != ';') && ( pos <= linhas.size()))
            {
                campo = campo + linhas[pos];
                pos = pos+1;
            }
            pos = pos+1;
            switch ( n_campo )
            {
            case 1:
                c.Chave = campo ;
                break ;
            case 2:
                c.Municipio = campo ;
                break ;
            case 3:
                c.Rodovia = campo ;
                break ;
            case 4:
                c.Data = campo ;
                break ;
            case 5:
                c.Dia_Semana = campo ;
                break ;
            case 6:
                c.Horario = campo ;
                break ;
            case 7:
                c.Tipo_Acidente = campo ;
                break ;
            case 8:
                c.Mortos = campo ;
                break ;
            case 9:
                c.Feridos = campo ;
                break ;
            case 10:
                c.Descricao = campo ;
                break ;
            }
            n_campo = n_campo+1;
        }
        c.disponivel = 0;
        n_cadastrados++;
        //acid [ n_linha ] = c;
        InsereFinal(lista, c);
        n_linha = n_linha+1;
    }
    cout << n_linha << endl;
    getch();
}
// ------------------------------------------------------------------------
void pesquisaAcidentes ( TInfo acid[])
{
    string cod;
    cout << " Entre com o código do acidente a ser pesquisa: ";
    cin >> cod ;
    for (int i = 0; i < n_registro; i++)
        if (( acid[i].Chave == cod ) && ( acid[i].disponivel == 0) )
        {
            cout << acid[i].Chave << endl ;
            cout << acid[i].Municipio << endl ;
            cout << acid[i].Rodovia << endl ;
            cout << acid[i].Data << endl ;
            cout << acid[i].Dia_Semana << endl ;
            cout << acid[i].Horario << endl ;
            cout << acid[i].Tipo_Acidente << endl ;
            cout << acid[i].Mortos << endl ;
            cout << acid[i].Feridos << endl ;
            cout << acid[i].Descricao << endl ;
            return ;
        }
    cout << " Acidente não Encontrado !!!" << endl ;
}
// ------------------------------------------------------------------------
void mostraAcidentes ( TInfo acid [])
{
    for (int i = 0; i < n_registro; i++)
        if ( acid [i].disponivel == 0)
            cout << acid[i].Chave << "-";
    cout << endl;
}
// ------------------------------------------------------------------------
#endif // MANIPULA_ARQUIVO_H_INCLUDED
