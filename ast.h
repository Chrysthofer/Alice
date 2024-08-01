#ifndef AST_H
#define AST_H

typedef struct ASTNode {
    int type;
    struct ASTNode *left;
    struct ASTNode *right;
    union {
        int ival;
        char *sval;
    } value;
} ASTNode;

ASTNode *create_node(int type, ASTNode *left, ASTNode *right, int ival, char *sval);
void generate_code(ASTNode *node);

#endif // AST_H
