%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char* s);

/* Symbol table implementation */
struct symbol {
    char* name;
    char* type;
    int address;  /* Memory address for the variable */
    struct symbol* next;
};

struct symbol* sym_table = NULL;
int next_address = 0;  /* Next available memory address */
int temp_count = 0;    /* Counter for temporary variables */

void add_symbol(char* name, char* type) {
    struct symbol* s = (struct symbol*)malloc(sizeof(struct symbol));
    s->name = strdup(name);
    s->type = strdup(type);
    s->address = next_address++;
    s->next = sym_table;
    sym_table = s;
}

struct symbol* find_symbol(char* name) {
    struct symbol* s;
    for (s = sym_table; s != NULL; s = s->next) {
        if (strcmp(s->name, name) == 0) {
            return s;
        }
    }
    return NULL;
}

/* Intermediate code generation */
FILE* outfile;
FILE* ir_file;  /* File for intermediate representation */
int label_count = 0;  /* Counter for labels */

char* new_temp() {
    char* temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    add_symbol(temp, "temp");
    return temp;
}

char* new_label() {
    char* label = (char*)malloc(10);
    sprintf(label, "L%d", label_count++);
    return label;
}

void emit(char* op, char* arg1, char* arg2, char* result) {
    fprintf(ir_file, "%s, %s, %s, %s\n", op, arg1 ? arg1 : "", arg2 ? arg2 : "", result ? result : "");
}

void generate_program_header() {
    fprintf(outfile, "#include <stdio.h>\n");
    fprintf(outfile, "#include <stdlib.h>\n");
    fprintf(outfile, "#include <string.h>\n\n");
    fprintf(outfile, "// Generated C code from custom language\n\n");
    
    fprintf(ir_file, "// Intermediate Code\n");
    fprintf(ir_file, "// Format: Operation, Arg1, Arg2, Result\n\n");
}

void generate_main_header() {
    fprintf(outfile, "int main() {\n");
    emit("FUNC_BEGIN", "main", "", "");
}

void generate_main_footer() {
    fprintf(outfile, "    return 0;\n");
    fprintf(outfile, "}\n");
    emit("FUNC_END", "main", "", "");
}
%}

%union {
    int ival;
    float fval;
    char* sval;
    struct {
        char* place;  /* Name of the temporary holding the value */
        char* code;   /* Generated code string */
        char* true_label;  /* For boolean expressions */
        char* false_label; /* For boolean expressions */
    } expr_attr;
}

/* Tokens */
%token CHECK ENDCHECK OTHERWISE ENDOTHERWISE DEFAULT ENDDEFAULT
%token LOOP ENDLOOP START END CALL GIVE
%token SHOW ASK INTO WRITE TO READ
%token PLUS MINUS MULT DIV
%token ASSIGN SEMICOLON COMMA
%token EQ NEQ GT LT GEQ LEQ
%token COLON LPAREN RPAREN
%token <ival> INT_LITERAL
%token <fval> FLOAT_LITERAL
%token <sval> STRING_LITERAL
%token <sval> IDENTIFIER
%type <expr_attr> loop_init
%type <expr_attr> loop_update

/* Types for non-terminals */
%type <expr_attr> expr

/* Operator precedence */
%left PLUS MINUS
%left MULT DIV

/* Resolve some grammar conflicts */
%expect 84

%%

program:
    { 
        /* Initialize output files and write headers */
        outfile = fopen("output.c", "w");
        ir_file = fopen("intermediate.ir", "w");
        if (outfile == NULL || ir_file == NULL) {
            fprintf(stderr, "Failed to open output files\n");
            exit(1);
        }
        generate_program_header();
        generate_main_header();
    }
    statement_list
    { 
        /* Write footers and close files */
        generate_main_footer();
        fclose(outfile);
        fclose(ir_file);
        printf("Compilation successful. Generated intermediate.ir\n");
    }
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    assignment
    | conditional_statement
    | loop_statement
    | function_definition
    | function_call
    | show_statement
    | input_statement
    | file_write_statement
    | file_read_statement
    | return_statement
    ;

assignment:
    IDENTIFIER ASSIGN expr
    { 
        /* Add symbol to table if not already there */
        if (!find_symbol($1)) {
            add_symbol($1, "var");
        }
        
        /* Generate C code */
        fprintf(outfile, "    /* Assignment */\n");
        fprintf(outfile, "    %s = %s;\n", $1, $3.place);
        
        /* Generate intermediate code */
        emit("ASSIGN", $3.place, "", $1);
    }
    ;

/* Conditional statements */
conditional_statement:
    check_block
    ;

check_block:
    check_statement
    | check_statement otherwise_statement_list
    | check_statement otherwise_statement_list default_statement
    ;

