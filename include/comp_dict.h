/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva 
*/

//estuturas de dados temporárias 
typedef struct {
   char *chave;
   int tipo;
   int simbolo;
   int lineNumber;
   //ETAPA 4
   int tipo_dado;	//Tipo do dado.
   int tipo_estrutura;	//Tipo de estrutura: vetor ou variavel
   int tamanho;		//Tamanho total do dado.

//ETAPA 5
   int escopo_eh_global;
   int endereco;


   struct comp_list_t* lista_tamanhos_dimensao;//Lista com tamanhos das dimensoes de arranjos.
   struct comp_list_t* lista_args_funcao;//Lista de argumentos e tipos deles para funcoes.
   struct comp_dict_item_t *prox;
} comp_dict_item_t;

typedef struct {
   int info;
   comp_dict_item_t *Itens;
} comp_dict_t;


//assinatura das funções
int dicionarioExiste(comp_dict_t *Dicionario);
comp_dict_t* dicionarioCria(int info);
comp_dict_item_t* dicionarioCriaItem(char *chave,int numLinha,int intTipo,int intSimbolo);
void dicionarioInsereItem(comp_dict_t *Dicionario, comp_dict_item_t *novoItem);
int dicionarioProcuraChave(comp_dict_t *Dicionario, char *Chave);
void dicionarioRemoveChave(comp_dict_t *Dicionario, char *Chave);
void dicionarioRemove(comp_dict_t **Dicionario);
void dicionarioImprime(comp_dict_t *Dicionario);
int dicionarioQtdeItens(comp_dict_t *Dicionario);
void dicionarioAtualizaLinha(comp_dict_t *Dicionario, char *chave, int novoValor);


comp_dict_item_t* dicionarioRetornaChave(comp_dict_t *Dicionario, char *Chave);
