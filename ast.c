#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"  // Include the generated header

FILE *outfile;

ASTNode *create_node(int type, ASTNode *left, ASTNode *right, int ival, char *sval) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;
    if (sval) {
        node->value.sval = strdup(sval);
    } else {
        node->value.ival = ival;
    }
    return node;
}

void generate_code(ASTNode *node) {
    if (!node) return;
    printf("Generating code for node type: %d\n", node->type);
    switch (node->type) {
        case ';':
            generate_code(node->left);
            generate_code(node->right);
            break;
        case '+':
            generate_code(node->left);
            generate_code(node->right);
            printf("ADD R0, R1\n");
            fprintf(outfile, "ADD R0, R1\n");
            break;
        case '-':
            generate_code(node->left);
            generate_code(node->right);
            printf("SUB R0, R1\n");
            fprintf(outfile, "SUB R0, R1\n");
            break;
        case '*':
            generate_code(node->left);
            generate_code(node->right);
            printf("MUL R0, R1\n");
            fprintf(outfile, "MUL R0, R1\n");
            break;
        case '/':
            generate_code(node->left);
            generate_code(node->right);
            printf("DIV R0, R1\n");
            fprintf(outfile, "DIV R0, R1\n");
            break;
        case '<':
            generate_code(node->left);
            generate_code(node->right);
            printf("LT R0, R1\n");
            fprintf(outfile, "LT R0, R1\n");
            break;
        case '>':
            generate_code(node->left);
            generate_code(node->right);
            printf("GT R0, R1\n");
            fprintf(outfile, "GT R0, R1\n");
            break;
        case LE:
            generate_code(node->left);
            generate_code(node->right);
            printf("LE R0, R1\n");
            fprintf(outfile, "LE R0, R1\n");
            break;
        case GE:
            generate_code(node->left);
            generate_code(node->right);
            printf("GE R0, R1\n");
            fprintf(outfile, "GE R0, R1\n");
            break;
        case '=':
            generate_code(node->right);
            printf("STORE %s\n", node->value.sval);
            fprintf(outfile, "STORE %s\n", node->value.sval);
            break;
        case 'I':
            printf("LOAD %s\n", node->value.sval);
            fprintf(outfile, "LOAD %s\n", node->value.sval);
            break;
        case 'N':
            printf("CONST %d\n", node->value.ival);
            fprintf(outfile, "CONST %d\n", node->value.ival);
            break;
        case 'R':
            generate_code(node->left);
            printf("RETURN\n");
            fprintf(outfile, "RETURN\n");
            break;
        default:
            printf("Unknown node type: %d\n", node->type);
            break;
    }
}

void generate_code_from_ast(ASTNode *node) {
    outfile = fopen("test.asm", "w");
    if (!outfile) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if (node) {
        printf("Generating code...\n");
        generate_code(node);
    } else {
        printf("No AST generated.\n");
    }

    fclose(outfile);
}
