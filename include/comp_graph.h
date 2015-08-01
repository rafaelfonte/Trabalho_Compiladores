/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/

//estuturas de dados temporárias 
typedef struct comp_graph_t grafo;

typedef struct aresta {
   grafo *link;
   struct aresta *prox;
} aresta;

typedef struct comp_graph_t {
   int info;
   struct comp_graph_t *prox;
   aresta *arestas;
} comp_graph_t;

//assinaturas das funções
int grafoVazio(comp_graph_t *Grafo);
comp_graph_t* grafoCria();
comp_graph_t* grafoCriaNodo(int info);
comp_graph_t* grafoAchaNodo(comp_graph_t *Grafo,int info);
void grafoInsereNodo(comp_graph_t *Grafo, comp_graph_t *novoNodo);
void grafoRemoveNodo(comp_graph_t *Grafo, comp_graph_t *Nodo);
void grafoInsereAresta(comp_graph_t *origem, comp_graph_t *destino);
void grafoRemoveAresta(comp_graph_t *origem, comp_graph_t *destino);
void grafoRemoveTodasArestas(comp_graph_t *Grafo, comp_graph_t *Nodo);
void grafoImprime(comp_graph_t *Grafo);

