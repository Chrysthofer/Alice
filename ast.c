#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include <stdbool.h>
#include "parser.tab.h"

FILE *outfile;

ASTNode *create_node(int type, ASTNode *left, ASTNode *right, ASTNode *back, ASTNode *forth, int ival, float fval, double dval, char *sval)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;
    node->back = back;
    node->forth = forth;
    if (sval)
    {
        node->value.sval = strdup(sval);
    }
    else if (type == 'FLN')
    {
        node->value.fval = fval;
    }
    else if (type == 'DBN')
    {
        node->value.dval = dval;
    }
    else if (type == 'INTN')
    {
        node->value.ival = ival;
    }
    return node;
}

static int labelCount = 0; // Global static variable to maintain label count
int acc_state = 0;
int stk_state = 0;

bool is_operator(int type) {
    switch (type) {
        case '+':
        case '/':
        case '-':
        case '*':
            return true;
        default:
            return false;
    }
}

char *format_float(double value)
{
    char buffer[50];
    // Format the float with a maximum of 15 decimal places
    snprintf(buffer, sizeof(buffer), "%.10f", value);

    // Remove trailing zeros and the decimal point if it's unnecessary
    char *end = buffer + strlen(buffer) - 1;
    while (end > buffer && *end == '0')
    {
        end--;
    }
    if (*end == '.')
    {
        end--;
    }
    *(end + 1) = '\0';

    return strdup(buffer);
}

