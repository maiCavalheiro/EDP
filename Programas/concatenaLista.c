#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int dado;
  struct Node *prox;
}Node;

typedef struct Lista{
  struct Node *inicio;
  struct Node *fim;
}Lista;

Lista *iniciaLista(Lista *l){
  l->inicio = NULL;
  l->fim = NULL;
  return l;
}

void  insere(Lista *l, int value) {
  Node *novo = (Node*)malloc(sizeof(Node));
  novo->dado = value;

  if(l->inicio == NULL && l->fim == NULL){
    l->inicio = novo;
    l->fim = novo;
  }
  else{
    l->fim->prox = novo;
    l->fim = novo;
    l->fim->prox = NULL;
  }
}

void imprime(Lista *l) {
  Node *aux = l->inicio;

  while (aux != NULL) {
    printf("%d -> ",aux->dado);
    aux = aux->prox;
  }
  printf("\n");
}

Lista *concatenaLista(Lista *l1, Lista *l2){ // recebe duas listas e concatena na lista 1;
  if(l1 == NULL){
    printf("A lista1 esta vazia\n");
    return 0;
  }
  if(l2 == NULL){
    printf("A lista1 esta vazia\n");
    return 0;
  }

  l1->fim->prox = l2->inicio;
  return l1;
}

void meio(Lista *l){ // função que enconta o(os) elemento(s) do meio da lista
  int cont = 0;
  int auxDiv = 0;
  Node *elemento; // guarda o elemento do meio
  Node *elemento2; // guarda o outro elemento perto do meio caso a lista seja de tamanho par
  Node *aux = l->inicio;

  while (aux != NULL) {
    cont = cont + 1;
    aux = aux->prox;
  }
   auxDiv = (cont/2)+(cont%2); // acha o meio da lista;
   aux = l->inicio; // a auxiliar volta pro inicio para percorrer outro laço

   if(auxDiv%2 != 1){ // se for uma lista com tamanho par
     for(int i = 0; i < auxDiv; i++){
          elemento = aux;
          elemento2 = elemento->prox;
          aux = aux->prox;
        }
        printf("%d e %d\n",elemento->dado, elemento2->dado);
   }
   else{ // se a lista tiver tamanho impar
     for(int i = 0; i < auxDiv; i++){
          elemento = aux;
          aux = aux->prox;
        }
        printf("%d\n",elemento->dado);
    }
}



int main(){
  Lista *L1 = (Lista*)malloc(sizeof(Lista));
  Lista *L2 = (Lista*)malloc(sizeof(Lista));

// operaçoes com a lista 1
  L1 = iniciaLista(L1);
  insere(L1, 3);
  insere(L1, 7);
  insere(L1, 9);
  insere(L1, 2);
  insere(L1, 8);
  printf("Lista1: \n");
  imprime(L1);

  printf("Elemento do meio da L1: \n");
  meio(L1);
  printf("\n");
// operaçoes com a lista 2
  L2 = iniciaLista(L2);
  insere(L2, 4);
  insere(L2, 5);
  insere(L2, 1);
  insere(L2, 6);
  printf("Lista2: \n");
  imprime(L2);

  printf("Elementos do meio da L2: \n");
  meio(L2);
  printf("\n");
// concatenação das Listas 2 e 1 na lista 1
  L1 = concatenaLista(L1,L2);
  printf("Listas 1 e 2 concatenadas:\n");
  imprime(L1);
  printf("Elemento do meio da nova L1: \n");
  meio(L1);

  free(L1);
  free(L2);
  return 0;
}
