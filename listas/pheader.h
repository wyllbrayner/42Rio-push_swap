#ifndef PHEADER_H
# define PHEADER_H

# include "dheader.h"

typedef struct _stack Stack;

Stack *Stack_create();
void Stack_destroy(Stack **s_ref);

bool Stack_is_empty(const Stack *S);
size_t Stack_size(const Stack *S);

void Stack_push(Stack *S, int val);
int Stack_peek(const Stack *S);
int Stack_pop(Stack *S);

void Stack_print(const Stack *S);
void Stack_inverted_print(const Stack *S);

#endif