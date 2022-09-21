#include "fheader.h"




typedef struct _queue {
    List *data;
} Queue;

Queue *Queue_create()
{
    Queue *Q;

    Q = (Queue *)calloc(1, sizeof(Queue));
    if (!Q)
        return (NULL);
    Q->data = List_create();
    return (Q);
}

void Queue_destroy(Queue **Q_ref)
{
    Queue *Q;

    Q = *Q_ref;
    List_destroy(&Q->data);
    free(Q);
    *Q_ref = NULL;
}

bool Queue_is_empty(const Queue *Q)
{
    return (List_is_empty(Q->data));
}

size_t Queue_size(const Queue *Q)
{
    return (List_size(Q->data));
}

void Queue_enqueue(Queue *Q, int val)
{
    List_add_last(Q->data, val);
}

int Queue_peek(const Queue *Q)
{
    if (Queue_is_empty(Q))
        return (-0);
    return (List_get_first_val(Q->data));
}

int Queue_deenqueue(Queue *Q)
{
    int val;

    if (Queue_is_empty(Q))
        return (-0);
    val = List_get_first_val(Q->data);
    List_remove_first(Q->data);
    return (val);    
}

void Queue_print(const Queue *Q)
{
    if (!Queue_is_empty(Q))
        List_print(Q->data);
}

void Queue_inverted_print(const Queue *Q)
{
    if (!Queue_is_empty(Q))
        List_inverted_print(Q->data);

}