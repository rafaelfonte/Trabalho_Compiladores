/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/

#include <stdlib.h>
#include <stdio.h>
#include "comp_list.h"

//função que verifica se a lista informada por parâmetro está vazia
int listaVazia(comp_list_t *Lista) {
   return Lista == NULL;
}

//função que retorna a qtde de nodos da lista
int listaQtdeNodos(comp_list_t *Lista) {
   int cont = 0;
   comp_list_t *aux = Lista;

   //verifico se a lista está vazia
   if (listaVazia(aux) == 1)
      return cont;
   //tem, pelo menos, 1 nodo
   cont = cont + 1;
   //percorro o restante da lista
   while (aux->prox != NULL)
   {
      //incremento o contador
      cont = cont + 1;
      //avanço na lista
      aux = aux->prox;
   }
   //retorno a qtde de nodos na lista
   return cont;
}

//função que retorna nodo de uma lista indexado por um argumento
comp_list_t* listaRetornaNodoIdx(comp_list_t *Lista,int idx) {
   int cont = 0;
   comp_list_t *aux = Lista;

   //verifico se a lista está vazia
   if (listaVazia(aux) == 1 || idx < 0)
      return NULL;
   //percorro o restante da lista
   while (aux->prox != NULL && idx != cont)
   {
      //incremento o contador
      cont = cont + 1;
      //avanço na lista
      aux = aux->prox;
   }
   if(idx == cont && aux != NULL)
	return aux;
   //nao achou o termo...
   return NULL;
}

//função que inicializa uma lista - retorna um ponteiro NULL
comp_list_t* listaCria() {
   comp_list_t *p;

   p = NULL;
   return p;
}

//função que cria um nodo da lista
comp_list_t* listaCriaNodo(int info) {
   comp_list_t *novoNodo;

   novoNodo = malloc(sizeof(comp_list_t));

   novoNodo->info = info;
   novoNodo->prox = NULL;
   novoNodo->prev = NULL;

   return novoNodo;
}

//função que insere um nodo no final da lista.
void listaInsereNodo(comp_list_t **Lista, comp_list_t *novoNodo) {
   comp_list_t *aux = *Lista;

   //verifico se a lista está vazia
   if (listaVazia(aux) == 1)
   {
      *Lista = novoNodo;
      return;
   } 
   //percorro a lista
   while (aux->prox != NULL) 
   {
      //avanço na lista...
      aux = aux->prox;
   }
   //adiciono o novo nodo no final da lista
   aux->prox = novoNodo;
   novoNodo->prev = aux;
   return;
}

//função que remove um nodo da lista
void listaRemoveNodo(comp_list_t *Lista, int info) {
   comp_list_t *aux[2] = {NULL,Lista};

   //verifico se a lista está vazia
   if (listaVazia(Lista) == 1)
      return;
   //verifico se é o primeiro nodo a ser removido e se só tem 1 na lista
   if (aux[1]->info == info) 
   {
      if (listaQtdeNodos(Lista) == 1)      
         Lista = NULL;
      else
         Lista = aux[1]->prox;
      free(aux[1]);
      return;
   }
   //percorro a lista
   while (aux[1] != NULL) 
   {
      //verifico se é o nodo a ser removido
      if (aux[1]->info == info) 
      {
         //achei...faço os ajustes necessários
         aux[0]->prox = aux[1]->prox;
         aux[1]->prox->prev = aux[1]->prev;
         free(aux[1]);
         return;
      }
      else
      {
         //avanço na lista...
         aux[0] = aux[1];
         aux[1] = aux[1]->prox;
      }
   }
   //não achei o nodo na lista
   return;
}

//função que remove um nodo da lista - retorna 0 se deu erro e 1 se deu certo
void listaImprime(comp_list_t *Lista) {
   comp_list_t *aux;

   aux = Lista;
   //verifico se a lista está vazia
   if (listaVazia(aux) == 1)
      return;
   //percorro a lista
   while (aux != NULL) 
   {
      //imprimo aux
      printf("Imprimindo o nodo %d.\n",aux->info);
      aux = aux->prox;
   }
   return;
}

//função que concatena duas listas
comp_list_t* listaConcatena(comp_list_t *Lista1, comp_list_t *Lista2) {
   comp_list_t *aux;

   //verifico se a lista1 está vazia
   if (listaVazia(Lista1) == 1)
      return Lista2;
   //verifico se a lista2 está vazia
   if (listaVazia(Lista2) == 1)
      return Lista1;
   aux = Lista1;
   //percorro a lista 1
   while (aux->prox != NULL) 
   {
         //avanço na lista...
         aux = aux->prox;
   }
   //concateno as listas
   aux->prox = Lista2;
   Lista2->prev = aux;
   return Lista1;
}







//função que insere um nodo no inicio da lista.
comp_list_t* listaAdicionaNodo_Inicio(comp_list_t *Lista, comp_list_t* novoNodo) {
   comp_list_t *aux = Lista;

   //verifico se a lista está vazia
   if (listaVazia(aux) == 1)
   {
      return novoNodo;
   } 
 
   //adiciono o novo nodo no inicio da lista
   aux->prev = novoNodo;
   novoNodo->prox = aux;
   return novoNodo;
}


//funcao que calcula o produto dos elementos da lista.
int listaCalculaProduto(comp_list_t* Lista){
	int resultado = 1;
	while(Lista != NULL){
		resultado = resultado * (Lista->info);
		Lista = Lista->prox;
	}
	return resultado;
}
