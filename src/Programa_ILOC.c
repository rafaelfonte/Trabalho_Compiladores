#include "Programa_ILOC.h"
#define __ILOC_DEBUG_MODE


int ILOC_label(){
	static int label = -1;
	label++;
	return label;
}

int ILOC_reg(){
	static int register_v = -1;
	register_v++;
	return register_v;
}

void ILOC_print_op(ILOC_OP* operation){
	char op_code[25];
	op_code[0] = '\0';

	if(operation == NULL){
		fprintf(stderr,"ERROR: null operation!\n");
		exit(ILOC_FATAL_ERROR);
	}
	else{
		int operand_scheme = 0;
/*
0: ??????
1: REG,REG => REG
2: REG,CONST => REG
3: CONST => REG
4: REG => REG
5: REG => REG, CONST
6: REG => REG, REG
7:  -> LABEL
8:  -> REG
9: REG -> LABEL, LABEL
10: REG, REG-> REG
*/
		switch(operation->operation_code){
			case ILOC_NOP:        {strcpy(op_code,"nop");operand_scheme=0;break;}
			case ILOC_ADD:        {strcpy(op_code,"add");operand_scheme=1;break;}
			case ILOC_SUB:        {strcpy(op_code,"sub");operand_scheme=1;break;}
			case ILOC_MULT:       {strcpy(op_code,"mult");operand_scheme=1;break;}
			case ILOC_DIV:        {strcpy(op_code,"div");operand_scheme=1;break;}
			
			case ILOC_ADD_I:      {strcpy(op_code,"addI");operand_scheme=2;break;}
			case ILOC_SUB_I:      {strcpy(op_code,"subI");operand_scheme=2;break;}
			case ILOC_R_SUB_I:    {strcpy(op_code,"RsubI");operand_scheme=2;break;}
			case ILOC_MULT_I:     {strcpy(op_code,"multI");operand_scheme=2;break;}
			case ILOC_DIV_I:      {strcpy(op_code,"divI");operand_scheme=2;break;}
			case ILOC_R_DIV_I:    {strcpy(op_code,"RdivI");operand_scheme=2;break;}
			
			case ILOC_L_SHIFT:    {strcpy(op_code,"Lshift");operand_scheme=1;break;}
			case ILOC_L_SHIFT_I:  {strcpy(op_code,"LshiftI");operand_scheme=2;break;}
			case ILOC_R_SHIFT:    {strcpy(op_code,"Rshift");operand_scheme=1;break;}
			case ILOC_R_SHIFT_I:  {strcpy(op_code,"RshiftI");operand_scheme=2;break;}

			case ILOC_AND:        {strcpy(op_code,"and");operand_scheme=1;break;}
			case ILOC_AND_I:      {strcpy(op_code,"andI");operand_scheme=2;break;}
			case ILOC_OR:         {strcpy(op_code,"or");operand_scheme=1;break;}
			case ILOC_OR_I:       {strcpy(op_code,"orI");operand_scheme=2;break;}
			case ILOC_XOR:        {strcpy(op_code,"xor");operand_scheme=1;break;}
			case ILOC_XOR_I:      {strcpy(op_code,"xorI");operand_scheme=2;break;}
			
			case ILOC_LOAD_I:     {strcpy(op_code,"loadI");operand_scheme=3;break;}
			
			case ILOC_LOAD:       {strcpy(op_code,"load");operand_scheme=4;break;}
			case ILOC_LOAD_AI:    {strcpy(op_code,"loadAI");operand_scheme=2;break;}
			case ILOC_LOAD_AO:    {strcpy(op_code,"loadAO");operand_scheme=1;break;}
			
			case ILOC_C_LOAD:     {strcpy(op_code,"Cload");operand_scheme=4;break;}
			case ILOC_C_LOAD_AI:  {strcpy(op_code,"CloadAI");operand_scheme=2;break;}
			case ILOC_C_LOAD_AO:  {strcpy(op_code,"CloadAO");operand_scheme=1;break;}
			
			case ILOC_STORE:      {strcpy(op_code,"store");operand_scheme=4;break;}
			case ILOC_STORE_AI:   {strcpy(op_code,"storeAI");operand_scheme=5;break;}
			case ILOC_STORE_AO:   {strcpy(op_code,"storeAO");operand_scheme=6;break;}
			
			case ILOC_C_STORE:    {strcpy(op_code,"Cstore");operand_scheme=4;break;}
			case ILOC_C_STORE_AI: {strcpy(op_code,"storeAI");operand_scheme=5;break;}
			case ILOC_C_STORE_AO: {strcpy(op_code,"storeAO");operand_scheme=6;break;}

			case ILOC_I_2_I:      {strcpy(op_code,"i2i");operand_scheme=4;break;}
			case ILOC_C_2_C:      {strcpy(op_code,"c2c");operand_scheme=4;break;}
			case ILOC_C_2_I:      {strcpy(op_code,"c2i");operand_scheme=4;break;}
			case ILOC_I_2_C:      {strcpy(op_code,"i2c");operand_scheme=4;break;}
			
			case ILOC_JUMP_I:     {strcpy(op_code,"jumpI");operand_scheme=7;break;}
			case ILOC_JUMP:       {strcpy(op_code,"jump");operand_scheme=8;break;}
			
			case ILOC_CBR:        {strcpy(op_code,"cbr");operand_scheme=9;break;}

			case ILOC_CMP_LT:     {strcpy(op_code,"cmp_LT");operand_scheme=10;break;}
			case ILOC_CMP_LE:     {strcpy(op_code,"cmp_LE");operand_scheme=10;break;}
			case ILOC_CMP_EQ:     {strcpy(op_code,"cmp_EQ");operand_scheme=10;break;}
			case ILOC_CMP_GE:     {strcpy(op_code,"cmp_GE");operand_scheme=10;break;}
			case ILOC_CMP_GT:     {strcpy(op_code,"cmp_GT");operand_scheme=10;break;}
			case ILOC_CMP_NE:     {strcpy(op_code,"cmp_NE");operand_scheme=10;break;}

			case ILOC_LABEL:      {strcpy(op_code,"L");operand_scheme=11;break;}
			default:{
				fprintf(stderr,"ERRO: opcode nao definido!\n");
				exit(ILOC_FATAL_ERROR);
			}
		};
/*
0: ??????
1: REG,REG => REG
2: REG,CONST => REG
3: CONST => REG
4: REG => REG
5: REG => REG, CONST
6: REG => REG, REG
7:  -> LABEL
8:  -> REG
9: REG -> LABEL, LABEL
10: REG, REG-> REG
*/
		switch(operand_scheme){
			case 0:{printf("\t%s\n", op_code);break;}
			case 1:{printf("\t%s r%d, r%d => r%d\n", op_code, operation->operand_1, operation->operand_2, operation->result_operand);break;}
			case 2:{printf("\t%s r%d, c%d => r%d\n", op_code, operation->operand_1, operation->operand_2, operation->result_operand);break;}
			case 3:{printf("\t%s c%d => r%d\n", op_code, operation->operand_1, operation->result_operand);break;}
			case 4:{printf("\t%s r%d => r%d\n", op_code, operation->operand_1, operation->result_operand);break;}
			case 5:{printf("\t%s r%d => r%d c%d\n", op_code, operation->operand_1, operation->operand_2, operation->result_operand);break;}
			case 6:{printf("\t%s r%d => r%d r%d\n", op_code, operation->operand_1, operation->operand_2, operation->result_operand);break;}
			case 7:{printf("\t%s -> L%d\n", op_code, operation->result_operand);break;}
			case 8:{printf("\t%s -> r%d\n", op_code, operation->result_operand);break;}
			case 9:{printf("\t%s r%d -> L%d L%d\n", op_code, operation->operand_1, operation->operand_2, operation->result_operand);break;}
			case 10:{printf("\t%s r%d, r%d -> r%d\n", op_code, operation->operand_1, operation->operand_2, operation->result_operand);break;}
			case 11:{printf("%s%d:\n", op_code,operation->result_operand);break;}
			default:{
				fprintf(stderr,"ERROR: operand scheme not defined!\n");
				exit(ILOC_FATAL_ERROR);
			}			
		};
	}
}

