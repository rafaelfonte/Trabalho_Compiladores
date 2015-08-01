/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/

//estuturas de dados temporárias 
typedef struct comp_list_t {
   int info;
   struct comp_list_t* prox;
   struct comp_list_t* prev;
} comp_list_t;

//assinaturas das funções
int listaVazia(comp_list_t *Lista);
int listaQtdeNodos(comp_list_t *Lista);
comp_list_t* listaRetornaNodoIdx(comp_list_t *Lista,int idx);
comp_list_t* listaCria();
comp_list_t* listaCriaNodo(int info);
void listaInsereNodo(comp_list_t **Lista, comp_list_t *novoNodo);//Adiciona ao final da lista
void listaRemoveNodo(comp_list_t *Lista, int info);
comp_list_t* listaConcatena(comp_list_t *Lista1, comp_list_t *Lista2);
void listaImprime(comp_list_t *Lista);



comp_list_t* listaAdicionaNodo_Inicio(comp_list_t *Lista,comp_list_t* novoNodo);

int listaCalculaProduto(comp_list_t* Lista);
