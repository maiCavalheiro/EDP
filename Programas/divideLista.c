/* Considerando listas de valores inteiros, implemente uma função que receba como
parâmetro uma lista encadeada e um valor inteiro n e divida a lista em duas, de tal
forma que a segunda lista comece no primeiro nó logo após a primeira ocorrência de
n na lista original. A função deve retornar um ponteiro para a segunda sub-divisão da lista original,
enquanto l deve continuar apontando para o primeiro elemento da primeira subdivisão
da lista. */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
  int dado;
  struct Node* prox;
}node;

typedef struct Lista{
  node *inicio;
}Lista;

Lista *iniciaLista(Lista *list){
  list->inicio = NULL;
  return list;
}

void insere(Lista* list, int value){
  node* novo = (node*)malloc(sizeof(node));
  novo->dado = value;

  if(list->inicio == NULL){
    list->inicio = novo;
    novo->prox = NULL;
  }
  else{
    node* aux = list->inicio;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    novo->dado = value;
    novo->prox = NULL;
    aux->prox = novo;
  }
}

void imprimir(Lista *L){
  node* aux = L->inicio;

  while (aux != NULL) {
    printf("%d -> ",aux->dado);
    aux = aux->prox;
  }
  printf("NULL");
  printf("\n");
}

node* separa(Lista* L, int n) {
    node* aux = L->inicio;
    node* temp;

  while(aux != NULL){
    if (aux->dado == n) {
      temp = aux->prox;
      aux->prox = NULL;
      return temp;
    }
    else
      aux = aux->prox;
  }

}

int main(){
  Lista *L1 = (Lista*)malloc(sizeof(Lista));
  L1 = iniciaLista(L1);
  insere(L1, 3);
  insere(L1, 7);
  insere(L1, 5);
  insere(L1, 12);
  insere(L1, 5);
  insere(L1, 1);
  imprimir(L1);

  printf("%d\n", *separa(L1, 5));
  imprimir(L1);

  free(L1);
  return 0;
}
