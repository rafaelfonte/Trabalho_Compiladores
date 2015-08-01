/*
  main.h

  Cabeçalho principal do analisador sintático
*/
#ifndef __MAIN_H
#define __MAIN_H
#include <stdio.h>
#include "comp_dict.h"
#include "comp_list.h"
#include "comp_tree.h"
#include "comp_graph.h"
#include "iks_ast.h"
#include "Programa_ILOC.h"
#include "gv.h"

/*
  Constantes a serem utilizadas como valor de retorno no caso de
  sucesso (IKS_SYNTAX_SUCESS) e erro (IKS_SYNTAX_ERRO) do analisador
  sintático.
*/
#define IKS_SYNTAX_SUCESSO 0
#define IKS_SYNTAX_ERRO    1

/*
  Constantes a serem utilizadas para diferenciar os lexemas que estão
  registrados na tabela de símbolos.
*/
#define IKS_SIMBOLO_INT             1
#define IKS_SIMBOLO_FLOAT           2
#define IKS_SIMBOLO_CHAR            3
#define IKS_SIMBOLO_STRING          4
#define IKS_SIMBOLO_BOOL            5
#define IKS_SIMBOLO_IDENTIFICADOR   6



/*********
 ETAPA - 4
**********/
/*
 * Códigos de tipos - Etapa 4.
 */
/*
 * Definicao de codigos para os tipos de dados. No caso de funcoes, eh utilizado para determinar o valor de retorno.
 */

#define IKS_INT		1
#define IKS_FLOAT	2
#define IKS_CHAR	3
#define IKS_STRING	4
#define IKS_BOOL	5

/*
 * Definição do tipo do identificador (variável simples, vetor ou funcao).
 */
#define IKS_TYPE_VARIABLE	1
#define IKS_TYPE_VECTOR		2
#define IKS_TYPE_FUNCTION	3
/*
 * Tamanhos dos tipos de dados primitivos (em bytes).
 */

#define IKS_SIZE_CHAR			1
#define IKS_SIZE_BOOL			1
#define IKS_SIZE_INT			4	
#define IKS_SIZE_FLOAT			8

/*
 * Macro que define os tamanho de strings.
 */
#define IKS_SIZE_STRING(L)		L*IKS_SIZE_CHAR

/*
 * Macros que definem os tamanhos de vetores.
 */
//Vetor de strings, caso entre no escopo do trabalho.
#ifdef __STRING_VECTOR_ENABLED
	#define IKS_SIZE_VECTOR_STRING(S,L)	S*IKS_SIZE_STRING(L)
#endif

#define IKS_SIZE_VECTOR_CHAR(L)		L*IKS_SIZE_CHAR
#define IKS_SIZE_VECTOR_BOOL(L)		L*IKS_SIZE_BOOL
#define IKS_SIZE_VECTOR_INT(L)		L*IKS_SIZE_INT
#define IKS_SIZE_VECTOR_FLOAT(L)	L*IKS_SIZE_FLOAT


/*
 * Códigos de retorno para erros semânticos - Etapa 4.
 */

#define IKS_SUCCESS			 0	//caso não houver nenhum tipo de erro

/*1 - Verificação de declarações */
#define IKS_ERROR_UNDECLARED		 1	//identificador não declarado
#define IKS_ERROR_DECLARED		 2	//identificador já declarado

/*2 - Uso correto de identificadores */
#define IKS_ERROR_VARIABLE		 3	//identificador deve ser utilizado como variável
#define IKS_ERROR_VECTOR		 4	//identificador deve ser utilizado como vetor
#define IKS_ERROR_FUNCTION		 5	//identificador deve ser utilizado como função

/*3 - Tipos e tamanho de dados */
#define IKS_ERROR_WRONG_TYPE		 6	//tipos incompatíveis
#define IKS_ERROR_STRING_TO_X		 7	//coerção impossível do tipo string
#define IKS_ERROR_CHAR_TO_X		 8	//coerção impossível do tipo char

/*4 - Argumentos e parâmetros */
#define IKS_ERROR_MISSING_ARGS		 9	//faltam argumentos
#define IKS_ERROR_EXCESS_ARGS		10	//sobram argumentos
#define IKS_ERROR_WRONG_TYPE_ARGS	11	//argumentos incompatíveis

/*5 - Verificação de tipos em comandos */
#define IKS_ERROR_WRONG_PAR_INPUT	12	//parâmetro não é identificador
#define IKS_ERROR_WRONG_PAR_OUTPUT	13	//parâmetro não é literal string ou expressão
#define IKS_ERROR_WRONG_PAR_RETURN	14	//parâmetro não é expressão compatível com tipo do retorno


#define IKS_ERROR_DIM_NOT_POSITIVE	15	//Dimensao informada nao eh positiva

#define IKS_FATAL_ERROR			666	//154, ja que a saida eh um inteiro de 1 byte.

extern int yylileno;
extern comp_dict_t *dicionario_atual;
extern comp_dict_t *dicionario_escopo_global;
extern int escopo_eh_local;
extern int passou_declaracoes_funcao;
extern int com_eh_input;//Pela forma como construiu-se o parser, devemos realizar esta verificacao no scanner.

//Etapa 5
extern int escopo_id_eh_global;

#endif