void generate_code(ASTNode *node)
{
    if (!node)
        return;
    switch (node->type)
    {
    case 'RTN':
        // Process the root node
        generate_code(node->left);
        fprintf(outfile, "ROOT");
        break;
    case ';':
        generate_code(node->left);
        generate_code(node->right);
        break;
    case '+':
        if (node->left != NULL && is_operator(node->left->type))
        {
            generate_code(node->left); // Recur on left subtree
            if (node->right->type == 'INTN')
            {
                fprintf(outfile, "PLD %d\n", node->right->value.ival); // Load next value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'I')
            {
                fprintf(outfile, "PLD %s\n", node->right->value.sval); // Load next value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'DBN')
            {
                char *formatted = format_float(node->right->value.dval); // Fix: Use node->right->value.dval
                fprintf(outfile, "PLD %s\n", formatted);                 // Load next value onto the stack
                stk_state = 1;
                free(formatted);
            }
            if (stk_state == 1)
            {
                fprintf(outfile, "SADD\n"); // Add the stack value to the accumulator
                stk_state = 0;
            }
        }
        else
        {

            generate_code(node->left);
            generate_code(node->right);
            if (node->right->type == 'INTN')
            {
                fprintf(outfile, "ADD %d\n", node->right->value.ival); // Load next value onto the stack
            }
            else if (node->right->type == 'I')
            {
                fprintf(outfile, "ADD %s\n", node->right->value.sval); // Load next value onto the stack
            }
            else if (node->right->type == 'DBN')
            {
                char *formatted = format_float(node->right->value.dval); // Fix: Use node->right->value.dval
                fprintf(outfile, "ADD %s\n", formatted);                 // Load next value onto the stack
                free(formatted);
            }
            
        }
        acc_state = 1;
        break;

    case '-':
    {
        // Check if the left operand is also a subtraction operation (e.g., a - b - c)
        if (node->left != NULL && node->left->type == '-')
        {
            // Recursively handle the left subtree (this ensures correct ordering of operations)
            generate_code(node->left);

            // Load and negate the right operand
            if (node->right->type == 'INTN')
            {
                fprintf(outfile, "PLD %d\n", node->right->value.ival); // Load integer value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'I')
            {
                fprintf(outfile, "PLD %s\n", node->right->value.sval); // Load float value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'DBN')
            {
                char *formatted = format_float(node->right->value.dval); // Format double value
                fprintf(outfile, "PLD %s\n", formatted);                 // Load double value onto the stack
                stk_state = 1;
                free(formatted);
            }

            fprintf(outfile, "NEG\n"); // Negate the loaded value
            if (stk_state == 1)
            {
                fprintf(outfile, "SADD\n"); // Subtract the negated value from the accumulator
                stk_state = 0;
            }
        }
        else
        {
            // Handle the first subtraction operation (e.g., a - b)
            if (node->right->type == 'INTN')
            {
                fprintf(outfile, "LOAD %d\n", node->right->value.ival); // Load integer value onto the stack
            }
            else if (node->right->type == 'I')
            {
                fprintf(outfile, "LOAD %s\n", node->right->value.sval); // Load float value onto the stack
            }
            else if (node->right->type == 'DBN')
            {
                char *formatted = format_float(node->right->value.dval); // Format double value
                fprintf(outfile, "LOAD %s\n", formatted);                // Load double value onto the stack
                free(formatted);
            }

            fprintf(outfile, "NEG\n"); // Negate the right operand

            if (node->left->type == 'INTN')
            {
                fprintf(outfile, "ADD %d\n", node->left->value.ival); // Subtract integer value from the accumulator
            }
            else if (node->left->type == 'I')
            {
                fprintf(outfile, "ADD %s\n", node->left->value.sval); // Subtract float value from the accumulator
            }
            else if (node->left->type == 'DBN')
            {
                char *formatted = format_float(node->left->value.dval); // Format double value
                fprintf(outfile, "ADD %s\n", formatted);                // Subtract double value from the accumulator
                free(formatted);
            }
        }
        acc_state = 1; // Update the accumulator state
        break;
    }

    case '++':
    {
        // Handle increment operation
        fprintf(outfile, "LOAD %s\n", node->value.sval);
        fprintf(outfile, "LOAD 1\n");
        fprintf(outfile, "ADD R0, R1\n");
        fprintf(outfile, "SET %s\n", node->value.sval);
        break;
    }
    case '--':
    {
        // Handle decrement operation
        fprintf(outfile, "LOAD %s\n", node->value.sval);
        fprintf(outfile, "LOAD 1\n");
        fprintf(outfile, "SUB R0, R1\n");
        fprintf(outfile, "SET %s\n", node->value.sval);
        break;
    }
    case '*':
        if (node->left != NULL && node->left->type == '*')
        {
            generate_code(node->left); // Recur on left subtree

            // Handle the right operand based on its type
            if (node->right->type == 'INTN')
            {
                fprintf(outfile, "PLD %d\n", node->right->value.ival); // Load int value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'I')
            {
                fprintf(outfile, "PLD %s\n", node->right->value.sval); // Load float value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'DBN')
            {
                char *formatted = format_float(node->right->value.dval); // Format the double value
                fprintf(outfile, "PLD %s\n", formatted);                 // Load double value onto the stack
                stk_state = 1;
                free(formatted);
            }

            if (stk_state == 1)
            {
                fprintf(outfile, "SMLT\n"); // Multiply stack value with accumulator
                stk_state = 0;
            }
        }
        else
        {
            generate_code(node->left); // Handle the leftmost operand
            generate_code(node->right);

            if (stk_state == 1)
            {
                fprintf(outfile, "SMLT\n"); // Multiply stack value with accumulator
                stk_state = 0;
            }

            // Handle the right operand based on its type
            if (node->right->type == 'INTN')
            {
                fprintf(outfile, "MLT %d\n", node->right->value.ival); // Multiply with int value
            }
            else if (node->right->type == 'I')
            {
                fprintf(outfile, "MLT %s\n", node->right->value.sval); // Multiply with float value
            }
            else if (node->right->type == 'DBN')
            {
                char *formatted = format_float(node->right->value.dval); // Format the double value
                fprintf(outfile, "MLT %s\n", formatted);                 // Multiply with double value
                free(formatted);
            }
        }

        acc_state = 1; // Set accumulator state to indicate it's in use
        break;

    case '/':
        if (node->left != NULL && is_operator(node->left->type))
        {
            generate_code(node->left); // Recur on left subtree

            // Handle the right operand based on its type
            if (node->right->type == 'INTN')
            {
                fprintf(outfile, "PLD %d\n", node->right->value.ival); // Load int value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'I')
            {
                fprintf(outfile, "PLD %s\n", node->right->value.sval); // Load float value onto the stack
                stk_state = 1;
            }
            else if (node->right->type == 'DBN')
            {
                char *formatted = format_float(node->right->value.dval); // Format the double value
                fprintf(outfile, "PLD %s\n", formatted);                 // Load double value onto the stack
                stk_state = 1;
                free(formatted);
            }
            if (stk_state == 1)
            {

                fprintf(outfile, "SDIV\n"); // Divide stack value by the accumulator
                stk_state = 0;
            }
        }
        else
        {
            generate_code(node->right); // Handle the leftmost operand
            // Handle the right operand based on its type
            if (node->left->type == 'INTN')
            {
                fprintf(outfile, "DIV %d\n", node->left->value.ival); // Divide accumulator by int value
            }
            else if (node->left->type == 'I')
            {
                fprintf(outfile, "DIV %s\n", node->left->value.sval); // Divide accumulator by float value
            }
            else if (node->left->type == 'DBN')
            {
                char *formatted = format_float(node->left->value.dval); // Format the double value
                fprintf(outfile, "DIV %s\n", formatted);                // Divide accumulator by double value
                free(formatted);
            }
        }

        acc_state = 1; // Set accumulator state to indicate it's in use
        break;

    case '%':
        generate_code(node->left);
        generate_code(node->right);
        fprintf(outfile, "MOD\n");
        break;
    case '<':
        // generate_code(node->left);
        generate_code(node->right);
        fprintf(outfile, "LES %s\n", node->left->value.sval);
        break;
    case '>':
        generate_code(node->left);
        generate_code(node->right);
        fprintf(outfile, "GT\n");
        break;
    case '>=':
        generate_code(node->left);
        generate_code(node->right);
        fprintf(outfile, "GE\n");
        break;
    case '<=':
        generate_code(node->left);
        generate_code(node->right);
        fprintf(outfile, "LE\n");
        break;
    case '=':
        generate_code(node->right);
        fprintf(outfile, "SET %s\n", node->value.sval);
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
        generate_code(node->right); // Evaluate right side
        fprintf(outfile, "AND\n");  // Apply AND operation
        break;
    case '||':
    {
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
    case 'FUNC':
    {
        // Function label
        fprintf(outfile, "FUNC %s\n", node->value.sval);

        // Push function parameters in reverse order
        if (node->left)
        {
            // Collect parameters in a stack
            ASTNode *params = node->left;
            // Push parameters in reverse order
            while (params)
            {
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
    case 'I': // Identifier
    {
        // Only load the variable if the accumulator is empty (acc_state == 0)
        if (acc_state == 0)
        {
            fprintf(outfile, "LOAD %s\n", node->value.sval);
            acc_state = 1; // Set the accumulator state to indicate it's in use
        }
        else if (stk_state == 0)
        {
            // If the accumulator is already in use, push the variable onto the stack
            fprintf(outfile, "PLD %s\n", node->value.sval);
            // Update the stack state to indicate a variable was pushed
            stk_state = 1; // Example state change; adjust as needed
        }
        break;
    }

    case 'INTN':
    {
        // Only load the variable if the accumulator is empty (acc_state == 0)
        if (acc_state == 0)
        {
            fprintf(outfile, "LOAD %d\n", node->value.ival);
            acc_state = 1; // Set the accumulator state to indicate it's in use
        }
        else
        {
            // If the accumulator is already in use, push the variable onto the stack instead
            fprintf(outfile, "PLD %d\n", node->value.ival);
        }
        break;
    }
    case 'FLN':
    {
        if (acc_state == 0)
        {
            // Handle double-precision number formatting
            char *formatted = format_float(node->value.fval);
            fprintf(outfile, "LOAD %s\n", formatted);
            free(formatted);
        }
        else
        {
            char *formatted = format_float(node->value.fval);
            fprintf(outfile, "PLD %s\n", formatted);
            free(formatted);
        }
        break;
    }
    case 'DBN':
    {
        if (acc_state == 0)
        {
            // Handle double-precision number formatting
            char *formatted = format_float(node->value.dval);
            fprintf(outfile, "LOAD %s\n", formatted);
            free(formatted);
        }
        else
        {
            char *formatted = format_float(node->value.dval);
            fprintf(outfile, "PLD %s\n", formatted);
            free(formatted);
        }
        break;
    }
    case 'R':
    {
        // Return statement
        generate_code(node->left);
        fprintf(outfile, "RETURN\n");
        break;
    }
    case 'IF':
    {
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
    case 'E':
    {
        int elseLabel = labelCount++;
        int endLabel = labelCount++;

        generate_code(node->left); // Condition
        fprintf(outfile, "CMP R0, 0\n");
        fprintf(outfile, "JE L%d\n", elseLabel);

        generate_code(node->right); // If body

        fprintf(outfile, "JMP L%d\n", endLabel);
        fprintf(outfile, "L%d:\n", elseLabel);

        generate_code(node->back); // Else body

        fprintf(outfile, "L%d:\n", endLabel);
        break;
    }
    case 'W':
    { // While loop
        int startLabel = 1 + labelCount++;
        int endLabel = labelCount++;

        fprintf(outfile, "@L%d ", startLabel);

        generate_code(node->left); // Condition
        fprintf(outfile, "JZ L%dend\n", endLabel);

        generate_code(node->right); // Body

        fprintf(outfile, "JMP L%d\n", startLabel);
        fprintf(outfile, "@L%dend\n", endLabel);
        break;
    }
    case 'F':
    { // For loop
        int startLabel = labelCount++;
        int endLabel = labelCount++;
        int continueLabel = labelCount++;

        generate_code(node->left); // Initialization

        fprintf(outfile, "L%d:\n", startLabel);

        generate_code(node->right); // Condition
        fprintf(outfile, "CMP R0, 0\n");
        fprintf(outfile, "JE L%d\n", endLabel);

        generate_code(node->forth); // Body

        generate_code(node->back); // Increment

        fprintf(outfile, "JMP L%d\n", startLabel);
        fprintf(outfile, "L%d:\n", endLabel);
        break;
    }
    case 'B':
        fprintf(outfile, "LOAD %d\n", node->value.ival);
        break;
    default:
        fprintf(outfile, "UNKNOWN OPERATION\n");
        break;
    }
}

void generate_code_from_ast(ASTNode *node)
{
    outfile = fopen("test.asm", "w");
    if (!outfile)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if (node)
    {
        generate_code(node);
    }
    else
    {
        fprintf(outfile, "No AST generated.\n");
    }

    fclose(outfile);
}