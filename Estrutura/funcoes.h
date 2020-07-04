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
    if(Lista.Ultimo == 0){
        Lista.Item[0] = item;
        Lista.Ultimo++;
        cout << "O dado foi inserido com sucesso!" << endl;
    }
    else{
        for(int i=Lista.Ultimo; i>0; i--){
            Lista.Item[i] = Lista.Item[i-1];
        }
        Lista.Ultimo++;
        Lista.Item[pos] = item;
    }
}

void inserePosicao(TLista &Lista, int p, TInfo item){
    bool teste = listaCheia(Lista);
    if(teste == true)
        cout << "Nao tem mais como inserir dados. Está cheio!" << endl;
    else{
        for(int i=Lista.Ultimo+1; i>p; i--){
            Lista.Item[i] = Lista.Item[i-1];
        }
        Lista.Ultimo++;
        Lista.Item[p] = item;
    }
}

void insereFinal(TLista &Lista, TInfo item){
    bool teste = listaCheia(Lista);
    if(teste == true){ //se sim
        cout << "O vetor já está cheio!" << endl;
    }
    else{
        int pos = Lista.Ultimo;
        Lista.Item[pos] = item;
        Lista.Ultimo ++;
        cout << "Dado inserido com sucesso!" << endl;
    }
}

void removeInicio(TLista &Lista){

    if(Lista.Ultimo == 0){
        cout << "Vetor vazio!!!" << endl;
    }
    else{
        for(int i=Lista.Ultimo; i>0; i--){
            Lista.Item[i] = Lista.Item[i-1];
        }
        Lista.Ultimo++;
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
        for(int i=item; i>Lista.Ultimo; i--){
            Lista.Item[i] = Lista.Item[i+1];
        }
        Lista.Ultimo--;
    }
}

void imprime(TLista Lista){

    for(int i=Lista.Primeiro; i<Lista.Ultimo; i++){
        printf("O valor da posição %d eh: %d\n", i, Lista.Item[i]);
    }
}

bool listaCheia(TLista Lista){
    if(Tmax == Lista.Ultimo)
        return true;
    else
        return false;
}