check_statement:
    CHECK expr COLON
    { 
        char* label_else = new_label();
        char* label_end = new_label();
        
        /* Generate C code */
        fprintf(outfile, "    /* Check statement */\n");
        fprintf(outfile, "    if (%s) {\n", $2.place);
        
        /* Generate intermediate code */
        emit("IF_FALSE", $2.place, "", label_else);
    }
    statement_list ENDCHECK
    {
        fprintf(outfile, "    }\n");
        emit("LABEL", "", "", "end_if");
    }
    ;

otherwise_statement_list:
    otherwise_statement
    | otherwise_statement_list otherwise_statement
    ;

otherwise_statement:
    OTHERWISE expr COLON
    {
        char* label_else = new_label();
        
        fprintf(outfile, "    /* Otherwise statement */\n");
        fprintf(outfile, "    else if (%s) {\n", $2.place);
        
        /* Generate intermediate code */
        emit("IF_FALSE", $2.place, "", label_else);
    }
    statement_list ENDOTHERWISE
    {
        fprintf(outfile, "    }\n");
        emit("LABEL", "", "", "end_elif");
    }
    ;

default_statement:
    DEFAULT COLON
    {
        fprintf(outfile, "    /* Default statement */\n");
        fprintf(outfile, "    else {\n");
        
        /* Generate intermediate code */
        emit("LABEL", "", "", "else_block");
    }
    statement_list ENDDEFAULT
    {
        fprintf(outfile, "    }\n");
        emit("LABEL", "", "", "end_if_all");
    }
    ;

loop_statement:
    LOOP loop_init SEMICOLON expr SEMICOLON loop_update COLON
    {
        char* start_label = new_label();
        char* end_label = new_label();
        
        fprintf(outfile, "    /* Loop statement */\n");
        fprintf(outfile, "    for (%s; %s; %s) {\n", $2.place, $4.place, $6.place);
        
        /* Generate intermediate code */
        emit("LABEL", "", "", start_label);
        emit("IF_FALSE", $4.place, "", end_label);
    }
    statement_list ENDLOOP
    {
        fprintf(outfile, "    }\n");
        
        /* Generate loop continuation */
        emit("GOTO", "", "", "loop_start");
        emit("LABEL", "", "", "loop_end");
    }
    ;

/* Add these new rules */
loop_init:
    IDENTIFIER ASSIGN expr
    {
        if (!find_symbol($1)) {
            add_symbol($1, "var");
        }
        $$.place = malloc(strlen($1) + strlen($3.place) + 5);
        sprintf($$.place, "%s = %s", $1, $3.place);
        emit("ASSIGN", $3.place, "", $1);
    }
    ;

loop_update:
    IDENTIFIER ASSIGN expr
    {
        $$.place = malloc(strlen($1) + strlen($3.place) + 5);
        sprintf($$.place, "%s = %s", $1, $3.place);
        emit("ASSIGN", $3.place, "", $1);
    }
    ;
function_definition:
    START IDENTIFIER param_list COLON
    {
        fprintf(outfile, "\n/* Function definition */\n");
        
        /* Generate intermediate code */
        emit("FUNC_BEGIN", $2, "", "");
    }
    statement_list END
    {
        fprintf(outfile, "}\n\n");
        emit("FUNC_END", "", "", "");
    }
    ;

param_list:
    IDENTIFIER
    {
        fprintf(outfile, "void %s(int %s) {\n", $<sval>-1, $1);
        add_symbol($1, "param");
        
        /* Generate intermediate code */
        emit("PARAM", $1, "", "");
    }
    | param_list COMMA IDENTIFIER
    {
        // Add parameter to symbol table
        add_symbol($3, "param");
        
        /* Generate intermediate code */
        emit("PARAM", $3, "", "");
    }
    ;

function_call:
    CALL IDENTIFIER arg_list
    {
        // Generate function call code
        fprintf(outfile, "    /* Function call */\n");
        fprintf(outfile, "    %s(/* args */);\n", $2);
        
        /* Generate intermediate code */
        emit("CALL", $2, "", "");
    }
    ;

arg_list:
    expr
    {
        /* Generate intermediate code */
        emit("ARG", $1.place, "", "");
    }
    | arg_list COMMA expr
    {
        /* Generate intermediate code */
        emit("ARG", $3.place, "", "");
    }
    ;

show_statement:
    SHOW expr
    {
        /* Generate C code for print statement */
        fprintf(outfile, "    /* Show statement */\n");
        fprintf(outfile, "    printf(\"%s\\n\");\n", $2.place);
        
        /* Generate intermediate code */
        emit("PRINT", $2.place, "", "");
    }
    ;

input_statement:
    ASK expr INTO IDENTIFIER
    {
        /* Add variable to symbol table */
        add_symbol($4, "var");
        
        /* Generate C code for input */
        fprintf(outfile, "    /* Input statement */\n");
        fprintf(outfile, "    {\n");
        fprintf(outfile, "        printf(\"%s \");\n", $2.place);
        fprintf(outfile, "        char %s[100];\n", $4);
        fprintf(outfile, "        scanf(\"%%s\", %s);\n", $4);
        fprintf(outfile, "    }\n");
        
        /* Generate intermediate code */
        emit("PROMPT", $2.place, "", "");
        emit("INPUT", "", "", $4);
    }
    ;

