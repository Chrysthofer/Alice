#ifndef AST_H
#define AST_H

typedef struct ASTNode {
    int type;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;
    struct ASTNode *fourth;
    union {
        int ival;
        float fval;
        double dval;
        char *sval;
    } value;
} ASTNode;

ASTNode *create_node(int type, ASTNode *left, ASTNode *right, ASTNode *next, ASTNode *fourth, int ival, float fval, double dval, char *sval);
void generate_code(ASTNode *node);

#endif // AST_H
