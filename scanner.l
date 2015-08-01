%{
/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/

#include <stdlib.h>
#include "main.h"
#include "parser.h"

comp_dict_item_t *itemDic;

int getLineNumber(void);
void initDicionario(void);
inline int procura_dic(comp_dict_t* dic, char * chave);
inline void add_item_dicionario(comp_dict_t* dic);
inline void referenciar_dicionario(comp_dict_t* dic);
inline void testa_erro_input();

%}

DIGIT 		[0-9]
ID 		[a-zA-Z_]([a-zA-Z_]|{DIGIT})*
LIT_INT 	{DIGIT}+
LIT_FLOAT 	{LIT_INT}"."{DIGIT}+
LIT_FALSE 	false
LIT_TRUE 	true
LIT_CHAR 	'(\\.|[^\\'])+\'
LIT_STRING 	\"(\\.|[^\\"])*\"

%x comentario
%x comentario1

%%
"/*"         BEGIN(comentario);

<comentario>[^*\n]*        /* consome qualquer coisa que não seja '*' */
<comentario>"*"+[^*/\n]*   /* consome todos os '*' que não são seguidos de '/' */
<comentario>\n             ++yylineno;
<comentario>"*"+"/"        BEGIN(INITIAL);

"//"         BEGIN(comentario1);

<comentario1>[^\n]*        /* consome qualquer coisa que não seja '/' */
<comentario1>\n            ++yylineno;BEGIN(INITIAL);

[ \t\r]		/* espaços */

int 		{ return TK_PR_INT; }
float 		{ return TK_PR_FLOAT; }
bool 		{ return TK_PR_BOOL; }
char 		{ return TK_PR_CHAR; }
string 		{ return TK_PR_STRING; }
if 		{ return TK_PR_IF; }
then 		{ return TK_PR_THEN; }
else 		{ return TK_PR_ELSE; }
while 		{ return TK_PR_WHILE; }
do 		{ return TK_PR_DO; }
input 		{ return TK_PR_INPUT; }
output 		{ return TK_PR_OUTPUT; }
return 		{ return TK_PR_RETURN; }

