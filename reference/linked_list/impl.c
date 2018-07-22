#include "linked_list.h"

int linked_list_init(linked_node_t *head, value_t value) {
    head->value = value;
    head->prev = NULL;
    head->next = NULL;
    return 0;
}

int linked_list_free(linked_node_t *head) {
    linked_node_t *node = head->next, *prev = NULL;
    while (node) {
        if (prev) {
            free(prev);
        }
        prev = node;
        node = node->next;
    }
    if (prev) {
        free(prev);
    }
    head->next = NULL;
    head->prev = NULL;
    return 0;
}

linked_node_t* linked_list_append(linked_node_t *head, value_t value) {
    while (head->next != NULL) {
        head = head->next;
    }
    return linked_list_insert(head, value);
}

linked_node_t* linked_list_insert(linked_node_t *head, value_t value) {
    linked_node_t *extra = calloc(1, sizeof(linked_node_t));
    if (head->next != NULL) {
        linked_node_t *after = head->next;
        after->prev = extra;
        extra->next = after;
    }
    extra->value = value;
    head->next = extra;
    extra->prev = head;
    return extra;
}

int linked_list_remove(linked_node_t *head) {
    if (head->next) {
        head->next->prev = head->prev;
    }
    if (head->prev) {
        head->prev->next = head->next;
    }
    return 0;
}

