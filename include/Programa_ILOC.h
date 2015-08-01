#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 *	DEFINICOES DAS OPERACOES ILOC
 */
#define ILOC_NOP		0

//OPERACOES ARITMETICAS ENTRE REGISTRADORES
#define ILOC_ADD		1
#define ILOC_SUB		2
#define ILOC_MULT		3
#define ILOC_DIV		4

//OPERACOES COM IMEDIATO
#define ILOC_ADD_I		5
#define ILOC_SUB_I		6
#define ILOC_R_SUB_I		7
#define ILOC_MULT_I		8
#define ILOC_DIV_I		9
#define ILOC_R_DIV_I		10

#define ILOC_L_SHIFT		11
#define ILOC_L_SHIFT_I		12
#define ILOC_R_SHIFT		13
#define ILOC_R_SHIFT_I		14

#define ILOC_AND		15
#define ILOC_AND_I		16
#define ILOC_OR			17
#define ILOC_OR_I		18
#define ILOC_XOR		19
#define ILOC_XOR_I		20

#define ILOC_LOAD_I		21

#define ILOC_LOAD		22
#define ILOC_LOAD_AI		23
#define ILOC_LOAD_AO		24

#define ILOC_C_LOAD		25
#define ILOC_C_LOAD_AI		26
#define ILOC_C_LOAD_AO		27

#define ILOC_STORE		28
#define ILOC_STORE_AI		29
#define ILOC_STORE_AO		30

#define ILOC_C_STORE		31
#define ILOC_C_STORE_AI		32
#define ILOC_C_STORE_AO		33

#define ILOC_I_2_I		34
#define ILOC_C_2_C		35
#define ILOC_C_2_I		36
#define ILOC_I_2_C		37

#define ILOC_JUMP_I		38
#define ILOC_JUMP		39

#define ILOC_CBR		40

#define ILOC_CMP_LT		41
#define ILOC_CMP_LE		42
#define ILOC_CMP_EQ		43
#define ILOC_CMP_GE		44
#define ILOC_CMP_GT		45
#define ILOC_CMP_NE		46

#define ILOC_LABEL		47

#define ILOC_FATAL_ERROR        666

typedef struct{
	int operation_code;
	int operand_1;
	int operand_2;
	int result_operand;
	struct ILOC_OP* next;
}ILOC_OP;

typedef struct{
	ILOC_OP* first;
	ILOC_OP* last;
}ILOC_OP_LIST;




int ILOC_label();
int ILOC_reg();
ILOC_OP* ILOC_create_operation(int op_code,int op_1, int op_2, int res);
ILOC_OP* ILOC_create_label(int label);


void ILOC_print_op(ILOC_OP* operation);
void ILOC_print_op_list(ILOC_OP_LIST * list);
ILOC_OP* ILOC_create_operation(int op_code,int op_1, int op_2, int res);
ILOC_OP* ILOC_create_label(int label);
int ILOC_is_list_empty(ILOC_OP_LIST* lst);
ILOC_OP_LIST* ILOC_concat_lists(ILOC_OP_LIST* l1, ILOC_OP_LIST* l2);
ILOC_OP_LIST* ILOC_create_operation_list();
ILOC_OP_LIST* ILOC_add_to_list(ILOC_OP_LIST* list_to_update, ILOC_OP * op_to_add);




