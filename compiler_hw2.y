/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
void yyerror(char *s);

typedef struct _symbol_table_entry {
	char name[32];
	char entry_type[32];
	char data_type[16];
	int scope_level;
	char formal_para[16][16];
}symbol_table_entry;

symbol_table_entry *symbol_table = NULL;
int table_pointer = 0;
extern int curr_scope;
char curr_formal_para[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
int curr_formal_para_index = 0;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char name[32]);
void create_symbol();
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]);
void dump_symbol();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
    int bool_val;
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE
%token SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token RET CONTINUE BREAK
%token C_COMMENT CPP_COMMENT

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <bool_val> TRUE_RESULT FALSE_RESULT
%token <string> INT FLOAT BOOL STRING VOID
%token <string> STR_CONST ID

/* Nonterminal with return, which need to sepcify type */
%type <string> type

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program global_decl_or_functions
    | 
;

global_decl_or_functions
	: global_decl_or_functions global_decl_or_function
	| global_decl_or_function
;
	
global_decl_or_function
	: global_decl
	| function_define
;

global_decl
    : var_decl
    | function_decl
;

var_decl
    : type ID ASGN initializer SEMICOLON {
    	if(strcmp($1, "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else
    	{
    		// semantic error
    		printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| %s can not be declared \"void\"", $2);
			printf("\n|-----------------------------------------------|\n\n");
    	}
    }
    | type ID SEMICOLON {
    	if(strcmp($1, "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else
    	{
    		// semantic error
    		printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| %s can not be declared \"void\"", $2);
			printf("\n|-----------------------------------------------|\n\n");
    	}
    }
;

function_decl
	: type ID para_area SEMICOLON {
		if(strcmp($1, "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "void", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "void", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", $2);
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
	}
;

para_area
	: LB paras RB { 
				curr_formal_para_index = 0;
				char allEmpty[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
				int targetIndex = 0;
				char *temp = NULL;
				if(strcmp(curr_formal_para[0], "\0") != 0)
				{
					temp = strtok(curr_formal_para[0], " ");
					targetIndex = lookup_symbol((char *)(curr_formal_para[0]+1));
				}
				if(targetIndex == -1)
				{
					insert_symbol((char *)(curr_formal_para[0]+1), "variable", temp, curr_scope+1, allEmpty);
				}
				else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
				{
					insert_symbol((char *)(curr_formal_para[0]+1), "variable", temp, curr_scope+1, allEmpty);
				}
				else
				{
					// semantic error
					printf("\n|-----------------------------------------------|\n");
					printf("| Error found in line %d: %s\n", yylineno, buf);
					printf("| Redeclared variable %s", (char *)(curr_formal_para[0]+1));
					printf("\n|-----------------------------------------------|\n\n");
				}
				for(int i=1; i<15; i++)
				{
					int targetIndex = 0;
					char *temp = NULL;
					if(strcmp(curr_formal_para[i], "\0") != 0)
					{
						temp = strtok(NULL, " ");
						targetIndex = lookup_symbol((char *)(curr_formal_para[i]+1));
					}
					if(targetIndex == -1)
					{
						insert_symbol((char *)(curr_formal_para[i]+1), "variable", temp, curr_scope+1, allEmpty);
					}
					else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
					{
						insert_symbol((char *)(curr_formal_para[i]+1), "variable", temp, curr_scope+1, allEmpty);
					}
					else
					{
						// semantic error
						printf("\n|-----------------------------------------------|\n");
						printf("| Error found in line %d: %s\n", yylineno, buf);
						printf("| Redeclared variable %s", (char *)(curr_formal_para[i]+1));
						printf("\n|-----------------------------------------------|\n\n");
					}
				}
				 
    		}
	| LB RB
;

paras
	: paras COMMA para
	| para
;

para
	: type ID { strcat(curr_formal_para[curr_formal_para_index], $1); strcat(curr_formal_para[curr_formal_para_index], " "); strcat(curr_formal_para[curr_formal_para_index], $2); if(curr_formal_para_index <= 14)curr_formal_para_index++; }
;

/* actions can be taken when meet the token or rule */
type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;

initializer
	: logic_initializer
	| STR_CONST 
;

logic_initializer
	: number_initializer
	| tf_initializer
;

number_initializer
	: I_CONST 
	| F_CONST 
	| count_expr
	| ID
;

tf_initializer
	: TRUE_RESULT 
	| FALSE_RESULT 
	| ID
;

count_expr  //need to complete it !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	: I_CONST ADD I_CONST 
	| I_CONST SUB I_CONST 
;

function_define
	: type ID para_area combound_area { 
		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "def"};
		int targetIndex = lookup_symbol($2);
		if(targetIndex == -1)
		{
			insert_symbol($2, "function", "void", curr_scope, temp);
		}
		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
		{
			insert_symbol($2, "function", "void", curr_scope, temp);
		}
		else if(targetIndex != -1 && strcmp(symbol_table[targetIndex].formal_para[15], "decl") == 0)
		{
			insert_symbol($2, "function", "void", curr_scope, temp);
		}
		else
		{
			// semantic error
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Redeclared function %s", $2);
			printf("\n|-----------------------------------------------|\n\n");
		}
	}
;

combound_area
	: LCB combound_area_inner RCB { dump_symbol(); curr_scope--; }
;

combound_area_inner
	: combound_area_inner stat
	|
;

stat
	: asgn_stat
	| var_decl
	| print_stat
	| function_using
	| if_stat
	| while_stat
	| return_stat
	| SEMICOLON
;

asgn_stat
	: ID ASGN initializer SEMICOLON
	| ID ADDASGN number_initializer SEMICOLON
	| ID SUBASGN number_initializer SEMICOLON
	| ID MULASGN number_initializer SEMICOLON
	| ID DIVASGN number_initializer SEMICOLON
	| ID MODASGN number_initializer SEMICOLON
;

print_stat
	: PRINT LB STR_CONST RB SEMICOLON
	| PRINT LB ID RB SEMICOLON
;

function_using
	: ID para_area_using SEMICOLON 
;

para_area_using
	: LB paras_using RB
	| LB RB
;

paras_using
	: paras_using COMMA initializer
	| initializer
;

if_stat
	: single_if_stat else_if_stats else_stat
	| single_if_stat else_if_stats
	| single_if_stat else_stat
	| single_if_stat
;

single_if_stat
	: IF LB logic_initializer RB combound_area
	| IF LB logic_initializer RB stat
;

else_if_stats 
	: else_if_stats ELSE single_if_stat
	| ELSE single_if_stat
;

else_stat
	: ELSE combound_area
	| ELSE stat
;

while_stat
	: WHILE LB logic_initializer RB combound_area
	| WHILE LB logic_initializer RB stat
;

return_stat
	: RET initializer SEMICOLON
	| RET SEMICOLON
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;
    create_symbol();
    printf("1. ");
    curr_scope = 0;

    yyparse();
    dump_symbol();
	printf("\nTotal lines: %d \n",yylineno);
	
	if(symbol_table != NULL)
	{
		free(symbol_table);
	}
    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {
	symbol_table = (symbol_table_entry *)malloc(sizeof(symbol_table_entry) * 30);
	for(int i=0; i<30; i++)
	{
		strcpy(symbol_table[i].name, "\0");
		strcpy(symbol_table[i].entry_type, "\0");
		strcpy(symbol_table[i].data_type, "\0");
		symbol_table[i].scope_level = -1;
		for(int j=0; j<16; j++)
			strcpy(symbol_table[i].formal_para[i], "\0");
	}
}
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]) {
	if(lookup_symbol(name) != -1)
	{
		//semantic error.
	}
	else if(lookup_symbol(name) == -1)
	{
		strcpy(symbol_table[table_pointer].name, name);
		strcpy(symbol_table[table_pointer].entry_type, entry_type);
		strcpy(symbol_table[table_pointer].data_type, data_type);
		symbol_table[table_pointer].scope_level = scope_level;
		for(int i=0; i<16; i++)
			strcpy(symbol_table[table_pointer].formal_para[i], formal_para[i]);
		
		if(table_pointer != 29) table_pointer++;
	}
	else
	{
		//unknown error, here is imposible in general.
	}
}
int lookup_symbol(char name[32]) {
	for(int i=0; i<30; i++)
	{
		if(strcmp(symbol_table[i].name, name) == 0)
		{
			return i;  //used
		}
	}
	return -1;
}
void dump_symbol() {
	int myFlag = 0;
	for(int i=0; i<30; i++)
	{
		if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
		{
			myFlag = 1;
		}
	}
	if(myFlag)
	{
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	}
    int dump_index = 0;
           
    for(int i=0; i<30; i++)
    {
    	char attribute[10] = "\0";
    	char index_str[10] = "\0";
    	char scope_str[10] = "\0";
    	
    	if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
    	{
    		for(int j=0; j<15; j++)
    		{
    			strcat(attribute, symbol_table[i].formal_para[j]);
    			if(j != 14 && strcmp(symbol_table[i].formal_para[j+1], "\0") != 0 && strcmp(symbol_table[i].formal_para[j+1], "decl") != 0) strcat(attribute, ", ");
    		}
    		sprintf(index_str, "%d", dump_index);
    		sprintf(scope_str, "%d", symbol_table[i].scope_level);
    		printf("%-10s%-10s%-12s%-10s%-10s%-10s\n",
           index_str, symbol_table[i].name, symbol_table[i].entry_type, symbol_table[i].data_type, scope_str, attribute);
           
           strcpy(symbol_table[i].name, "\0");
		   strcpy(symbol_table[i].entry_type, "\0");
		   strcpy(symbol_table[i].data_type, "\0");
		   symbol_table[i].scope_level = -1;
		   for(int j=0; j<16; j++)
			   strcpy(symbol_table[i].formal_para[i], "\0");
           
           dump_index++;
    	}
    }
}
