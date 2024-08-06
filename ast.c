#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"

FILE *outfile;

ASTNode *create_node(int type, ASTNode *left, ASTNode *right, ASTNode *next, ASTNode *fourth, int ival, char *sval) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;
    node->next = next;
    node->fourth = fourth;
    if (sval) {
        node->value.sval = strdup(sval);
    } else {
        node->value.ival = ival;
    }
    return node;
}

static int labelCount = 0; // Global static variable to maintain label count

void generate_code(ASTNode *node) {
    if (!node) return;
    switch (node->type) {
        case ';':
            generate_code(node->left);
            generate_code(node->right);
            break;
        case '+':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "ADD R0, R1\n");
            break;
        case '++': {
            // Handle increment operation
            fprintf(outfile, "LOAD %s\n", node->value.sval);
            fprintf(outfile, "CONST 1\n");
            fprintf(outfile, "ADD R0, R1\n");
            fprintf(outfile, "STORE %s\n", node->value.sval);
            break;
        }
        case '--': {
            // Handle increment operation
            fprintf(outfile, "LOAD %s\n", node->value.sval);
            fprintf(outfile, "CONST 1\n");
            fprintf(outfile, "SUB R0, R1\n");
            fprintf(outfile, "STORE %s\n", node->value.sval);
            break;
        }
        case '-':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "SUB R0, R1\n");
            break;
        case '*':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "MUL R0, R1\n");
            break;
        case '/':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "DIV R0, R1\n");
            break;
        case '<':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "LT R0, R1\n");
            break;
        case '=':
            generate_code(node->right);
            fprintf(outfile, "STORE %s\n", node->value.sval);
            break;
        case 'I':
            fprintf(outfile, "LOAD %s\n", node->value.sval);
            break;
        case 'N':
            fprintf(outfile, "CONST %d\n", node->value.ival);
            break;
        case 'R':
            generate_code(node->left);
            fprintf(outfile, "RETURN\n");
            break;
        case 'IF': {
            int elseLabel = labelCount++;
            int endLabel = labelCount++;

            generate_code(node->left); // Condition
            fprintf(outfile, "CMP R0, 0\n");
            fprintf(outfile, "JE L%d\n", elseLabel);

            generate_code(node->right); // If body

            fprintf(outfile, "JMP L%d\n", endLabel);
            fprintf(outfile, "L%d:\n", elseLabel);

            if (node->next) { // Else part
                generate_code(node->next);
            }

            fprintf(outfile, "L%d:\n", endLabel);
            break;
        }
        case 'E': {
            int elseLabel = labelCount++;
            int endLabel = labelCount++;

            generate_code(node->left); // Condition
            fprintf(outfile, "CMP R0, 0\n");
            fprintf(outfile, "JE L%d\n", elseLabel);

            generate_code(node->right); // If body

            fprintf(outfile, "JMP L%d\n", endLabel);
            fprintf(outfile, "L%d:\n", elseLabel);

            generate_code(node->next); // Else body

            fprintf(outfile, "L%d:\n", endLabel);
            break;
        }
        case 'W': { // While loop
            int startLabel = labelCount++;
            int endLabel = labelCount++;
            
            fprintf(outfile, "L%d:\n", startLabel);

            generate_code(node->left); // Condition
            fprintf(outfile, "CMP R0, 0\n");
            fprintf(outfile, "JE L%d\n", endLabel);

            generate_code(node->right); // Body

            fprintf(outfile, "JMP L%d\n", startLabel);
            fprintf(outfile, "L%d:\n", endLabel);
            break;
        }
        case 'F': { // For loop (general handling)
            int startLabel = labelCount++;
            int endLabel = labelCount++;
            int continueLabel = labelCount++;
            
            generate_code(node->left); // Initialization
            
            fprintf(outfile, "L%d:\n", startLabel);

            generate_code(node->right); // Condition
            fprintf(outfile, "CMP R0, 0\n");
            fprintf(outfile, "JE L%d\n", endLabel);

            generate_code(node->fourth); // Body

            generate_code(node->next); // Increment
            
            fprintf(outfile, "JMP L%d\n", startLabel);
            fprintf(outfile, "L%d:\n", endLabel);
            break;
        }
        default:
            fprintf(outfile, "UNKNOWN OPERATION\n");
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
        generate_code(node);
    } else {
        fprintf(outfile, "No AST generated.\n");
    }

    fclose(outfile);
}
