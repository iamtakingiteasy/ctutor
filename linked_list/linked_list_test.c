#include "linked_list.h"
#include "asserts.h"

#include <stdio.h>

void linked_list_tests() {
    linked_node_t head;
    linked_list_init(&head, 345);

    // [345]
    execute_asserts((assert_t[]){
        { head.value == 345,  "head.value should be initialized" },
        { head.prev  == NULL, "head.prev should be initialized" },
        { head.next  == NULL, "head.next should be initialized" },
        { 0, NULL }
    });

    linked_node_t *next = linked_list_append(&head, 123);

    // [345]-[123]
    execute_asserts((assert_t[]){
        { next        != NULL,  "next must not be null" },
        { 0, NULL }
    });

    execute_asserts((assert_t[]){
        { next->value == 123,   "next.value must be initialized"},
        { next->prev  == &head, "next.prev must be head" },
        { next->next  == NULL,  "next.next must be null" },
        { head.value  == 345,   "head.value should be the same" },
        { head.prev   == NULL,  "head.prev should be null" },
        { head.next   == next,  "head.next should be initialized to next node" },
        { 0, NULL }
    });


    linked_node_t *last = linked_list_append(&head, 999);

    // [345]-[123]-[999]
    execute_asserts((assert_t[]){
        { last        != NULL,  "last must not be null" },
        { 0, NULL }
    });

    execute_asserts((assert_t[]){
        { last->value == 999,   "last.value must be initialized"},
        { last->prev  == next,  "last.prev must be next" },
        { last->next  == NULL,  "last.next must be null" },
        { next->value == 123,   "next.value must be initialized"},
        { next->prev  == &head, "next.prev must be head" },
        { next->next  == last,  "next.next must be last" },
        { head.value  == 345,   "head.value should be the same" },
        { head.prev   == NULL,  "head.prev should be null" },
        { head.next   == next,  "head.next should be initialized to next node" },
        { 0, NULL }
    });


    linked_node_t *extra = linked_list_insert(&head, 666);

    // [345]-[666]-[123]-[999]
    execute_asserts((assert_t[]){
        { extra        != NULL,  "extra must not be null" },
        { 0, NULL }
    });

    execute_asserts((assert_t[]){
        { last->value  == 999,   "last.value must be initialized"},
        { last->prev   == next,  "last.prev must be next" },
        { last->next   == NULL,  "last.next must be null" },
        { next->value  == 123,   "next value must be initialized"},
        { next->prev   == extra, "next.prev must be extra" },
        { next->next   == last,  "next.next must be last" },
        { extra->value == 666,   "extra.value must be initialized"},
        { extra->prev  == &head, "extra.prev must be head" },
        { extra->next  == next,  "extra.next must be next" },
        { head.value   == 345,   "head.value should be the same" },
        { head.prev    == NULL,  "head.prev should be null" },
        { head.next    == extra, "head.next should be initialized to extra node" },
        { 0, NULL }
    });

    linked_list_remove(next);
    // return memory
    free(next);
        
    // [345]-[666]-[999]
    execute_asserts((assert_t[]){
        { last->value  == 999,   "last.value must be initialized"},
        { last->prev   == extra,  "last.prev must be next" },
        { last->next   == NULL,  "last.next must be null" },
        { extra->value == 666,   "extra.value must be initialized"},
        { extra->prev  == &head, "extra.prev must be head" },
        { extra->next  == last,  "extra.next must be next" },
        { head.value   == 345,   "head.value should be the same" },
        { head.prev    == NULL,  "head.prev should be null" },
        { head.next    == extra, "head.next should be initialized to extra node" },
        { 0, NULL }
    });

    linked_list_free(&head);
    execute_asserts((assert_t[]){
        { head.prev  == NULL, "head.prev should be initialized to NULL" },
        { head.next  == NULL, "head.next should be initialized to NULL" },
        { 0, NULL }
    });

    printf("all tests are passed, implementations seems valid\n");
}
