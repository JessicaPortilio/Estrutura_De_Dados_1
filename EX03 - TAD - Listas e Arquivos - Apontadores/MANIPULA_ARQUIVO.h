#ifndef MANIPULA_ARQUIVO_H_INCLUDED
#define MANIPULA_ARQUIVO_H_INCLUDED

// --------------------------------------------------------
#include <string.h>
#include <stdlib.h>
#include <fstream>
// --------------------------------------------------------
void carregaAcidentes ( ifstream &Entrada, TLista& lista );
void pesquisaAcidente(TLista& lista, TInfo item);
// --------------------------------------------------------
void carregaAcidentes ( ifstream &Entrada, TLista& lista )
{
    TInfo c;
    string linhas, campo ;
    int n_linha = 0;
    int n_campo, pos ;
    int n = 0;
    while((getline(Entrada, linhas)) && (n_linha < 20))
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
                strcpy(c.Codigo, campo.c_str());
                //c.Codigo = campo ;
                break ;
            case 2:
                strcpy(c.Cidade, campo.c_str());
                //c.Cidade = campo ;
                break ;
            case 3:
                strcpy(c.Rodovia, campo.c_str());
                //c.Rodovia = campo ;
                break ;
            case 4:
                strcpy(c.Data, campo.c_str());
                //c.Data = campo ;
                break ;
            case 5:
                //c.Dia = campo ;
                strcpy(c.Dia, campo.c_str());
                break ;
            case 6:
                //c.Hora = campo ;
                strcpy(c.Hora, campo.c_str());
                break ;
            case 7:
                //c.TipoDeAcidente = campo ;
                strcpy(c.TipoDeAcidente, campo.c_str());
                break ;
            case 8:
                //c.QuantMortos = campo ;
                strcpy(c.QuantMortos, campo.c_str());
                break ;
            case 9:
                //c.QuantFeridos = campo ;
                strcpy(c.QuantFeridos, campo.c_str());
                break ;
            case 10:
                //c.Descricao = campo ;
                strcpy(c.Descricao, campo.c_str());
                break ;
            }
            n_campo = n_campo+1;
        }
        insereFinal(lista, c);
        n_linha = n_linha+1;
    }
    cout << n_linha << endl;
    getch();
}
// --------------------------------------------------------
void pesquisaAcidente(TLista& lista, TInfo item)
{
    Apontador aux;
    aux = lista.Primeiro->Proximo;
    while(aux != NULL)
    {
        if(!strcmp(aux->Item.Codigo, item.Codigo))
        {
            cout << " C�digo: " << aux->Item.Codigo << endl;
            cout << " Cidade: " << aux->Item.Cidade << endl;
            cout << " Rodovia: " << aux->Item.Rodovia << endl;
            cout << " Data: " << aux->Item.Data << endl;
            cout << " Dia: " << aux->Item.Dia << endl;
            cout << " Hora: " << aux->Item.Hora << endl;
            cout << " Tipo: " << aux->Item.TipoDeAcidente << endl;
            cout << " Mortos: " << aux->Item.QuantMortos << endl;
            cout << " Feridos: " << aux->Item.QuantFeridos << endl;
            cout << " Descri��o: " << aux->Item.Descricao << endl;
            getch();
        }
        aux = aux->Proximo;
    }
}
// --------------------------------------------------------
#endif // MANIPULA_ARQUIVO_H_INCLUDED
