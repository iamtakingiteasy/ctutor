#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

// value this linked list nodes are holding
typedef int value_t;

// double-linked list node
typedef struct linked_node_t {
    value_t value;
    struct linked_node_t *next;
    struct linked_node_t *prev;
} linked_node_t;

// initialize empty head
int linked_list_init(linked_node_t *head, value_t value);

// deinitialize head, all subsequent nodes and de-allocate all after the head
int linked_list_free(linked_node_t *head);

// allocate new node with given value, place after the last node in given head-chain and return this new node
linked_node_t* linked_list_append(linked_node_t *head, value_t value);

// allocate new node with given value, place directly after given node and return this new node
linked_node_t* linked_list_insert(linked_node_t *head, value_t value);

// remove given node, fix broken chain if any, do not de-allocate given node
int linked_list_remove(linked_node_t *head);

void linked_list_tests();
#endif
