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
int curr_scope = 0;

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
%type <string> type initializer count_expr

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
//	| function_define
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
    		insert_symbol($2, "variable", "int", curr_scope, temp);
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		
    	}
    	else
    	{
    		// semantic error
    	}
    }
    | type ID SEMICOLON {
    	if(strcmp($1, "int") == 0)
    	{
    		
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		
    	}
    	else
    	{
    		// semantic error
    	}
    }
;

function_decl
	: type ID para_area SEMICOLON
;

para_area
	: LB paras RB
	| LB RB
;

paras
	: paras COMMA para
	| para
;

para
	: type ID
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
	: I_CONST { $$ = strdup("test");  }
	| F_CONST { $$ = strdup("test");  }
	| TRUE_RESULT { $$ = strdup("test");  }
	| FALSE_RESULT { $$ = strdup("test"); }
	| STR_CONST { $$ = strdup($1); }
	| count_expr
;

count_expr  //need to complete it !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	: I_CONST ADD I_CONST { $$ = strdup("test");  }
	| I_CONST SUB I_CONST { $$ = strdup("test"); }
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;
    create_symbol();
    printf("1. ");

    yyparse();
	printf("\nTotal lines: %d \n",yylineno);
	dump_symbol();
	
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
	if(lookup_symbol(name) == -1)
	{
		//semantic error.
	}
	else if(lookup_symbol(name) == 0)
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
			return -1;  //used
		}
	}
	return 0;
}
void dump_symbol() {
	if(strcmp(symbol_table[0].name, "\0") == 0) return;
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
           
    int dump_index = 0;
           
    for(int i=0; i<30; i++)
    {
    	char attribute[10] = "\0";
    	char index_str[10] = "\0";
    	char scope_str[10] = "\0";
    	
    	if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
    	{
    		for(int j=0; j<16; j++)
    		{
    			strcat(attribute, symbol_table[i].formal_para[j]);
    			if(j != 15 && strcmp(symbol_table[i].formal_para[j+1], "\0") != 0) strcat(attribute, ", ");
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
