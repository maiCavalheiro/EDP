#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node *esq;
  struct Node *dir;
}Node;

Node *insere (Node *a, int value){

  if( a == NULL){ // verifica se esta vazio e aloca um novo nó
    a = (Node*)malloc(sizeof(Node));
    a->data = value;
    a->esq = NULL;
    a->dir = NULL;
  }

  if(a->data < value){ // se o valor for maior insere a direita
    a->dir = insere(a->dir, value);
  }
  if(a->data > value){ //se o valor for menor insere a esquerda
    a->esq = insere(a->esq, value);
  }

  return a; // retorna um ponteiro para a raiz
}

void imprime( Node *a){
  while(a != NULL){
    imprime(a->esq);
    printf("%d\n",a->data);
    imprime(a->dir);
  }
}


int main(){
  Node *arvore;
  arvore = NULL;

  arvore = insere(arvore, 4);
  arvore = insere(arvore, 2);
  arvore = insere(arvore, 1);
  arvore = insere(arvore, 3);
  arvore = insere(arvore, 6);
  arvore = insere(arvore, 5);
  arvore = insere(arvore, 7);

  imprime(arvore);

  free(arvore);
  return 0;
}
