#include "cheader.h"

typedef struct _circ_node
{
    int                     val;
    struct _circ_node     *prev;
    struct _circ_node     *next;
} CircNode;

typedef struct _circ_list
{
    CircNode    *begin;
    CircNode    *end;
    size_t      size;
} CircList;

CircNode *CircNode_create(int val)
{
    CircNode *cnode;

    cnode = (CircNode *)calloc(1, sizeof(CircNode));
    if (!cnode)
        return (NULL);
    cnode->val = val;
    cnode->prev = cnode;
    cnode->next = cnode;
    return (cnode);
}

void CircNode_destroy(CircNode **cnode_ref)
{
    CircNode *cnode;

    cnode = *cnode_ref;
    free(cnode);
    *cnode_ref = NULL;
}

CircList *CircList_create()
{
    CircList *L;

    L = (CircList *)calloc(1, sizeof(CircList));
    if (!L)
        return (NULL);
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;
    return (L);
}

void CircList_destroy(CircList **L_ref)
{
    CircList *L;
    CircNode *p;
    CircNode *tmp;

    L = *L_ref;
    p = L->begin;
    tmp = NULL;

    while (p != L->end)
    {
        tmp = p;
        p = p->next;
        CircNode_destroy(&tmp);
    }
    CircNode_destroy(&p);
    free(L);
    *L_ref = NULL;
}

bool CircList_is_empty(const CircList *L)
{
    return (L->size == 0);
}

void CircList_add_first(CircList *L, int val)
{
    CircNode *p;

    p = CircNode_create(val); //cria o novo nó
    if (!p)
        exit(-1);
    if (CircList_is_empty(L)) //se a lista está vazia
    {
        L->begin = p; // insere na lista
        L->end = p; // insere na lista
    }
    else // se a lista não estiver vazia (se já tiver outros nós)
    {
        p->next = L->begin; // linka o nó criado no inicio dos nós existentes 
        L->begin->prev = p; // linka o ponteiro prev dp elemento já existênte ao nó criado.
        L->begin = p; // linka o início ao nó criado.
        p->prev = L->end;
        L->end->next = p;
    }
    L->size++;
}

void CircList_print(const CircList *L)
{
    if (CircList_is_empty(L)) //se a lista está vazia
    {
        printf("L -> NULL\n");
        printf("L->end -> NULL\n");
    }
    else
    {
        CircNode *p;

        p = L->begin;
        printf("L -> ");
        printf("%d -> ", p->val); //imprime o primeiro nó
        p = p->next; //mova o ponteiro p para o próximo nó.
        while (p != L->begin) //enquanto p estiver apontando para um nó diferente do inicio (já impresso).
        {
            printf("%d -> ", p->val);
            p = p->next; //mova o ponteiro p para o próximo nó.
        }
        printf("\nL-> end -> %d\n", L->end->val);
    }
    printf("Size: %lu\n", L->size);
}

void CircList_inverted_print(const CircList *L)
{
    if (CircList_is_empty(L)) //se a lista está vazia
    {
        printf("L -> NULL\n");
        printf("L->end -> NULL\n");
    }
    else
    {
        CircNode *p;

        p = L->end;
        printf("L -> ");
        printf("%d -> ", p->val); //imprime o primeiro nó
        p = p->prev; //mova o ponteiro p para o próximo nó.
        while (p != L->end) //enquanto p estiver apontando para um nó diferente do inicio (já impresso).
        {
            printf("%d -> ", p->val);
            p = p->prev; //mova o ponteiro p para o próximo nó.
        }
        printf("\nL-> begin -> %d\n", L->begin->val);
    }
    printf("Size: %lu\n", L->size);
}

void CircList_add_last(CircList *L, int val)
{
    CircNode *p;

    p = CircNode_create(val); //cria o novo nó
    if (!p)
        exit(-1);
    if (CircList_is_empty(L)) //se a lista está vazia
    {
        L->begin = p; // insere na lista
        L->end = p; // insere na lista
    }
    else // se a lista não estiver vazia (se já tiver outros nós)
    {
        L->end->next = p;
        p->prev = L->end;
        L->end = p;
        L->begin->prev = p;
        p->next = L->begin;
    }
    L->size++;
}

size_t CircList_size(const CircList *L)
{
    return (L->size);
}

void CircList_remove(CircList *L, int val)
{ 
    if (!CircList_is_empty(L))
    {
        CircNode *p;

        if (L->begin->val == val)
        {
            p = L->begin;
            if (CircList_size(L) == 1)
            {
                L->begin = NULL;
                L->end = NULL;
            }
            else
            {
                L->begin = p->next;
                L->begin->prev = L->end;
                L->end->next = L->begin;
            }
            CircNode_destroy(&p);
            L->size--;
        }
        else
        {
            p = L->begin->next;           
            while (p != L->begin)
            {
                if (p->val == val)
                {
                    if (L->end == p)
                    {
                        L->end = p->prev;
                        L->end->next = L->begin;
                        L->begin->prev = L->end;
                    }
                    else
                    {
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                    }
                    CircNode_destroy(&p);
                    L->size--;
                    break ; //necessário para forçar a saída do loop, caso contrário acessará um ponteiro inválido para p.
                }
                else
                    p = p->next;
            }
        }
    }
}