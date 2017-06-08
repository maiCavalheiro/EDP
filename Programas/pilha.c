#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int chave;
  struct Node *prox;
}node;

typedef struct Pilha{
  struct Node* topo;
}pilha;

pilha *criaPilha(pilha *p){
  p->topo = NULL;
  return p;
}

void insere(int value, pilha *p){
  node *novo = (node*)malloc(sizeof(node));
  novo->chave = value;

  if(p->topo == NULL){
    novo->prox = NULL;
  }
  else{
    novo->prox = p->topo;
  }
  p->topo = novo;
}

void remover(pilha *p){
  node *temp = p->topo;

  if(temp == NULL){
    printf("Pilha vazia\n");
    return;
  }
  p->topo = p->topo->prox;
  free(temp);

}

void imprimir(pilha *p){
  node* aux = p->topo;

  while (aux != NULL) {
    printf("%d -> ",aux->chave);
    aux = aux->prox;
  }
  printf("\n");
}

int busca(pilha *p, int value){
  node *temp = p->topo;

  if(temp == NULL){
    printf("pilha vazia\n");
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
  pilha *P1 = (pilha*)malloc(sizeof(pilha));

  P1 = criaPilha(P1);
  insere(5, P1);
  insere(10, P1);
  insere(7, P1);
  imprimir(P1);
  remover(P1);
  imprimir(P1);

  aux = busca(P1, 5);
   if(aux == 1)
     printf("O elemento se encontra na Pilha\n");
   else
     printf("O elemento nao esta na pilha\n");

     remover(P1);
     imprimir(P1);

  printf("\n");

  return 0;
}
