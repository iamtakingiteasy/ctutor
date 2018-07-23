#include "asserts.h"

#include <stdio.h>
#include <stdlib.h>

void execute_asserts(assert_t *asserts) {
    int err = 0;
    while (asserts && asserts->descr) {
        if (!asserts->expr) {
            printf("FAILED: %s\n", asserts->descr);
            err = 1;
        }
        asserts++;
    }
    if (err) {
        exit(1);
    }
}
