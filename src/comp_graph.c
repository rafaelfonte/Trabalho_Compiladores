/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/

#include <stdlib.h>
#include <stdio.h>
#include "comp_graph.h"

//função que verifica se o grafo informado por parâmetro está vazio
int grafoVazio(comp_graph_t *Grafo) {
   return Grafo == NULL;
}

//função que inicializa um grafo - retorna um ponteiro NULL
comp_graph_t* grafoCria() {
   comp_graph_t *p;

   p = NULL;
   return p;
}

//função que cria uma aresta
aresta* grafoCriaAresta(comp_graph_t *link) {
   aresta *novaAresta;

   novaAresta = (aresta *) malloc(sizeof(aresta));

   novaAresta->link = link;
   novaAresta->prox = NULL;

   return novaAresta;
}


//função que cria um nodo do grafo
comp_graph_t* grafoCriaNodo(int info) {
   comp_graph_t *novoNodo;

   novoNodo = malloc(sizeof(comp_graph_t));

   novoNodo->info = info;
   novoNodo->prox = NULL;
   novoNodo->arestas = NULL;

   return novoNodo;
}

//função que insere um nodo no grafo. 
void grafoInsereNodo(comp_graph_t *Grafo, comp_graph_t *novoNodo) {
   comp_graph_t *aux = Grafo;

   //percorro o array de filhos desse grafo
   while (aux->prox != NULL) 
     aux = aux->prox;
   //cheguei na posição de inserção
   aux->prox = novoNodo;
   return;
}

//função que remove um nodo do grafo
void grafoRemoveNodo(comp_graph_t *Grafo, comp_graph_t *Nodo) {
   comp_graph_t *aux[2] = {NULL,Grafo};

   //verifico se é o nodo a ser removido
   if (aux[2] == Nodo)
   {
      //é, removo-o
      grafoRemoveTodasArestas(Grafo,aux[2]);
      Grafo = aux[2]->prox;
      free(aux[2]);
      return;
   } 
   //percorro a lista de nodos do grafo
   while (aux[2] != NULL) 
   {
     //verifico se achei o nodo
     if (aux[2] == Nodo)
     {
        //achei...removo-o
        grafoRemoveTodasArestas(Grafo,aux[2]);
        aux[1]->prox = aux[2]->prox;
        free(aux[2]);
        return;
     }
     aux[1] = aux[2];
     aux[2] = aux[2]->prox;
   }
   return;
}

//função que localiza um nodo pela informação
comp_graph_t* grafoAchaNodo(comp_graph_t *Grafo, int info) {
   comp_graph_t *aux = Grafo;

   //percorro a lista de nodos do grafo
   while (aux != NULL) 
   {
     //verifico se achei o nodo
     if (aux->info == info)
     {
        //achei...
        return aux;
     }
     aux = aux->prox;
   }
   return NULL;
}

//função que imprime um grafo
void grafoImprime(comp_graph_t *Grafo) {
   comp_graph_t *aux = Grafo;
   aresta *Aresta;

   //percorro a lista de nodos do grafo
   while (aux != NULL) 
   {
     printf("Nodo %d.\n",aux->info);
     Aresta = aux->arestas;
     while (Aresta != NULL)
     {
        printf("   Aresta para %d.\n",Aresta->link->info);
        Aresta = Aresta->prox;
     }
     aux = aux->prox;
   }
   return;
}