file_write_statement:
    WRITE expr TO expr
    {
        fprintf(outfile, "    /* Write to file */\n");
        fprintf(outfile, "    {\n");
        fprintf(outfile, "        FILE* f = fopen(%s, \"w\");\n", $4.place);
        fprintf(outfile, "        if (f != NULL) {\n");
        fprintf(outfile, "            fprintf(f, \"%%s\", %s);\n", $2.place);
        fprintf(outfile, "            fclose(f);\n");
        fprintf(outfile, "        } else {\n");
        fprintf(outfile, "            printf(\"Error opening file\\n\");\n");
        fprintf(outfile, "        }\n");
        fprintf(outfile, "    }\n");
        
        /* Generate intermediate code */
        emit("FOPEN", $4.place, "w", "file_ptr");
        emit("FWRITE", $2.place, "", "file_ptr");
        emit("FCLOSE", "file_ptr", "", "");
    }
    ;

file_read_statement:
    IDENTIFIER ASSIGN READ expr
    {
        /* Add variable to symbol table */
        add_symbol($1, "var");
        
        fprintf(outfile, "    /* Read from file */\n");
        fprintf(outfile, "    {\n");
        fprintf(outfile, "        FILE* f = fopen(%s, \"r\");\n", $4.place);
        fprintf(outfile, "        if (f != NULL) {\n");
        fprintf(outfile, "            char %s[1000];\n", $1);
        fprintf(outfile, "            fgets(%s, 1000, f);\n", $1);
        fprintf(outfile, "            fclose(f);\n");
        fprintf(outfile, "        } else {\n");
        fprintf(outfile, "            printf(\"Error opening file\\n\");\n");
        fprintf(outfile, "        }\n");
        fprintf(outfile, "    }\n");
        
        /* Generate intermediate code */
        emit("FOPEN", $4.place, "r", "file_ptr");
        emit("FREAD", "", "", $1);
        emit("FCLOSE", "file_ptr", "", "");
    }
    ;

return_statement:
    GIVE expr
    {
        fprintf(outfile, "    /* Return statement */\n");
        fprintf(outfile, "    return %s;\n", $2.place);
        
        /* Generate intermediate code */
        emit("RETURN", $2.place, "", "");
    }
    ;

expr:
    IDENTIFIER 
    { 
        $$.place = $1;
        $$.code = strdup("");
    }
    | INT_LITERAL 
    { 
        char temp[20]; 
        sprintf(temp, "%d", $1); 
        $$.place = strdup(temp);
        $$.code = strdup("");
    }
    | FLOAT_LITERAL 
    { 
        char temp[20]; 
        sprintf(temp, "%f", $1); 
        $$.place = strdup(temp);
        $$.code = strdup("");
    }
    | STRING_LITERAL 
    { 
        char temp[strlen($1) + 3]; 
        sprintf(temp, "\"%s\"", $1); 
        $$.place = strdup(temp);
        $$.code = strdup("");
    }
    | expr PLUS expr 
    { 
        $$.place = new_temp();
        emit("ADD", $1.place, $3.place, $$.place);
    }
    | expr MINUS expr 
    { 
        $$.place = new_temp();
        emit("SUB", $1.place, $3.place, $$.place);
    }
    | expr MULT expr 
    { 
        $$.place = new_temp();
        emit("MUL", $1.place, $3.place, $$.place);
    }
    | expr DIV expr 
    { 
        $$.place = new_temp();
        emit("DIV", $1.place, $3.place, $$.place);
    }
    | expr GT expr 
    { 
        $$.place = new_temp();
        emit("GT", $1.place, $3.place, $$.place);
    }
    | expr LT expr 
    { 
        $$.place = new_temp();
        emit("LT", $1.place, $3.place, $$.place);
    }
    | expr GEQ expr 
    { 
        $$.place = new_temp();
        emit("GE", $1.place, $3.place, $$.place);
    }
    | expr LEQ expr 
    { 
        $$.place = new_temp();
        emit("LE", $1.place, $3.place, $$.place);
    }
    | expr EQ expr 
    { 
        $$.place = new_temp();
        emit("EQ", $1.place, $3.place, $$.place);
    }
    | expr NEQ expr 
    { 
        $$.place = new_temp();
        emit("NE", $1.place, $3.place, $$.place);
    }
    | LPAREN expr RPAREN 
    { 
        $$.place = $2.place;
        $$.code = $2.code;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s near '%s'\n", yylineno, s, yytext);
    exit(1);
}

int main(int argc, char* argv[]) {
    printf("Starting compiler for custom language...\n");
    
    /* If filename provided, read from file */
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open input file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    /* Parse input */
    yyparse();
    
    printf("Parsing completed successfully.\n");
    return 0;
}