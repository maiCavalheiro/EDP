//fila duplamente encadeada

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int chave;
  struct Node* prox;
  struct Node* ant;
}node;

typedef struct Fila{
  struct Node* inicio;
  struct Node* fim;
}fila;

fila *iniciaFila(fila *f){
  f->inicio = NULL;
  f->fim = NULL;
  return f;
}

void insereDuplamente(int valor, fila *f){
  node *novo = (node*)malloc(sizeof(node));
  novo->chave = valor;
  novo->prox = NULL;

  if(f->inicio == NULL && f->fim == NULL){
    f->inicio = novo;
    f->fim = novo;
    novo->ant = NULL;
  }else{
    novo->ant = f->fim;
    f->fim->prox = novo;
    f->fim = novo;
  }
}

void imprimir(fila *f){
  node* aux = f->inicio;

  if(aux == NULL){
    printf("Fila vazia\n");
  }

  while (aux != NULL) {
    printf("%d -> ",aux->chave);
    aux = aux->prox;
  }
  printf("\n");
}

void removerDuplaEnc(fila *f){
  node *temp = f->inicio;

  if(f->inicio == f->fim){// apenas um elemento
    f->inicio = f->fim = NULL;
  }
  else{
    f->inicio = f->inicio->prox;
    f->inicio->ant = NULL;
  }
  free(temp);
}

int main(){
  fila *F1 = (fila*)malloc(sizeof(fila));

  F1 = iniciaFila(F1);
  insereDuplamente(2, F1);
  insereDuplamente(10, F1);
  insereDuplamente(7, F1);
  insereDuplamente(15, F1);
  insereDuplamente(3, F1);
  imprimir(F1);
  removerDuplaEnc(F1);
  imprimir(F1);

  return 0;
}
