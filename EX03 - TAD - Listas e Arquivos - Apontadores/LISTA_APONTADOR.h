#ifndef LISTA_APONTADOR_H_INCLUDED
#define LISTA_APONTADOR_H_INCLUDED

// Bibliotecas -------------------------------
#include <stdlib.h>
#include <conio2.h>
#include <iostream>
#include <string.h>
using namespace std;

// Definições e structs -------------------------------
typedef struct NodoLista *Apontador;

typedef struct
{
    char Codigo[5];
    char Cidade[20];
    char Rodovia[10];
    char Data[11];
    char Dia[14];
    char Hora[5];
    char TipoDeAcidente[15];
    char QuantMortos[3];
    char QuantFeridos[3];
    char Descricao[150];
}TInfo;

struct NodoLista {
    TInfo Item;
    struct NodoLista *Proximo;
};

typedef struct
{
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
}TLista;

// Protótipos -------------------------------
void cria (TLista& Lista);
char menu();
void setDados(TInfo& item);
void setDadosPesquisa(TInfo& item);
void setPosicao(int& pos);
bool vazia(TLista& lista);
void insereInicio(TLista& lista, TInfo item);
void inserePosicao(TLista& lista, TInfo item, int p);
void removeInicio(TLista& lista);
void insereFinal(TLista& lista, TInfo item);
void removeFinal(TLista& lista);
void removePosicao(TLista& lista, Apontador p);
void pesquisaRemove(TLista& lista, TInfo item);
void imprime(TLista& lista);