void ILOC_print_op_list(ILOC_OP_LIST * list){
	if(list == NULL){
		#ifdef __ILOC_DEBUG_MODE
		printf("List to be printed is empty!\n");
		#endif
	}
	else{
		ILOC_OP * curOP = list->first;
		while(curOP != NULL){
			ILOC_print_op(curOP);
			curOP = curOP->next;
		}
	}
}


ILOC_OP* ILOC_create_operation(int op_code,int op_1, int op_2, int res){
	ILOC_OP * new_op = (ILOC_OP*)malloc(sizeof(ILOC_OP));
	new_op->operation_code = op_code;
	new_op->operand_1 = op_1;
	new_op->operand_2 = op_2;
	new_op->result_operand = res;
	return new_op;	
}

//Creates a new ILOC Label
ILOC_OP* ILOC_create_label(int label){
	return ILOC_create_operation(ILOC_LABEL,-1,-1,label);
}


int ILOC_is_list_empty(ILOC_OP_LIST* lst){
	if(lst != NULL){
		return lst->first == NULL;
	}
	else{
		return 1;
	}
}

ILOC_OP_LIST* ILOC_concat_lists(ILOC_OP_LIST* l1, ILOC_OP_LIST* l2){
	if(ILOC_is_list_empty(l1)){
		return l2;
	}
	if(ILOC_is_list_empty(l2)){
		return l1;
	}
	
	ILOC_OP_LIST * new_list = (ILOC_OP_LIST*) malloc(sizeof(ILOC_OP_LIST));
	new_list->first = l1->first;
	l1->last->next = l2->first;
	new_list->last = l2->last;
	
	free(l1);
	free(l2);
}

ILOC_OP_LIST* ILOC_create_operation_list(){
	ILOC_OP_LIST* new_list = (ILOC_OP_LIST*) malloc(sizeof(ILOC_OP_LIST));
	
	new_list->first = NULL;
	new_list->last = NULL;
	return new_list;
}

ILOC_OP_LIST* ILOC_add_to_list(ILOC_OP_LIST* list_to_update, ILOC_OP * op_to_add){
	ILOC_OP_LIST* lst = list_to_update;
	if(lst == NULL){
		fprintf(stderr,"ERROR: list has not been initialized!\n");
		exit(ILOC_FATAL_ERROR);
	}
	if(op_to_add == NULL){
		fprintf(stderr,"ERROR: operation structure has not been initialized!\n");
		exit(ILOC_FATAL_ERROR);
	}
	if((lst->first == NULL && lst->last != NULL) || (lst->first != NULL && lst->last == NULL)){
		fprintf(stderr,"ERROR: list lost consistency!\n");
		exit(ILOC_FATAL_ERROR);
	}
	//List is empty...
	if(lst->first == NULL){
		lst->first = op_to_add;
		lst->last = op_to_add;
		op_to_add->next = NULL;
		return lst;
	}
	else{
		lst->last->next = op_to_add;
		op_to_add->next = NULL;
		lst->last = op_to_add;
		return lst;
	}
}








