#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *ptr;
    int num_d_ref;
} REF;

#define MAX_D_REFS 100

REF ref_array[MAX_D_REFS];

void* malloc2(size_t size) {
    for (int i = 0; i < MAX_D_REFS; i++) {
        if (ref_array[i].ptr == NULL) {
            ref_array[i].ptr = malloc(size);
            if (ref_array[i].ptr == NULL) {
                return NULL;
            }
            ref_array[i].num_d_ref = 1;
            return ref_array[i].ptr;
        }
    }
    return NULL;
}

void atrib2(void **dest, void *src) {
    if (*dest != NULL) {
        for (int i = 0; i < MAX_D_REFS; i++) {
            if (ref_array[i].ptr == *dest) {
                ref_array[i].num_d_ref--;
                if (ref_array[i].num_d_ref == 0) {
                    free(ref_array[i].ptr);
                    ref_array[i].ptr = NULL;
                }
                break;
            }
        }
    }
    if (src != NULL) {
        for (int i = 0; i < MAX_D_REFS; i++) {
            if (ref_array[i].ptr == src) {
                ref_array[i].num_d_ref++;
                break;
            }
        }
    }
    *dest = src;
}

void dump() {
    for (int i = 0; i < MAX_D_REFS; i++) {
        if (ref_array[i].ptr != NULL) {
            printf("Endereco: %p, Referencias: %d\n", ref_array[i].ptr, ref_array[i].num_d_ref);
        }
    }
    printf("\n\n");
}

