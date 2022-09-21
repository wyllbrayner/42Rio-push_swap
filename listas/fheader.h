#ifndef FHEADER_H
# define FHEADER_H

# include "dheader.h"

typedef struct _queue Queue;

Queue *Queue_create();
void Queue_destroy(Queue **Q_ref);
bool Queue_is_empty(const Queue *S);
size_t Queue_size(const Queue *S);
void Queue_enqueue(Queue *Q, int val);
int Queue_peek(const Queue *Q);
int Queue_deenqueue(Queue *Q);
void Queue_print(const Queue *Q);
void Queue_inverted_print(const Queue *Q);

#endif