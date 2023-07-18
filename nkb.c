#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,        // Addition operation
    SUB,        // Subtraction operation
    MUL,        // Multiplication operation
    FIBO,       //FIBO SEQU
    INVALID     // Invalid operation
} TypeTag;


typedef struct Node
{
    TypeTag type;
    int value;
} Node;

Node* makeFunc(TypeTag tag)
{
    Node* result = (Node*)malloc(sizeof(Node));
    result->type = tag;
    return result;
}

Node* executeOperation(TypeTag tag, Node* operand1, Node* operand2)
{
    Node* result = (Node*)malloc(sizeof(Node));
    result->type = tag;

    if (operand1 == NULL || operand2 == NULL)
    {
        result->value = 0;
        return result;
    }

    switch (tag)
    {
        case ADD:
            result->value = operand1->value + operand2->value;
            break;
        case SUB:
            result->value = operand1->value - operand2->value;
            break;
        case MUL:
            result->value = operand1->value * operand2->value;
            break;
        default:
            result->type = INVALID;
            result->value = 0;
            break;
    }

    return result;
}

void calc(Node* node)
{
    switch (node->type)
    {
        case ADD:
            printf("add : %d\n", node->value);
            break;
        case SUB:
            printf("sub : %d\n", node->value);
            break;
        case MUL:
            printf("mul : %d\n", node->value);
            break;
        case FIBO:
            printf("fibo : %d\n", node->value);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }
}


{
    Node *add = makeFunc(ADD);
    add->value = 10 + 6;

    Node *mul = makeFunc(MUL);
    mul->value = 5 * 4;

    Node *sub = makeFunc(SUB);
    sub->value = add->value - mul->value;

    Node *fibo = makeFunc(FIBO);
    fibo->value = sub->value + 6;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
