#ifndef ASSERTS_H
#define ASSERTS_H

#include <stdlib.h>

typedef struct {
    int expr;
    char *descr;
} assert_t;

void execute_asserts(assert_t *asserts);
#endif
