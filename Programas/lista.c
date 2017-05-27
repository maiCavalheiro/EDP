#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
}Node;

Node *inicio = NULL;

void insere (int value){
   Node *nova = (Node*)malloc(sizeof (Node));
   nova->chave = value;
   nova->prox = inicio;
   inicio = nova;
}

void insereOrdenado(int value) {
  Node *novo = (Node*)malloc(sizeof(Node));
  Node *temp = inicio;
  Node *ant = NULL;

  novo->chave = value;

  if(temp == NULL){ // primeira inserção de elemento na lista
    novo->prox = inicio;
    inicio = novo;
    return;
  }

  if(value < temp->chave){// caso o valor seja menor que o primeiro elemento da lista
    novo->prox = inicio;
    inicio = novo;
    return;
  }

  while (temp != NULL) {
    if (value > temp->chave){ // compara e percorre a lista
      ant = temp;
      temp = temp->prox;
    }
    else{ // insere no meio da lista
      ant->prox = novo;
      novo->prox = temp;
      return;
    }
  }
  ant->prox = novo;
  novo->prox = temp;
}

void imprimir(){
  Node* aux = inicio;

  while (aux != NULL) {
    printf("%d -> ",aux->chave);
    aux = aux->prox;
  }
  printf("\n");
 }

int busca(int value){
  Node* aux = inicio;

  if (aux == NULL){
      printf("A lista esta vazia\n");
      return 0;
  }
    while (aux != NULL) {
      if (value == aux->chave) {
        return 1;
    }else
      aux = aux->prox;
    }
  return 0;
}

void remover(int value){
  Node* temp = inicio;
  Node* anterior = NULL;

  if (temp == NULL) {
    printf("Lista vazia\n");
    return;
  }

  if(anterior == NULL && value == temp->chave){// remove do inicio
    inicio = temp->prox;
    free(temp);
    return;
  }

  while (temp != NULL) {
    if(value == temp->chave){ // remove do meio
      anterior->prox = temp->prox;
      free(temp);
      return;
    }
    else{
        anterior = temp;
        temp = temp->prox;
    }
  }

}

int main(){
  int aux;

  insereOrdenado(2);
  insereOrdenado(5);
  insereOrdenado(3);
  insereOrdenado(1);
  insereOrdenado(4);
  imprimir();

  aux = busca(4);
   if(aux == 1)
     printf("O elemento se encontra na lista\n");
   else
     printf("O elemento nao esta na lista\n");

  remover(1);
  imprimir();
  return 0;
}
