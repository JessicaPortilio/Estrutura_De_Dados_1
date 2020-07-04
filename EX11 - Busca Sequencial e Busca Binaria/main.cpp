#include <locale.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;
#include "LISTA_ARRANJO.h"
#include "PESQUISA_SEQUENCIAL.h"
#include "PESQUISA_BINARIA .h"
enum Escolhas {MOSTRAR =1, PESQUISAR_SEQ, PESQUISAR_BIN, NOVO, APAGAR, FIM};
// PROTOTIPOS ...
// ------------------------------------------------------------------------
Escolhas enterChoice();
// ------------------------------------------------------------------------
void carregaAcidentes ( ifstream &f, TLista & LAcid );
// ------------------------------------------------------------------------
void mostraAcidentes ( TLista l);
// ------------------------------------------------------------------------
void cadastraAcidentes ( TLista &l );
// ------------------------------------------------------------------------
void pesquisaAcidentes_SEQ ( TLista l);
// ------------------------------------------------------------------------
void pesquisaAcidentes_BIN ( TLista l);
// ------------------------------------------------------------------------
void shellSort(TLista &lista);
// ------------------------------------------------------------------------
void removeAcidente ( TLista &l);
// ------------------------------------------------------------------------
void atualizaAcidentes ( ofstream &f, TLista LAcid );
// FUNCAO MAIN
// ------------------------------------------------------------------------
int main ()
{
    setlocale ( LC_ALL,"portuguese");
    TLista LAcid;
    Cria ( LAcid );
    ifstream inAcidentes ("acidentes.txt", ios :: in );
    if (!inAcidentes )
    {
        cerr << " Arquivo acidentes.txt nao pode ser aberto." << endl;
        exit(1);
    }
    carregaAcidentes ( inAcidentes, LAcid );
    inAcidentes.close();
    shellSort(LAcid);
    Escolhas opcao;
    while ((opcao = enterChoice ()) != FIM )
    {
        switch ( opcao )
        {
        case MOSTRAR:
            mostraAcidentes ( LAcid );
            break;
        case PESQUISAR_SEQ:
            pesquisaAcidentes_SEQ ( LAcid );
            break;
        case PESQUISAR_BIN:
            pesquisaAcidentes_BIN ( LAcid );
            break;
        case NOVO:
            cadastraAcidentes ( LAcid );
            break;
        case APAGAR:
            removeAcidente ( LAcid );
            break;
        default :
            cerr << " Opcao incorreta\n";
            break;
        }
        cout << "\n<< TECLA ENTER PARA VOLTAR >>" << endl ;
        getch () ;
    }
    ofstream OutAcidentes (" acidentes.txt ", ios::out | ios::trunc );
    if (!OutAcidentes )
    {
        cerr << " Arquivo acidentes.txt nao pode ser aberto." << endl ;
        exit (1) ;
    }
    atualizaAcidentes ( OutAcidentes, LAcid );
    OutAcidentes.close ();
    return 0;
}
// Definicoes dos prototipos...
// ------------------------------------------------------------------------
void carregaAcidentes ( ifstream &f, TLista& l)
{
    TInfo c;
    string linhas;
    string campo;
    int n_linha = 0;
    int n_campo, pos;
    //int tot = 0;
    while ( getline (f, linhas ) /*&& tot < 11*/)
    {
        //tot++;
        n_campo = 1;
        pos = 0;
        while ( pos <= linhas.size())
        {
            campo = "";
            while (( linhas[pos] != ';') and ( pos <= linhas.size()))
            {
                campo = campo + linhas [pos];
                pos = pos + 1;
            }
            pos = pos + 1;
            switch ( n_campo )
            {
            case 1:
                c.Chave = atoi(campo.c_str());
                break;
            case 2:
                c.municipio = new char [ campo.length()+1];
                strcpy ( c.municipio, campo.c_str());
                break;
            case 3:
                c.Rodovia = new char [ campo.length()+1];
                strcpy ( c.Rodovia, campo.c_str ());
                break;
            case 4:
                c.Data = new char [ campo.length()+1];
                strcpy ( c.Data, campo.c_str ());
                break;
            case 5:
                c.Dia_Semana = new char [ campo.length()+1];
                strcpy ( c.Dia_Semana, campo.c_str ());
                break;
            case 6:
                c.Horario = new char [ campo.length ()+1];
                strcpy ( c.Horario, campo.c_str ());
                break;
            case 7:
                c.Tipo_Acidente = new char [ campo.length ()+1];
                strcpy ( c.Tipo_Acidente, campo.c_str () );
                break;
            case 8:
                c.Mortos = atoi ( campo.c_str () );
                break;
            case 9:
                c.Feridos = atoi ( campo.c_str () );
                break;
            case 10:
                c.Descricao = new char [ campo.length ()+1];
                strcpy ( c.Descricao, campo.c_str ());
                break;
            }
            n_campo = n_campo + 1;
        }
        InsereFinal (l,c);
        n_linha = n_linha + 1;
    }
}
// ------------------------------------------------------------------------
Escolhas enterChoice ()
{
    system ("cls");
    int menuChoice ;
    cout << "\nMenu :" << endl
         << "1 - Listar os Acidentes na Tela \n"
         << "2 - Pesquisa SEQUENCIAL de Acidente por Codigo \n"
         << "3 - Pesquisa BINARIA de Acidente por Codigo \n"
         << "4 - Cadastrar Novo Acidente \n"
         << "5 - Remover Acidente \n"
         << "6 - Finalizar o programa \n"
         << " Opcao : ";
    cin >> menuChoice ;
    return ( Escolhas ) menuChoice ;
}
// ------------------------------------------------------------------------
void mostraAcidentes ( TLista l)
{
    Imprime(l);
}
// ------------------------------------------------------------------------
void Imprime ( TLista& Lista )
{
    cout << " Itens na LISTA : \n" << endl ;
    if ( Vazia ( Lista ))
    {
        cout << " Lista está vazia. " << endl ;
        getch();
    }
    else
    {
        for (int i = Lista.Primeiro; i < Lista.Ultimo; i++)
        {
            cout << " Código: " << Lista.Item[i].Chave << endl ;
            cout << " Cidade: " << Lista.Item[i].municipio << endl ;
            cout << " Rodovia: " << Lista.Item[i].Rodovia << endl ;
            cout << " Data:  " << Lista.Item[i].Data << endl ;
            cout << " Dia: " << Lista.Item[i].Dia_Semana << endl ;
            cout << " Hora: " << Lista.Item[i].Horario << endl ;
            cout << " Tipo: " << Lista.Item[i].Tipo_Acidente << endl ;
            cout << " Mortos: " << Lista.Item[i].Mortos << endl ;
            cout << " Feridos: " << Lista.Item[i].Feridos << endl ;
            cout << " Descrição: " << Lista.Item[i].Descricao << endl ;
            getch();
            cout << endl << endl;
        }
    }
    cout << "\n PRIMEIRO = " << Lista.Primeiro << endl ;
    cout << " ULTIMO = " << Lista.Ultimo << endl ;
    cout << " TMAX = " << Tmax << endl ;
}
// ------------------------------------------------------------------------
void cadastraAcidentes ( TLista &l )
{
    TInfo acid;
    string strtmp;
    cout << " Codigo: ";
    cin >> acid.Chave;
    cout << " Municipio: ";
    cin >> strtmp;
    acid.municipio = new char [ strtmp.length () +1];
    strcpy ( acid.municipio, strtmp.c_str());
    cout << " Rodovia: ";
    cin >> strtmp ;
    acid.Rodovia = new char [ strtmp.length () +1];
    strcpy ( acid.Rodovia, strtmp.c_str () ) ;
    cout << " Data: ";
    cin >> strtmp ;
    acid.Data = new char [ strtmp.length ()+1];
    strcpy ( acid.Data, strtmp.c_str () );
    cout << " Dia da Semana: ";
    cin >> strtmp;
    acid.Dia_Semana = new char [ strtmp.length()+1];
    strcpy ( acid.Dia_Semana, strtmp.c_str());
    cout << " Horario : ";
    cin >> strtmp;
    acid.Horario = new char [ strtmp.length()+1];
    strcpy ( acid.Horario, strtmp.c_str());
    cout << " Tipo do Acidente : ";
    cin >> strtmp ;
    acid.Tipo_Acidente = new char [ strtmp.length()+1];
    strcpy ( acid.Tipo_Acidente, strtmp.c_str ());
    cout << " Mortos : ";
    cin >> acid.Mortos;
    cout << " Feridos : ";
    cin >> acid.Feridos;
    cout << " Descricao : ";
    cin >> strtmp;
    acid.Descricao = new char [strtmp.length()+1];
    strcpy ( acid.Descricao, strtmp.c_str ());
    InsereFinal (l, acid );
}
// ------------------------------------------------------------------------
void pesquisaAcidentes_SEQ (TLista l)
{
    TInfo acid;
    cout << " Entre com o codigo do acidente a ser pesquisa: ";
    cin >> acid.Chave;
    int achou = Pesquisa_Sequencial (l, acid, l.Ultimo-1);
    if ( achou != -1)
    {
        cout << "\n-- ----- ----- ---- ----- ----- ---- ----- ---- ----- ---" << endl;
        cout << " Codigo ........: " << l.Item[achou].Chave << endl;
        cout << " Municipio .....: " << l.Item[achou].municipio << endl;
        cout << " Rodovia .......: " << l.Item[achou].Rodovia << endl;
        cout << " Data ..........: " << l.Item[achou].Data << endl;
        cout << " Dia da Semana .: " << l.Item[achou].Dia_Semana << endl;
        cout << " Horario .......: " << l.Item[achou].Horario << endl;
        cout << " Tipo ..........: " << l.Item[achou].Tipo_Acidente << endl;
        cout << " No Mortos .....: " << l.Item[achou].Mortos << endl;
        cout << " No Feridos ....: " << l.Item[achou].Feridos << endl;
        cout << " Detalhes ......: " << l.Item[achou].Descricao << endl;
        cout << "\n-- ----- ----- ---- ----- ----- ---- ----- ---- ----- ---" << endl;
    }
    else
        cout << " Elemento nao encontrado " << endl ;
}
// ------------------------------------------------------------------------
void pesquisaAcidentes_BIN ( TLista l)
{
    TInfo acid;
    //int comp = 0;
    cout << " Entre com o codigo do acidente a ser pesquisa : ";
    cin >> acid.Chave;
    int achou = Pesquisa_Binaria(l, acid, l.Ultimo-1);
    if ( achou != -1)
    {
        cout << "\n-- ----- ----- ---- ----- ----- ---- ----- ---- ----- ---" << endl;
        cout << " Codigo ........: " << l.Item[achou].Chave << endl ;
        cout << " Municipio .....: " << l.Item[achou].municipio << endl ;
        cout << " Rodovia .......: " << l.Item[achou].Rodovia << endl ;
        cout << " Data ..........: " << l.Item[achou].Data << endl ;
        cout << " Dia da Semana .: " << l.Item[achou].Dia_Semana << endl ;
        cout << " Horario .......: " << l.Item[achou].Horario << endl ;
        cout << " Tipo ..........: " << l.Item[achou].Tipo_Acidente << endl ;
        cout << " No Mortos .....: " << l.Item[achou].Mortos << endl ;
        cout << " No Feridos ....: " << l.Item[achou].Feridos << endl;
        cout << " Detalhes ......: " << l.Item[achou].Descricao << endl;
        cout << "\n-- ----- ----- ---- ----- ----- ---- ----- ---- ----- ---" << endl;
    }
    else
        cout << " Elemento nao encontrado " << endl ;
}
// ------------------------------------------------------------------------
void removeAcidente ( TLista &l)
{
    TInfo acid ;
    cout << " Entre com o codigo do acidente a ser removido : ";
    cin >> acid.Chave;
    PesquisaRemove (l, acid.Chave);
}
// ------------------------------------------------------------------------
void PesquisaRemove ( TLista & Lista, TInfo Item )
{
    if ( Vazia ( Lista ))
    {
        cout << " Erro: A lista está vazia.\n" << endl;
        getch();
    }
    else
    {
        int aux = Lista.Primeiro;
        while (( Lista.Item[aux].Chave != Item.Chave ) && ( aux < Lista.Ultimo-1))
            aux ++;
        if ( Lista.Item[aux].Chave == Item.Chave )
        {
            cout << " Elemento removido " << endl << endl;
            cout << " Código: " << Lista.Item[aux].Chave << endl ;
            cout << " Cidade: " << Lista.Item[aux].municipio << endl ;
            cout << " Rodovia: " << Lista.Item[aux].Rodovia << endl ;
            cout << " Data:  " << Lista.Item[aux].Data << endl ;
            cout << " Dia: " << Lista.Item[aux].Dia_Semana << endl ;
            cout << " Hora: " << Lista.Item[aux].Horario << endl ;
            cout << " Tipo: " << Lista.Item[aux].Tipo_Acidente << endl ;
            cout << " Mortos: " << Lista.Item[aux].Mortos << endl ;
            cout << " Feridos: " << Lista.Item[aux].Feridos << endl ;
            cout << " Descrição: " << Lista.Item[aux].Descricao << endl ;
            getch();
            RemovePosicao ( Lista, aux );
        }
        else
            cout << " Elemento não encontrado " << endl ;
    }
}
// ------------------------------------------------------------------------
void atualizaAcidentes ( ofstream &f, TLista Lista )
{
    if ( Vazia ( Lista ))
        cout << " Lista esta vazia." << endl;
    else
    {
        for (int aux = Lista.Primeiro; aux < Lista.Ultimo; aux++)
        {
            f << Lista.Item[aux].Chave << ";";
            f << Lista.Item[aux].municipio << ";";
            f << Lista.Item[aux].Rodovia << ";";
            f << Lista.Item[aux].Data << ";";
            f << Lista.Item[aux].Dia_Semana << ";";
            f << Lista.Item[aux].Horario << ";";
            f << Lista.Item[aux].Tipo_Acidente << ";";
            f << Lista.Item[aux].Mortos << ";";
            f << Lista.Item[aux].Feridos << ";";
            f << Lista.Item[aux].Descricao << endl ;
        }
        cout << " Acidentes Atualizados no Arquivo !!! " << endl ;
    }
}
// ---------------------------------------------
void shellSort(TLista& lista)
{
    int h=1, inner, outer;
    TInfo temp;

    while(h <= lista.Ultimo-1/3)
        h = h*3+1;

    while(h>0)
    {
        for(outer=h; outer<lista.Ultimo; outer++)
        {
            temp = lista.Item[outer];
            inner = outer;

            while(inner>h-1 && lista.Item[inner-h].Chave >= temp.Chave)
            {
                lista.Item[inner] = lista.Item[inner-h];
                inner-=h;
            }
            lista.Item[inner] = temp;
        }
        h = (h-1)/3;
    }
}