//função de insere uma aresta no grafo
void grafoInsereAresta(comp_graph_t *origem, comp_graph_t *destino) {
   aresta *arestaOrigem[2] = {NULL,origem->arestas};
   aresta *arestaDestino[2] = {NULL,destino->arestas};
   int achei = 0;

   //verifico se tem alguma aresta 
   if (origem->arestas == NULL)
   {
      //é a primeira
      origem->arestas = grafoCriaAresta(destino);
      achei = 1;
   }
   //percorro as arestas da origem
   while ((arestaOrigem[2] != NULL) && (achei != 1)) 
   {
      //verifico se é o link para o destino
      if (arestaOrigem[2]->link == destino)
         //essa aresta já existe
         achei = 1;
      arestaOrigem[1] = arestaOrigem[2];
      arestaOrigem[2] = arestaOrigem[2]->prox;
   }
   //verifico se achei o vértice
   if (achei == 0) 
   {
      //não achei...insiro
      arestaOrigem[1]->prox = grafoCriaAresta(destino);
   }
   achei = 0;
   //verifico se tem alguma aresta 
   if (destino->arestas == NULL)
   {
      //é a primeira
      destino->arestas = grafoCriaAresta(origem);
      achei = 1;
   }
   //percorro as arestas do destino
   while ((arestaDestino[2] != NULL) && (achei != 1)) 
   {
      //verifico se é o link para a origem
      if (arestaDestino[2]->link == origem)
         //essa aresta já existe
         achei = 1;
      arestaDestino[1] = arestaDestino[2];
      arestaDestino[2] = arestaDestino[2]->prox;
   }
   //verifico se achei o vértice
   if (achei == 0) 
   {
      //não achei...insiro
      arestaDestino[1]->prox = grafoCriaAresta(origem);
   }
   return;
}

//função que remove uma aresta do grafo
void grafoRemoveAresta(comp_graph_t *origem, comp_graph_t *destino) {
   aresta *arestaOrigem[2] = {NULL,origem->arestas};
   aresta *arestaDestino[2] = {NULL,destino->arestas};
   int achei = 0;

   //verifico se tem alguma aresta 
   if (origem->arestas->link == destino)
   {
      //é a primeira
      origem->arestas = origem->arestas->prox;
      free(arestaOrigem[2]);
      achei = 1;
   }
   //percorro as arestas da origem
   while ((arestaOrigem[2] != NULL) && (achei != 1)) 
   {
      //verifico se é o link para o destino
      if (arestaOrigem[2]->link == destino)
      {
         //achei a aresta, removo-a
         arestaOrigem[1]->prox = arestaOrigem[2]->prox;
         free(arestaOrigem[2]);
         achei = 1;
      }
      arestaOrigem[1] = arestaOrigem[2];
      arestaOrigem[2] = arestaOrigem[2]->prox;
   }
   achei = 0;
   if (destino->arestas->link == origem)
   {
      //é a primeira
      destino->arestas = destino->arestas->prox;
      free(arestaDestino[2]);
      achei = 1;
   }
   //percorro as arestas do destino
   while ((arestaDestino[2] != NULL) && (achei != 1)) 
   {
      //verifico se é o link para a origem
      if (arestaDestino[2]->link == origem)
      {
         //achei a aresta, removo-a
         arestaDestino[1]->prox = arestaDestino[2]->prox;
         free(arestaDestino[2]);
         achei = 1;
      }
      arestaDestino[1] = arestaDestino[2];
      arestaDestino[2] = arestaDestino[2]->prox;
   }
   return;
}

//função que remove todas as arestas de um nodo
void grafoRemoveTodasArestas(comp_graph_t *Grafo, comp_graph_t *Nodo) {
   comp_graph_t *aux = Grafo;
   aresta *arestas[2] = {NULL,aux->arestas};
   int achei = 0;

   //verifico se a primeira aresta já é para o nodo alvo
   if (aux->arestas->link == Nodo)
   {
      //sim. removo-a
      aux->arestas = aux->arestas->prox;
      free(arestas[2]);
      achei = 1;
   }
   //percorro as arestas do Nodo em processamento
   while ((arestas[2] != NULL) && (achei != 1)) 
   {
      //verifico se é o link para o nodo
      if (arestas[2]->link == Nodo)
      {
         //achei a aresta, removo-a
         arestas[1]->prox = arestas[2]->prox;
         free(arestas[2]);
         achei = 1;
      }
      arestas[1] = arestas[2];
      arestas[2] = arestas[2]->prox;
   }
   //processo para o próximo nodo
   grafoRemoveTodasArestas(aux->prox,Nodo);
   return;
}
