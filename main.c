#include "contref.h"


/// Exemplo que ta no Trabalho

int main(int argc, char const *argv[]) {
    int *v = (int*)malloc2(sizeof(int));
    *v = 10;
    int *w = (int*)malloc2(sizeof(int));
    dump();
    *w = 20;
    atrib2((void**)&v, w);
    dump();
    char *c = (char*)malloc2(sizeof(char));
    *c = 'z';
    dump();
    atrib2((void**)&w, NULL);
    dump();
    return 0;
}



