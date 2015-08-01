/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/
/*
   main.c

   Arquivo principal do analisador sintático.
*/
#include "main.h"

char arquivo_saida[] = "saida.dot";

int main (int argc, char **argv)
{
  gv_init(arquivo_saida);
  int resultado = yyparse();
  gv_close();
  return resultado;
}

