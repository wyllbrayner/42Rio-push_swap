#include "fheader.h"

int main()
{
    Queue *Q;
    Q = Queue_create();

    Queue_enqueue(Q, 7);
    Queue_enqueue(Q, 5);
    Queue_print(Q);
    
    printf("%d\n", Queue_peek(Q));

    Queue_deenqueue(Q);
    Queue_print(Q);
    Queue_deenqueue(Q);
    Queue_print(Q);
    Queue_deenqueue(Q);
    Queue_print(Q);
    Queue_inverted_print(Q);
    Queue_destroy(&Q);
    printf("L == NULL: %d\n", Q == NULL);
    return (0);
}