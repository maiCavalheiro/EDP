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
    printf("Impressao: Fila vazia");
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

void buscaOtimizada(fila *f, int value){
  node *auxIni = f->inicio;
  node *auxFim = f->fim;

  if(auxIni == NULL && auxFim == NULL){
    printf("Busca: Fila vazia\n");
    return;
  }

  if(auxIni == auxFim){ // apenas um elemento na fila
    printf("Valor encontrado \n");
    return;
  }

  while (auxIni != auxFim) {
    if(auxIni->chave != value){
      auxIni = auxIni->prox;
    }
    else{
      printf("Valor encontrado \n");
      return;
    }

    if(auxFim->chave != value){
      auxFim = auxFim->ant;
    }
    else{
      printf("Valor encontrado \n");
      return;
    }
  }

    if(auxIni == auxFim){ // caso os ponteiros se encontrem
      printf("Valor %d nao encontrado\n",value);
      return;
    }

}

void removerTodos(fila *f){ // remove todos os elementos da fila
  node *aux = f->inicio;

  while (aux != f->fim) { // laço que remove até o penultimo elemento
    aux = aux->prox;
    f->inicio = f->inicio->prox;
    f->inicio->ant = NULL;
  }

  if(f->inicio == f->fim){// remove o ultimo elemento
    f->inicio = f->fim = NULL;
  }
  free(aux);
}


int main(){
  fila *F1 = (fila*)malloc(sizeof(fila));

  F1 = iniciaFila(F1);
  insereDuplamente(2, F1);
  insereDuplamente(10, F1);
  insereDuplamente(7, F1);
  insereDuplamente(8, F1);
  insereDuplamente(15, F1);
  insereDuplamente(3, F1);
  imprimir(F1);
  buscaOtimizada(F1,8);
  removerDuplaEnc(F1); // remover um elemento
  imprimir(F1);
  removerTodos(F1); // remover todos os elementos da fila
  imprimir(F1);
  insereDuplamente(2, F1);
  imprimir(F1);

  free(F1);

  return 0;
}
