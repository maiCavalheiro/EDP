// multiplas listas
#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
}SNo;

typedef struct Lista{
  struct SNo *inicio;
  struct SNo *fim;
}Lista;

Lista *iniciaLista(Lista *L){
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

void insere(int value, Lista *L){ // insere no fim
  SNo *novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = value;
  novo->prox = NULL;

  if(L->fim == NULL){ // primeira inserção
    L->fim = novo;
    L->inicio = novo;
    //novo->prox = NULL;
  }
  else{
    L->fim->prox = novo;
    L->fim = novo;
    //novo->prox = NULL;
  }
}

void imprimir(Lista *L){
  SNo* aux = L->inicio;

  while (aux != NULL) {
    printf("%d -> ",aux->chave);
    aux = aux->prox;
  }
  printf("\n");
}

void remover(Lista *L){ // remove do inicio
  SNo* temp = L->inicio;

  if(temp == NULL){
    printf("Lista vazia\n");
    return;
  }

  if(L->inicio == L->fim){
    L->inicio = L->fim = NULL;
    //free(temp);
  }
  else{
      L->inicio = L->inicio->prox;
      free(temp);
    }
}

int busca(Lista *L, int value){
  SNo *temp = L->inicio;

  if(temp == NULL){
    printf("Lista vazia\n");
    return 0;
  }

  while(temp != NULL){
    if(temp->chave != value){
      temp = temp->prox;
    }
    else{
      return 1;
    }
  }
  return 0;
}

int main(){
  int aux;
  Lista *L1 = (Lista*)malloc(sizeof(Lista));
  Lista *L2 = (Lista*)malloc(sizeof(Lista));

  printf("Lista 1:\n");
  L1 = iniciaLista(L1);
  insere(5, L1);
  insere(10, L1);
  imprimir(L1);

  aux = busca(L1, 5);
   if(aux == 1)
     printf("O elemento se encontra na lista\n");
   else
     printf("O elemento nao esta na lista\n");

     remover(L1);
     imprimir(L1);

  printf("\n");

  printf("Lista 2:\n");
  L2= iniciaLista(L2);
  insere(8, L2);
  insere(20, L2);
  imprimir(L2);
  remover(L2);
  imprimir(L2);

  free(L1);
  free(L2);

  return 0;
}
