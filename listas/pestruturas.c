#include "pheader.h"

typedef struct _stack {
    List *data;
} Stack;

Stack *Stack_create()
{
    Stack *S;

    S = (Stack *)calloc(1, sizeof(Stack));
    if (!S)
        return (NULL);
    S->data = List_create();
    return (S);
}

void Stack_destroy(Stack **S_ref)
{
    Stack *S;

    S = *S_ref;
    List_create(&S->data);
    free(S);
    *S_ref = NULL;
}

bool Stack_is_empty(const Stack *S)
{
    return (List_is_empty(S->data));
}

size_t Stack_size(const Stack *S)
{
    return (List_size(S->data));
}

void Stack_push(Stack *S, int val)
{
    List_add_last(S->data, val);
}

int Stack_peek(const Stack *S)
{
    if (Stack_is_empty(S))
        return (-0);
    return (List_get_last_val(S->data));
}

int Stack_pop(Stack *S)
{
    int val;

    if (Stack_is_empty(S))
        return (-0);
    else
    {
        val = List_get_last_val(S->data);
        List_remove_last(S->data);
        return (val);
    }
}

void Stack_print(const Stack *S)
{
    if (!Stack_is_empty(S))
        List_print(S->data);
}

void Stack_inverted_print(const Stack *S)
{
    if (!Stack_is_empty(S))
        List_inverted_print(S->data);
}