[,:\(\)+*/<>!&$] { return yytext[0]; }
[\}] { return yytext[0]; }
[\{] { return yytext[0]; }
[\]] { return yytext[0]; }
[\[] { return yytext[0]; }
[;] { return yytext[0]; }
[-] { return yytext[0]; }
[=] { return yytext[0]; }

"<=" 		{ return TK_OC_LE; }
">=" 		{ return TK_OC_GE; }
"==" 		{ return TK_OC_EQ; }
"!=" 		{ return TK_OC_NE; }
"&&" 		{ return TK_OC_AND; }
"||" 		{ return TK_OC_OR; }
"\n"		{ ++yylineno; }

{LIT_STRING} 	{	
			testa_erro_input();
			if (!dicionarioExiste(dicionario_atual))
				initDicionario();
                        if(dicionarioProcuraChave(dicionario_atual,yytext) == 0)
			{
				itemDic = dicionarioCriaItem(yytext,yylineno,TK_LIT_STRING,IKS_SIMBOLO_STRING);
				yylval.symbol = itemDic;
				dicionarioInsereItem(dicionario_atual,itemDic);
				itemDic->tipo_dado = IKS_STRING;
				return TK_LIT_STRING;
			} else 
			{
				yylval.symbol = dicionarioRetornaChave(dicionario_atual,yytext);
				dicionarioAtualizaLinha(dicionario_atual,yytext,yylineno);
				return TK_LIT_STRING; 
			}
		}


{LIT_INT} 	{
			testa_erro_input();
			if (!dicionarioExiste(dicionario_atual))
				initDicionario();
			if(dicionarioProcuraChave(dicionario_atual,yytext) == 0)
			{
				itemDic = dicionarioCriaItem(yytext,yylineno,TK_LIT_INT,IKS_SIMBOLO_INT);
				yylval.symbol = itemDic;
				dicionarioInsereItem(dicionario_atual,itemDic);
				itemDic->tipo_dado = IKS_INT;
				return TK_LIT_INT;
			} else 
			{
				yylval.symbol = dicionarioRetornaChave(dicionario_atual,yytext);
				dicionarioAtualizaLinha(dicionario_atual,yytext,yylineno);
				return TK_LIT_INT; 
			}
		}
			
{LIT_FLOAT} 	{
			testa_erro_input();
			if (!dicionarioExiste(dicionario_atual))
				initDicionario();
			if(dicionarioProcuraChave(dicionario_atual,yytext) == 0)
			{
				itemDic = dicionarioCriaItem(yytext,yylineno,TK_LIT_FLOAT,IKS_SIMBOLO_FLOAT);
				yylval.symbol = itemDic;
				dicionarioInsereItem(dicionario_atual,itemDic);
				itemDic->tipo_dado = IKS_FLOAT;
				return TK_LIT_FLOAT;
			} else 
			{
				yylval.symbol = dicionarioRetornaChave(dicionario_atual,yytext);
				dicionarioAtualizaLinha(dicionario_atual,yytext,yylineno);
				return TK_LIT_FLOAT; 
			}
		}
			
{LIT_FALSE} 	{
			testa_erro_input();
			if (!dicionarioExiste(dicionario_atual))
				initDicionario();
			if(dicionarioProcuraChave(dicionario_atual,yytext) == 0)
			{
				itemDic = dicionarioCriaItem(yytext,yylineno,TK_LIT_FALSE,IKS_SIMBOLO_BOOL);
				yylval.symbol = itemDic;
				dicionarioInsereItem(dicionario_atual,itemDic);
				itemDic->tipo_dado = IKS_BOOL;
				return TK_LIT_FALSE;
			} else 
			{
				yylval.symbol = dicionarioRetornaChave(dicionario_atual,yytext);
				dicionarioAtualizaLinha(dicionario_atual,yytext,yylineno);				
				return TK_LIT_FALSE; 
			}
		}
			
{LIT_TRUE} 	{
			testa_erro_input();
			if (!dicionarioExiste(dicionario_atual))
				initDicionario();
			if(dicionarioProcuraChave(dicionario_atual,yytext) == 0)
			{
				itemDic = dicionarioCriaItem(yytext,yylineno,TK_LIT_TRUE,IKS_SIMBOLO_BOOL);
				yylval.symbol = itemDic;
				dicionarioInsereItem(dicionario_atual,itemDic);
				itemDic->tipo_dado = IKS_BOOL;
				return TK_LIT_TRUE;
			} else 
			{
				yylval.symbol = dicionarioRetornaChave(dicionario_atual,yytext);
				dicionarioAtualizaLinha(dicionario_atual,yytext,yylineno);				
				return TK_LIT_TRUE; 
			}
		}
			
{LIT_CHAR} 	{
			testa_erro_input();
			if (!dicionarioExiste(dicionario_atual))
				initDicionario();
			if(dicionarioProcuraChave(dicionario_atual,yytext) == 0)
			{
				itemDic = dicionarioCriaItem(yytext,yylineno,TK_LIT_CHAR,IKS_SIMBOLO_CHAR);
				yylval.symbol = itemDic;
				dicionarioInsereItem(dicionario_atual,itemDic);
				itemDic->tipo_dado = IKS_CHAR;
				return TK_LIT_CHAR;
			} else 
			{
				yylval.symbol = dicionarioRetornaChave(dicionario_atual,yytext);
				dicionarioAtualizaLinha(dicionario_atual,yytext,yylineno);				
				return TK_LIT_CHAR; 
			}
		}
			
{ID} 		{
			//if(com_eh_input) //Nao precisaria desse 'if'
				com_eh_input = 0;
			if (!dicionarioExiste(dicionario_atual))
				initDicionario();
			switch(escopo_eh_local){
				case 1:{
					if(!passou_declaracoes_funcao){//Declaracao variavel local/parametro
						if(procura_dic(dicionario_atual,yytext) == 0)//Procura item no dicionario local, nao deve achar...
						{
							add_item_dicionario(dicionario_atual);
						} else {
							exit(IKS_ERROR_DECLARED);//Encontrou algo, eh uma redeclaracao.
						}
					} else{//Esta no escopo da funcao, mas ja passou pelas declaracoes de parametros/variaveis locais
						//TODO: procura no dicionario local. Se nao estiver la, procura no global. Se nao estiver la, ERRO!
						if(procura_dic(dicionario_atual,yytext) != 0)//Esta no local
						{
							referenciar_dicionario(dicionario_atual);
						} else {
							if(procura_dic(dicionario_escopo_global,yytext) != 0)//Esta no global
								referenciar_dicionario(dicionario_escopo_global);
							else{
								exit(IKS_ERROR_UNDECLARED);//Variavel referenciada nao foi declarada...
                            }
						}
					}
					break;
				}
				case 0:{//Referencia no escopo global -> dicionario_atual eh o global
                    if(procura_dic(dicionario_atual,yytext) == 0){//Caso bom, nao eh uma redeclaracao...
						add_item_dicionario(dicionario_atual);//dicionario_atual eh o global, gracas ao parser
                        dicionario_escopo_global = dicionario_atual;
                        //printf("Adicionou %s, %p.\n", yytext,dicionario_atual);
                        //dicionarioImprime(dicionario_atual);
                    }
					else//Caso ruim, achou algo, redeclaracao.
						exit(IKS_ERROR_DECLARED);//Esta havendo uma redeclaracao, eh um erro!					
					break;
				}
				default:{//Caso inalcancavel...
					fprintf(stderr,"Erro impossivel, como?\n");
					exit(IKS_FATAL_ERROR);
				}
			};
			return TK_IDENTIFICADOR;
/*//Matido para lembrar como era...
			if(dicionarioProcuraChave(dicionario_atual,yytext) == 0)
			{
				itemDic = dicionarioCriaItem(yytext,yylineno,TK_IDENTIFICADOR,IKS_SIMBOLO_IDENTIFICADOR);
				yylval.symbol = itemDic;
				dicionarioInsereItem(dicionario_atual,itemDic);	
				return TK_IDENTIFICADOR;
			} else 
			{	
				yylval.symbol = dicionarioRetornaChave(dicionario_atual,yytext);
				dicionarioAtualizaLinha(dicionario_atual,yytext,yylineno);
                                return TK_IDENTIFICADOR;
			}
*/
		}

<<EOF>>		{return TOKEN_EOF;}

. { printf("Erro\n"); return TOKEN_ERRO; }
%%

int getLineNumber(void)
{
	return yylineno;
}

void initDicionario(void)
{
   int token = 0;
   dicionario_atual = dicionarioCria(token);
}

inline int procura_dic(comp_dict_t* dic, char * chave){
	return 	dicionarioProcuraChave(dic,chave);
}

inline void add_item_dicionario(comp_dict_t* dic){
	itemDic = dicionarioCriaItem(yytext,yylineno,TK_IDENTIFICADOR,IKS_SIMBOLO_IDENTIFICADOR);
	yylval.symbol = itemDic;
	
	itemDic->escopo_eh_global = !escopo_eh_local;//Auxiliara no calculo do endereco da variavel
	
	dicionarioInsereItem(dic,itemDic);
}

inline void referenciar_dicionario(comp_dict_t* dic){
	yylval.symbol = dicionarioRetornaChave(dic,yytext);
	dicionarioAtualizaLinha(dic,yytext,yylineno);
}

inline void testa_erro_input(){
	if(com_eh_input == 1)
		exit(IKS_ERROR_WRONG_PAR_INPUT);
}
