#include <stdio.h>
#include <stdlib.h>

//representa um "nó" da lista
struct Node{
  int dado;
  struct Node *prox;
};
typedef struct Node node;

//função que percorre e imprime os elementos da lista
void imprime (node* lista){
 node* aux; /* variável auxiliar para percorrer a lista */
 for (aux = lista; aux != NULL; aux = aux->prox)
 printf("%d\n", aux->dado);
}

//função que insere um valor no início da lista e retorna a lista atualizada
node* insere (node* lista, int aux){
 node* novo = (node*) malloc(sizeof(node)); //aloca o espaço para armazenar a lista
 novo->dado = aux; // guarda a informação do novo nó
 novo->prox = lista; // aponta para o proximo nó da lista
 return novo; // retorna o novo valor que representa o novo primeiro elemento da lista
}

// função que insere ordenado
node* insereOrdenado(node* lista, int valor){
  node* novo = (node*)malloc(sizeof(node));
  node* ant = NULL; // guarda o elemento anterior
  node* temp = lista;// ponteiro para percorrer a lista

  novo->dado = valor;

  while (temp != NULL && valor > temp->dado) { // percorre a lista para achar a posição certa para o novo elemento
      ant = temp;
      temp = temp->prox;
  }

  if(ant == NULL){ //insere no inicio
    novo->prox = lista;
    lista = novo;
  }
  else{ // insere no meio ou fim da lista
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  return lista;
}
//função que busca um elemento na lista
node* busca(node* lista, int valor){
  node* aux;
  for(aux = lista; aux != NULL; aux = aux->prox)
    if(aux->dado == valor)
      return aux;
  return NULL; //retorna null caso não ache o elemento
}

//função que remove um elemento da lista
node* retira(node* lista, int valor){
  node* anterior = NULL; // ponteiro para o elemento anterior
  node* aux = lista; // variavel auxiliar p/ percorrer a lista

  // procura um elemento na lista e guarda o anterior
  while (aux != NULL && aux->dado != valor) {
    anterior = aux;
    aux = aux->prox;
  }
  //verifica se o elemento existe na lista
  if(aux == NULL) return lista;

  // retira o elemento
  if(anterior == NULL){
    lista = aux->prox; // retira elemento do inicio
  }
  else{
    anterior->prox = aux->prox; //retira do meio
  }
  free(aux);
  return lista;
}

//função p/ liberar a memoria alocada
void freeList(node* lista){
  node* aux = lista;
  while (aux != NULL) {
    node* temp  = aux->prox; // guarda a referencia p/ o proximo elemento
    free(aux); // libera a memoria
    aux = temp; // aux aponta para o proximo
  }
}

int main (){
  node* list; //lista não inicializada
  list = NULL;
  // list = insere(list, 1);
  // list = insere(list, 2);
  // list = insere(list, 3);
  // list = insere(list, 4);
  // imprime(list);
  // printf("busca de elemento: %d\n",*busca(list,3));
  // list = retira(list, 4);
  list = insereOrdenado(list, 9);
  list = insereOrdenado(list, 4);
  list = insereOrdenado(list, 2);
  list = insereOrdenado(list, 10);
  list = insereOrdenado(list, 7);
  imprime(list);
  freeList(list);
 return 0;
}
