#include <stdio.h>
#include <stdlib.h>

//prox é um ponteiro pra estrutura de nó.

typedef struct no{
    int info;
    struct no* prox;
}no;

no* inicioL;

void inicializarLista(){ //Pontapé inicial da lista encadeada.
    inicioL = NULL;
}

int listaVazia(){ //se a lista apontar pra NULO, lista vazia.
    if(inicioL == NULL){
        return 1;
    }else{
        return 0;
    }
}

void inserirInicio(int valor){ //Cria um nó auxiliar pra alocar espaço na memória e guardar as informações, e depois encaixar o auxiliar na lista.
    no* aux;
    aux = (no*) malloc(sizeof(no));
    if(aux != NULL){ //primeiro guarda as informações do nó, depois o prox do nó aponta para NULL se for último elemento da lista.
        aux->info = valor;
        aux->prox = inicioL; //como inicioL é NULL e o primeiro elemento também é o último, e o último precisa apontar pra NULL, isso aqui dá certo. E caso fosse uma lista já feita, também daria certo, pois o inicioL apontaria para o nó do primeiro elemento da lista.
        inicioL = aux; // como estamos inserindo no início, o nó do inicioL aponta pro prox do elemento inserido.
    }else{
        printf("Não foi possível inserir!");
    }
}

void percorrerLista(){ //precisa de uma variavél auxiliar pra percorrer a lista, pois se usarmos o inicioL, podemos perder os nós pra onde inicioL está apontando.
    no* aux;
    if(!listaVazia()){
        aux = inicioL;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }else{
        printf("Lista vazia!");
    }
}

void inserirFim(int valor){
    no *aux, *p;
    aux = (no*) malloc(sizeof(no));
    if(aux!=NULL){
        aux->info = valor;
        aux->prox = NULL;
        if(!listaVazia()){
            p = inicioL;
            while(p->prox != NULL){
                p = p->prox;
            }
            p->prox = aux;
        }else{
            inicioL = aux;
        }
    }
}

void remover(int valor){
    no *ant, *aux;
    aux = inicioL;
    ant = NULL;
    if(!listaVazia()){
        //procurar pelo nó a remover
        while(aux != NULL && aux->info!=valor){
            ant = aux;
            aux=aux->prox;
        }
        if(aux == NULL){
            printf("Valor nao encontrado.");
        }else{
          if(aux->prox == NULL){
            ant->prox = NULL;
          }else{
            ant->prox = aux->prox;  
          }
            free(aux);
        }
        
    }else{
        printf("\nLista Vazia!");
    }
}

int main(){
    
    int valor, op;
    inicializarLista();
    do{
        printf("\n1- Inserir pelo inicio\n2- Percorrer e imprimir os dados\n3-Sair\n4-Remover algum elemento");
        printf("\nInforme sua alternativa: ");
        scanf("%d", &op);
        if(op!=1 && op!=2 && op!=4){
            printf("\nAlternativa invalida.");
        }else{
            if(op==1){
                printf("Valor: ");
                scanf("%d", &valor);
                inserirInicio(valor);
            }else if(op==2){
                percorrerLista();
            }else if(op == 4){
                printf("\nDigite o elemento a ser removido: ");
              scanf("%d", &valor);
              remover(valor);
            }else{
                printf("\nEncerrando...");
            }
        }
        
    }while(op!=3);
    return 0;
}
