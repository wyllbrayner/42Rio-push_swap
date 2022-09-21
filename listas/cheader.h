#ifndef CHEADER_H
# define CHEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;

CircNode *CircNode_create(int val);
void CircNode_destroy(CircNode **cnode_ref);

CircList *CircList_create();
void CircList_destroy(CircList **L_ref);
bool CircList_is_empty(const CircList *L);

void CircList_add_first(CircList *L, int val);
void CircList_print(const CircList *L);
void CircList_inverted_print(const CircList *L);
void CircList_add_last(CircList *L, int val);
size_t CircList_size(const CircList *L);
void CircList_remove(CircList *L, int val);

#endif