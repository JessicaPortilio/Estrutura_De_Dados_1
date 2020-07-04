#include <iostream>
using namespace std;

const int Tmax = 5;

typedef int Apontador;

typedef struct{
    int Chave;
} TInfo;

typedef struct{
    TInfo Item[Tmax];
    Apontador Primeiro;
    Apontador Ultimo;
} TLista;

void cria(TLista &Lista);
void insereInicio(TLista &Lista, TInfo Item);
void inserePosicao(TLista &Lista, int p, TInfo Item);
void insereFinal(TLista &Lista, TInfo Item);
void removeInicio(TLista &Lista);
void removeFinal(TLista &Lista);
void pesquisaRemove(TLista &Lista, int item);
void imprime(TLista Lista);
bool listaCheia(TLista Lista);

void cria(TLista &Lista){

    Lista.Primeiro = 0;
    Lista.Ultimo = 0;

    cout << "Lista criada com sucesso!" << endl;
}

void insereInicio(TLista &Lista, TInfo item){
    int pos;
    if(Lista.Ultimo == 0){ //se a lista tá vazia ja adicionamos de cara o valor informado pelo usuario na posição zero do vetor
        Lista.Item[0] = item; //dessa forma
        Lista.Ultimo++; //ja que foi adicionado um dado no vetor incrementamos no apontador Ultimo
        cout << "O dado foi inserido com sucesso" << endl;
    }
    else{ //mas se o vetor ja tem dados temos de deslocá-los para trás.
        for(int i=Lista.Ultimo; i>0; i--){ //deslocando todos os dados para uma posição a mais
            Lista.Item[i] = Lista.Item[i-1];
        }
        Lista.Ultimo++; //aumentando uma posição da sentinela Ultimo
        Lista.Item[pos] = item; //adicionando o valor informado pelo usuario na posição vazia que é a primeira, a que pertence a apontador primeiro
    }
}

void inserePosicao(TLista &Lista, int p, TInfo item){
    bool teste = listaCheia(Lista); //testamos se a lista ja ta cheia
    if(teste == true) //se sim nao tem mais como adicionar novos dados
        cout << "Nao tem mais como inserir dados." << endl;
    else{ //se nao vamos adicionar!
        for(int i=Lista.Ultimo+1; i>p; i--){ //deslocando todos os dados para uma posição a mais
            Lista.Item[i] = Lista.Item[i-1];
        }
        Lista.Ultimo++; //aumentando uma posição da sentinela Ultimo ja que aumentamos um dado no  vetor
        Lista.Item[p] = item; //adicionando na posição informada pelo usuario o dado informado pelo mesmo.
    }
}

void insereFinal(TLista &Lista, TInfo item){
    bool teste = listaCheia(Lista); //teste de lista cheia
    if(teste == true){ //se sim
        cout << "O vetor ja esta cheio." << endl; //nao da mais pra inserir, cai fora usuario
    }
    else{ //se nao vamos inserir
        int pos = Lista.Ultimo; //criamos uma variavel para armazenar o valor de Lista.Ultimo, isso é opcional, funcionaria se vc só usasse Lista.Ultimo
        Lista.Item[pos] = item; //adicionando na primeira posição vazia o dado informado pelo usuario
        Lista.Ultimo ++; //ja que adicionamos um novo dado vamos incrementar nossa sentinela ultimo
        cout << "Dado inserido com sucesso." << endl;
    }
}

void removeInicio(TLista &Lista){

    if(Lista.Ultimo == 0){
        cout << "vetor vazio!!" << endl;
    }
    else{
        for(int i=Lista.Ultimo; i>0; i--){ //deslocando todos os dados para uma posição a mais
            Lista.Item[i] = Lista.Item[i-1];
        }
        Lista.Ultimo++; //aumentando uma posição da sentinela Ultimo
        Lista.Primeiro++;
    }
}

void removeFinal(TLista &Lista){
    if(Lista.Ultimo == 0)
        cout << "O vetor está vazio." << endl;
    else if(Lista.Ultimo > 0 && Lista.Ultimo < Tmax){
        cout << "Entrei no segundo if" << endl;
        Lista.Ultimo--;
    }

}

void pesquisaRemove(TLista &Lista, int item){
    if(Lista.Ultimo == 0)
        cout << "Vetor está vazio." << endl;
    else{
        for(int i=item; i>Lista.Ultimo; i--){ //deslocando todos os dados para uma posição a mais
            Lista.Item[i] = Lista.Item[i+1];
        }
        Lista.Ultimo--; //aumentando uma posição da sentinela Ultimo
    }
}

void imprime(TLista Lista){
    cout << "testando funcao imprime: " << endl;
    for(int i=Lista.Primeiro; i<Lista.Ultimo; i++){
        printf("O valor da posicao %d eh: %d\n", i, Lista.Item[i]);
    }
}

bool listaCheia(TLista Lista){
    if(Tmax == Lista.Ultimo)
        return true;
    else
        return false;
}
