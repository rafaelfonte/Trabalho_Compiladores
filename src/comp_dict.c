/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/comp_dict.h"

//função que verifica se o dicionário informado por parâmetro está vazio
int dicionarioExiste(comp_dict_t *Dicionario) {
   if (Dicionario == 0)
    {
//      printf("Não existe o dicionário\n");
      return 0;
    }
   else
    {
//      printf("Existe o dicionário\n");
      return 1;
    }
}

//função que inicializa um dicionário - retorna um ponteiro NULL
comp_dict_t* dicionarioCria(int info) {
   comp_dict_t *p;

   p = malloc(sizeof(comp_dict_t));

   p->info = info;
   p->Itens = NULL;
   return p;
}

//função que cria um novo item de dicionário
comp_dict_item_t* dicionarioCriaItem(char *chave,int numLinha,int intTipo,int intSimbolo) {
   comp_dict_item_t *novoItem;
   char *strAux;

   strAux = (char*) calloc (strlen(chave)-1, sizeof(char));      

//   printf("Aux antes da copia %s\n",strAux);

   int i = 0;
   int j = 0;   
   for(i = 0; i < strlen(chave);i++)
      {
        strAux[j] = chave[i];
        j++;      
      }

   novoItem = malloc(sizeof(comp_dict_item_t));

//   printf("Aux depois da copia %s\n",strAux);
   novoItem->chave = strAux;
   novoItem->lineNumber = numLinha;
   novoItem->tipo = intTipo;
   novoItem->simbolo = intSimbolo;
   novoItem->prox = NULL;
   novoItem->lista_args_funcao = NULL;
   novoItem->lista_tamanhos_dimensao = NULL;
   novoItem->tamanho = 0;

   return novoItem;
}

//função que insere um novo item no dicionario
void dicionarioInsereItem(comp_dict_t *Dicionario, comp_dict_item_t *novoItem) {
   comp_dict_item_t *aux[2] = {NULL,Dicionario->Itens};

   //verifico se o dicionário está vazio
   if (aux[1] == NULL)
   {
      Dicionario->Itens = novoItem;
      return;
   } 
   //percorro a lista de itens do dicionário
   while (aux[1] != NULL) 
   {
      //avanço na lista...
      aux[0] = aux[1];
      aux[1] = aux[1]->prox;
   }
   //adiciono o novo nodo no final da lista
   aux[1] = novoItem;
   aux[0]->prox = aux[1];
//   dicionarioImprime (Dicionario);
   return;
}

//função que verifica se uma chave já consta no dicionário. Retorna 0 se não existe e 1 se existir
int dicionarioProcuraChave(comp_dict_t *Dicionario, char *Chave) {
   comp_dict_item_t *aux = Dicionario->Itens;

   //percorro a lista de itens do dicionário
   while (aux != NULL) 
   {
      //verifico se achei a chave
      //if (aux->chave == Chave)
//      printf("Comparando '%s' com '%s'\n",Chave,aux->chave);
      if (strcmp(aux->chave,Chave) == 0)
         //achei...
         return 1;
      aux = aux->prox;
   }
   //se cheguei aqui é porque não achei
   return 0;
}

//função que verifica se uma chave consta no dicionário. Retorna  o item
comp_dict_item_t* dicionarioGetItem(comp_dict_t *Dicionario, char *Chave) {
   comp_dict_item_t *aux = Dicionario->Itens;

   //percorro a lista de itens do dicionário
   while (aux != NULL) 
   {
      //verifico se achei a chave
      //if (aux->chave == Chave)
      if (strcmp(aux->chave,Chave) == 0)
         //achei...
         return aux;
      aux = aux->prox;
   }
   //se cheguei aqui é porque não achei
   return NULL;
}

//função que atualiza o número da linha de um identificador
void dicionarioAtualizaLinha(comp_dict_t *Dicionario, char *chave, int novoValor) {
   comp_dict_item_t *aux = dicionarioGetItem(Dicionario,chave);

   if (aux != NULL)
      aux->lineNumber = novoValor;
   return;
}


//função que remove uma chave do dicionário
void dicionarioRemoveChave(comp_dict_t *Dicionario, char *Chave) {
   comp_dict_item_t *aux[2] = {NULL,Dicionario->Itens};

   //verifico se a chave consta no dicionário
   if (dicionarioProcuraChave(Dicionario,Chave) == 0)
      //a chave não consta no dicionário
      return;
   //verifico se é o primeiro item da lista
   if (Dicionario->Itens->chave == Chave) 
   {
      //é o primeiro, já resolvo aqui mesmo
      Dicionario->Itens = Dicionario->Itens->prox;
      free(aux[1]);
      return;
   }
   //percorro a lista de itens do dicionário
   while (aux[1] != NULL) 
   {
      //verifico se achei a chave
      if (aux[1]->chave == Chave)
      {
         //achei...removo
         aux[0]->prox = aux[1]->prox;
         free(aux[1]); 
         return;
      }
      aux[0] = aux[1];
      aux[1] = aux[1]->prox;
   }
   return;
}

//função que remove todas as chaves do dicionário
void dicionarioRemoveTodasChaves(comp_dict_t *Dicionario) {
   //vou removendo o primeiro item até acabar a lista
   while (Dicionario->Itens != NULL) 
      dicionarioRemoveChave(Dicionario,Dicionario->Itens->chave);
   return;
}

//função que remove um dicionário (e seus itens primeiro)
void dicionarioRemove(comp_dict_t **Dicionario) {
   if(*Dicionario == NULL)
	return;
   comp_dict_item_t *aux = (*Dicionario)->Itens;

   //removo os itens do dicionário
   dicionarioRemoveTodasChaves(*Dicionario);
   //removo o dicionário
   free(*Dicionario);
   *Dicionario = NULL;
   return;
}

//função que imprime os dados de um dicionário
void dicionarioImprime(comp_dict_t *Dicionario) {
    if(Dicionario == NULL){
        printf("Dicionario vazio!\n");
        return;
    }
    comp_dict_item_t *aux = Dicionario->Itens;

   //info do dicionário
   printf("Dicionario de info %d\n",Dicionario->info);
   //percorro os itens do dicionario
   while (aux != NULL)
   {
      printf("Imprimindo item %s, token %d na linha %d\n",aux->chave,aux->tipo,aux->lineNumber); 
      aux = aux->prox;
   }
   printf("Fim da impressão do dicionario.\n");
   return;
}

//função que retorna a qtde de itens no dicionário
int dicionarioQtdeItens(comp_dict_t *Dicionario) {
   comp_dict_item_t *aux = Dicionario->Itens;
   int qtde = 0;

   //info do dicionário
   printf("Dicionario de info %d\n",Dicionario->info);
   //percorro os itens do dicionario
   while (aux != NULL)
   {
      qtde = qtde + 1;
      aux = aux->prox;
   }
   return qtde;
}





comp_dict_item_t* dicionarioRetornaChave(comp_dict_t *Dicionario, char *Chave){
	return dicionarioGetItem(Dicionario, Chave);
}
