#include "sheader.h"

typedef struct _snode
{
    int              val;
    struct _snode    *next;
} SNode;

typedef struct _linked_list
{
    SNode   *begin;
    SNode   *end;
    size_t  size;
} LinkedList;

SNode *SNode_create(int val)
{
    SNode *snode = (SNode *)calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return (snode);
}

LinkedList *LinkedList_create()
{
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;
    return (L);
}

void LinkedList_destroy(LinkedList **L_ref)
{
    LinkedList  *L;
    SNode       *p;
    SNode       *tmp;
    
    L = *L_ref;
    p = L->begin;
    tmp = NULL;

    while (p != NULL)
    {
       tmp = p;
       p = p->next;
       free(tmp); 
    }
    free(L);
    *L_ref = NULL;
}

bool LinkedList_is_empty(const LinkedList *L)
{
    return (L->size == 0);
//    return (L->begin == NULL && L->end == NULL);
}

void LinkedList_add_first(LinkedList *L, int val)
{
//    printf("L->begin == NULL %d\n", L->begin == NULL);
//    printf("L->end == NULL %d\n", L->end == NULL);
    SNode *p;

    p = SNode_create(val); //cria o novo nó
    if (!p)
        exit(-1);
    if (LinkedList_is_empty(L)) //se a lista está vazia
    {
        L->begin = p; // insere na lista
        L->end = p; // insere na lista
    }
    else // se a lista não estiver vazia (se já tiver outros nós)
    {
        p->next = L->begin; // linka o nó criado no inicio dos nós existentes 
        L->begin = p; // linka o início ao nó criado.
    }
    L->size++;
//    printf("L->begin == NULL %d\n", L->begin == NULL);
//    printf("L->end == NULL %d\n", L->end == NULL);
}

void LinkedList_add_last_slow(LinkedList *L, int val)
{
    SNode *q;
    SNode *p;

    if (LinkedList_is_empty(L)) //se a lista está vazia
    {
        q = SNode_create(val); //cria o novo nó
        if (!q)
            exit(-1);
        L->begin = q; // insere na lista
    }
    else // se a lista não estiver vazia (se já tiver outros nós)
    {
        q = SNode_create(val); //cria o novo nó
        if (!q)
            exit(-1);
        p = L->begin; // ponteiro p aponta para o início da lista

        while (p->next != NULL) //verifica se há um próximo ponteiro no nó.
        {
            p = p->next; // desloca o ponteiro para o próximo nó da lista.
        }
        p->next = q; // quando sair do loop, é porque p chegou no último nó e p recebe q.
    }
    L->size++;
}

void LinkedList_add_last(LinkedList *L, int val)
{
    SNode *q;

    if (LinkedList_is_empty(L)) //se a lista está vazia
    {
        q = SNode_create(val); //cria o novo nó
        if (!q)
            exit(-1);
        L->begin = q; // insere no início da lista
        L->end = q; // insere n final da lista
    }
    else // se a lista não estiver vazia (se já tiver outros nós)
    {
        q = SNode_create(val); //cria o novo nó
        if (!q)
            exit(-1);
        L->end->next = q; //aponta o ponteiro next do último ponteiro para q.  
        L->end = q; // (ou) aponta o ponteiro para o último nó da lista para o novo último nó. 
//        L->end = L->end->next; // aponta o ponteiro para o último nó da lista para o novo último nó.
    }
    L->size++;
}

void LinkedList_print(const LinkedList *L)
{
    SNode *p;

    p = L->begin;
    printf("L -> ");
    while (p != NULL) //enquanto p estiver apontando para um nó
    {
        printf("%d -> ", p->val);
        p = p->next; //mova o ponteiro p para o próximo nó.
    }
    printf("NULL\n");
    if (L->end == NULL)
        printf("L-> end == NULL\n");
    else
        printf("L->end == %d\n", L->end->val);
    printf("Size: %lu\n", L->size);
}

void LinkedList_remove(LinkedList *L, int val)
{
    if (!LinkedList_is_empty(L))
    {
        SNode *prev;
        SNode *pos;

        prev = NULL;
        pos = L->begin;
        while (pos != NULL && pos->val != val) // percorre a lista enquanto o valor atual for diferente do valor procurado e enquanto o próximo ponteiro não for nulo;
        {
            prev = pos; 
            pos = pos->next;
        }
        if (pos != NULL) //se "pos" for diferente de NULL, é porque saiu do loop por ter identificado o valor. 
        {
            if (L->end == pos)
                L->end = prev; // o ponteiro end da lista passa a apontar para o nó previo.
            if (L->begin == pos)
                L->begin = L->begin->next;
            else
                prev->next = pos->next;
            free(pos);
            L->size--;
        }
    }
}

/*
void LinkedList_remove(LinkedList *L, int val)
{
    if (!LinkedList_is_empty(L))
    {
        if (L->begin->val == val) // 1º caso: O elemento está na cabeça da lista.
        {
            SNode *pos;
            pos = L->begin;

            if (L->begin == L->end) //ferifica se a lista possui apenas um elemento
                L->end = NULL; // possuindo apenas um elemento, o ponteiro end passa a apontar para NULL.
            L->begin = L->begin->next;
            free(pos);
        }
        else // 2º caso: o elemento está no meio da lista.
        {
            SNode *prev;
            SNode *pos;

            prev = L->begin;
            pos = L->begin->next;
            while (pos != NULL && pos->val != val) // percorre a lista enquanto o valor atual for diferente do valor procurado e enquanto o próximo ponteiro não for nulo;
            {
                prev = prev->next;
                pos = pos->next;
            }
            //ao sair do loop, é necessário verificar qual das condições fez a parada do loop (se a lista encerrou pos == NULL ou se identificou o valor).  
            if (pos != NULL) //se "pos" for diferente de NULL, é porque saiu do loop por ter identificado o valor. 
            {
                prev->next = pos->next; // aponta o próximo ponteiro de prev para o ponteiro seguinte de pós. Liverando o Nó pós par liberação.
                if (pos->next == NULL) // removendo o último elemento da lista.
                    L->end = prev; // o ponteiro end da lista passa a apontar para o nó previo.
                free(pos); // libera o nó.
                L->size++;
            }
        }
    }
}
*/

size_t LinkedList_size_slow(const LinkedList *L)
{
    SNode *p;
    size_t len;

    p = L->begin;
    len = 0;

    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return (len);
}

size_t LinkedList_size(const LinkedList *L)
{
    return (L->size);
}

int LinkedList_first_val(const LinkedList *L)
{
    if (LinkedList_is_empty(L))
        return (-1);
    return (L->begin->val);
}

int LinkedList_last_val(const LinkedList *L)
{
    if (LinkedList_is_empty(L))
        return (-1);
    return (L->end->val);

}

int LinkedList_get_val(const LinkedList *L, size_t index)
{
    if (LinkedList_is_empty(L))
        return (-1);
    else if (index < 0 || index > L->size)
        return (-2);
    else
    {
        size_t i;
        SNode *p;

        i = 0;
        p = L->begin;
        while (i < index)
        {
            i++;
            p = p->next;
        }
        return (p->val);
    }
}