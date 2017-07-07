#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int dado;
  struct Node *prox;
  struct Node *ant;
}node;

typedef struct Lista{
  struct Node* inicio;
  struct Node* fim;
}lista;

lista* iniciaLista( lista* l){
  l->inicio = NULL;
  l->fim = NULL;

  return l;
}

void insereDuplamenteCircular(lista *l, int value){
  node *novo = (node*)malloc(sizeof(node));
  novo->dado = value;

  if(l->inicio == NULL && l->fim == NULL){ // primeira inserção
    l->inicio = novo;
    l->fim = novo;
  }
  else{
    l->fim->prox = novo;
    novo->ant = l->fim;
    l->fim = novo;
  }
  l->fim->prox = l->inicio;
  l->inicio->ant = l->fim;

}

void imprime(lista *l) {
    node *aux = l->inicio;

    if(l == NULL){
      printf("Lista vazia\n");
      return;
    }

    do{
      printf("%d -> ",aux->dado);
      aux = aux->prox;
    }
    while (aux != l->inicio);

    printf("\n");
}

void busca(lista *l, int value) {
  node* aux = l->inicio;

  if(l == NULL){
    printf("Lista vazia\n");
    return;
  }

  do{
    if(aux->dado == value){
      printf("O valor '%d' existe na lista\n",value);
      return;
    }
    aux = aux->prox;
  }
  while (aux != l->inicio);

  printf("Valor '%d' nao encontrado\n",value);
}

void removoElemento(lista *l, int value) {
  node *aux = l->inicio;
  node *auxAnt; // variavel auxiliar para guardar o anterior
  node *auxProx; // variavel auxiliar para guardar o proximo

  if(l == NULL){
    printf("Lista vazia\n");
    return;
  }

  if(value == aux->dado){ // remove do inicio
    l->fim->prox = l->inicio->prox;
    l->inicio = l->inicio->prox;
    l->inicio->ant = l->fim;
    free(aux);
    return;
  }

  do{ // percorre e elimina elemento do meio

    if(aux->dado == value){
      auxAnt = aux->ant;
      auxProx = aux->prox;
      auxAnt->prox = auxProx;
      auxProx->ant = auxAnt;
      free(aux);
      return;
    }
    aux = aux->prox;
  }
  while (aux != l->inicio);

}


int main(){
  lista *L1 = (lista*)malloc(sizeof(lista));

  L1 = iniciaLista(L1);
  insereDuplamenteCircular(L1,1);
  insereDuplamenteCircular(L1,2);
  insereDuplamenteCircular(L1,3);
  insereDuplamenteCircular(L1,1);
  insereDuplamenteCircular(L1,4);
  imprime(L1);
  busca(L1, 3);
  busca(L1, 9);
  removoElemento(L1,3);
  imprime(L1);
  return 0;
}
