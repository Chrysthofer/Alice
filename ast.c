#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"

FILE *outfile;

ASTNode *create_node(int type, ASTNode *left, ASTNode *right, ASTNode *next, ASTNode *fourth, int ival, float fval, double dval, char *sval) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;
    node->next = next;
    node->fourth = fourth;
    if (sval) {
        node->value.sval = strdup(sval);
    } else if(type == 'FL'){
        node->value.fval = fval;
    } else if(type == 'DB'){
        node->value.dval = dval;
    } else {
        node->value.ival = ival;
    }
    return node;
}

static int labelCount = 0; // Global static variable to maintain label count

char *format_float(double value) {
    char buffer[50];
    // Format the float with a maximum of 15 decimal places
    snprintf(buffer, sizeof(buffer), "%.15f", value);
    
    // Remove trailing zeros and the decimal point if it's unnecessary
    char *end = buffer + strlen(buffer) - 1;
    while (end > buffer && *end == '0') {
        end--;
    }
    if (*end == '.') {
        end--;
    }
    *(end + 1) = '\0';

    return strdup(buffer);
}

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
            // Handle decrement operation
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
        case '%':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "MOD\n");
            break;
        case '<':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "LT R0, R1\n");
            break;
        case '>':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "GT R0, R1\n");
            break;
        case '=':
            generate_code(node->right);
            fprintf(outfile, "STORE %s\n", node->value.sval);
            break;
        case 'DIF':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "EQU\n");
            fprintf(outfile, "INV\n");
            break;
        case 'IN':
            generate_code(node->left);
            fprintf(outfile, "PUSH\n");
            fprintf(outfile, "IN\n");
            break;
        case 'OUT':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "OUT\n");
            break;
        case 'SEQU':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "SEQU\n");
            break;
        case 'EQU':
            generate_code(node->right);
            fprintf(outfile, "EQU %s\n", node->value.sval); // SEQU uses the identifier directly
            break;
        case '&&':
            generate_code(node->left);  // Evaluate left side
            generate_code(node->right);  // Evaluate right side
            fprintf(outfile, "AND\n");  // Apply AND operation
            break;
        case '||': {
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "OR\n");
            break;
        }
        case '^':
            generate_code(node->left);
            generate_code(node->right);
            fprintf(outfile, "XOR\n");
            break;
        case '/>':
            generate_code(node->left);
            fprintf(outfile, "NORM\n");
            break;
        case 'ARA':
            generate_code(node->left);

            break;
        case 'FUNC': {
            // Function label
            fprintf(outfile, "FUNC %s\n", node->value.sval);

            // Push function parameters in reverse order
            if (node->left) {
                // Collect parameters in a stack
                ASTNode *params = node->left;
                // Push parameters in reverse order
                while (params) {
                    fprintf(outfile, "PUSH %s\n", params->value.sval);
                    params = params->right;
                }
            }

            // Function body
            generate_code(node->right);

            // Return statement at the end of the function
            fprintf(outfile, "RETURN\n");
            break;
        }
        case 'P':
            fprintf(outfile, "PUSH %s\n", node->value.sval);
            break;
        case 'I':
            fprintf(outfile, "LOAD %s\n", node->value.sval);
            break;
        case 'N':
            fprintf(outfile, "CONST %d\n", node->value.ival);
            break;
        case 'FL': {
            // Handle floating-point number formatting
            char *formatted = format_float(node->value.fval);
            fprintf(outfile, "CONST %s\n", formatted);
            free(formatted);
            break;
        }
        case 'DB': {
            // Handle double-precision number formatting
            char *formatted = format_float(node->value.dval);
            fprintf(outfile, "CONST %s\n", formatted);
            free(formatted);
            break;
        }
        case 'R': {
            // Return statement
            generate_code(node->left);
            fprintf(outfile, "RETURN\n");
            break;
        }
        case 'IF': {
            int elseLabel = labelCount++;
            int endLabel = labelCount++;

            generate_code(node->left); // Condition
            fprintf(outfile, "CMP R0, 0\n");
            fprintf(outfile, "JE L%d\n", elseLabel);

            generate_code(node->right); // If body

            fprintf(outfile, "JMP L%d\n", endLabel);
            fprintf(outfile, "L%d:\n", elseLabel);

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
        case 'F': { // For loop
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
        case 'B':
            fprintf(outfile, "CONST %d\n", node->value.ival);
            break;
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