// Funções -------------------------------
void cria(TLista& lista)
{
    lista.Primeiro = (Apontador) malloc (sizeof(struct NodoLista));
    lista.Ultimo = lista.Primeiro;
    lista.Primeiro->Proximo = NULL;
}
// -------------------------------
char menu()
{
    char opc;
    clrscr();
    //Imprime(lista);

    cout << "\n Menu de escolhas\n\n"
         << " 1 - InsereInicio\n"
         << " 2 - InserePosição\n"
         << " 3 - InsereFinal\n"
         << " 4 - RemoveInicio\n"
         << " 5 - RemoveFinal\n"
         << " 6 - Pesquisa_Remove\n"
         << " 7 - Imprime\n"
         << " 8 - Pesquisar_Acidente\n"
         << " 9 - Finalizar\n\n"
         << " Escolha uma opção: ";
    cin >> opc;
    return toupper(opc);
}
// -------------------------------
void setDados(TInfo& item)
{
    cout << endl;
    cout << " Informe o código: ";
    cin >> item.Codigo;
}
// -------------------------------
void setDadosPesquisa(TInfo& item)
{
    cout << endl;
    cout << " Informe o código: ";
    cin >> item.Codigo;
}
// -------------------------------
void setPosicao(int& pos)
{
    cout << " \nInforme a posição: ";
    cin >> pos;
}
// -------------------------------
bool vazia(TLista& lista)
{
    return lista.Primeiro == lista.Ultimo ? true : false;
}
// -------------------------------
void insereInicio(TLista& lista, TInfo item)
{
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    p->Item = item;
    p->Proximo = lista.Primeiro->Proximo;
    lista.Primeiro->Proximo = p;

    if(p->Proximo == NULL)
        lista.Ultimo = p;
}
// -------------------------------
void inserePosicao(TLista& lista, TInfo item, int p)
{
    if(p == 1)
        insereInicio(lista, item);
    else
    {
        int i;
        Apontador aux;
        i = 1;
        aux = lista.Primeiro->Proximo;
        while((i < p-1) && (aux != NULL))
        {
            i++;
            aux = aux->Proximo;
        }
        if(aux == NULL)
            cout << " Erro: Posição não existe!\n ";
        else
        {
            Apontador ptr = (Apontador) malloc (sizeof(struct NodoLista));
            ptr->Item = item;
            ptr->Proximo = aux->Proximo;
            aux->Proximo = ptr;
        }
    }
}
// -------------------------------
void removeInicio(TLista& lista)
{
    if(vazia(lista))
    {
        cout << " Erro: A lista está vazia.\n ";
        getch();
    }
    else
    {
        Apontador p = lista.Primeiro->Proximo;
        cout << " Elemento Removido:\n ";
        cout << p->Item.Codigo << endl;
        //cout << ;
        lista.Primeiro->Proximo = p->Proximo;
        if(lista.Primeiro->Proximo == NULL)
            lista.Ultimo = lista.Primeiro;
        free(p);
    }
}
// -------------------------------
void insereFinal(TLista& lista, TInfo item)
{
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    p->Item = item;
    p->Proximo = NULL;
    lista.Ultimo->Proximo = p;
    lista.Ultimo = p;
}
// -------------------------------
void removeFinal(TLista& lista)
{
    if(vazia(lista))
    {
        cout << " Erro: A lista está vazia.\n ";
        getch();
    }
    else
    {
        Apontador p = lista.Primeiro->Proximo;
        if(p->Proximo == NULL)
        {
            lista.Primeiro->Proximo = NULL;
            lista.Ultimo = lista.Primeiro;
        }
        else
        {
            Apontador aux;
            while(p->Proximo != NULL)
            {
                aux = p;
                p = p->Proximo;
            }
            aux->Proximo = NULL;
            lista.Ultimo = aux;
        }
        free(p);
    }
}
// -------------------------------
void removePosicao(TLista& lista, Apontador p)
{
    if((vazia(lista)) || (p == NULL) || (p->Proximo == NULL))
    {
        cout << " Erro: Lista vazia ou posição não existe.\n ";
        getch();
    }
    else
    {
        Apontador q = p->Proximo;
        p->Proximo = q->Proximo;
        if(p->Proximo == NULL)
            lista.Ultimo = p;
        free(q);
    }
}
// -------------------------------
/*void pesquisaRemove(TLista& lista, TInfo item)
{
    if(vazia(lista))
    {
        cout << " Erro: A lista está vazia.\n ";
        getch();
    }
    else
    {
        if(strcmp(lista.Primeiro->Proximo->Item.Codigo, item.Codigo))
            removeInicio(lista);
        else
        {
            Apontador aux;
            aux = lista.Primeiro->Proximo;
            while((!strcmp(aux->Item.Codigo, item.Codigo)) && (aux->Proximo->Proximo != NULL))
                aux = aux->Proximo;
            if(strcmp(aux->Proximo->Item.Codigo, item.Codigo))
                removePosicao(lista,aux);
            else
                cout << " Elemento não encontrado.\n " << endl;
        }
    }
}*/
void pesquisaRemove(TLista& lista, TInfo item)
{
    if(vazia(lista))
    {
        cout << "Erro: Lista vazia!";
        getch();
    }
    else
    {
        Apontador anterior = lista.Primeiro; // Parte da celula cabeça por isso fica um nó atrás
        Apontador excluir = lista.Primeiro->Proximo; // Começa do primeiro nó da lista.
        while(excluir != NULL)
        {
            if(!strcmp(excluir->Item.Codigo, item.Codigo))
            {
                cout << " Item excluido: \n" << endl;
                cout << " Código: " << excluir->Item.Codigo << endl;
                cout << " Cidade: " << excluir->Item.Cidade << endl;
                cout << " Rodovia: " << excluir->Item.Rodovia << endl;
                cout << " Data: " << excluir->Item.Data << endl;
                cout << " Dia: " << excluir->Item.Dia << endl;
                cout << " Hora: " << excluir->Item.Hora << endl;
                cout << " Tipo: " << excluir->Item.TipoDeAcidente << endl;
                cout << " Mortos: " << excluir->Item.QuantMortos << endl;
                cout << " Feridos: " << excluir->Item.QuantFeridos << endl;
                cout << " Descrição: " << excluir->Item.Descricao << endl;
                getch();

                anterior->Proximo = excluir->Proximo; // Caso encontre o item execulta essa linha e o proximo ao exclído é passado para anterior assim
                                                     // apagando o item retirando a referencia do apontador para o nó
            }
            anterior = anterior->Proximo; // Fica um nó atrás do Apontador excluir ~sendo a primeira execução a passagem para o primeiro nó~
            excluir = excluir->Proximo; // Passando para o próximo nó apos a 1ª comparação
        }
        if(lista.Primeiro->Proximo == NULL)
            lista.Ultimo = lista.Primeiro;
        free(excluir);
        free(anterior);
    }
}
// -------------------------------
void imprime(TLista& lista)
{
    cout << " \nItens na LISTA:\n " << endl;
    if(vazia(lista))
    {
        cout << " Lista está vazia. " << endl;
        getch();
    }
    else
    {
        Apontador aux;
        aux = lista.Primeiro->Proximo;
        while(aux != NULL)
        {
            cout << " Código: " << aux->Item.Codigo << endl;
            cout << " Cidade: " << aux->Item.Cidade << endl;
            cout << " Rodovia: " << aux->Item.Rodovia << endl;
            cout << " Data: " << aux->Item.Data << endl;
            cout << " Dia: " << aux->Item.Dia << endl;
            cout << " Hora: " << aux->Item.Hora << endl;
            cout << " Tipo: " << aux->Item.TipoDeAcidente << endl;
            cout << " Mortos: " << aux->Item.QuantMortos << endl;
            cout << " Feridos: " << aux->Item.QuantFeridos << endl;
            cout << " Descrição: " << aux->Item.Descricao << endl;
            getch();
            aux = aux->Proximo;
            cout << endl;
        }
    }
}
// -------------------------------
#endif // LISTA_APONTADOR_H_INCLUDED
