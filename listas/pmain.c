#include "pheader.h"

int main()
{
    Stack *S;
    S = Stack_create();
    Stack_push(S, 7);
    Stack_push(S, 5);
    Stack_print(S);
    
    Stack_pop(S);
    Stack_print(S);
    Stack_pop(S);
    Stack_print(S);
    Stack_pop(S);
    Stack_print(S);
    Stack_pop(S);
    Stack_print(S);
    Stack_inverted_print(S);
    Stack_destroy(&S);
    printf("L == NULL: %d\n", S == NULL);
    return (0);
}