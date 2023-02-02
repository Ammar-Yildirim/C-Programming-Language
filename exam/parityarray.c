#include "parityarray.h"
#include <stdlib.h>
#include <stdio.h>

void init(ParityArray* p, int size){
    p->elements = malloc(sizeof(int) * size);
    p->size = size;
    p->even_idx = 0;
    //p->odd_idx = ARRAY_SIZE-1;
    p->odd_idx = size-1;
}

void insert(ParityArray* p, int number){
    if( number % 2 == 0){
        //p->numbers[p->even_idx++] = number;
        p->elements[p->even_idx++] = number;
    }
    else{
        //p->numbers[p->odd_idx--] = number;
        p->elements[p->odd_idx--] = number;
    }
}

void print(ParityArray p){
    /*
    for(int i = 0; i<p.even_idx;i++){
        printf("%d ", p.numbers[i]);
    }
    for(int i = p.odd_idx+1; i<ARRAY_SIZE;i++){
        printf("%d ", p.numbers[i]);
    }
    */
    for(int i = 0; i<p.even_idx;i++){
        printf("%d ", p.elements[i]);
    }
    for(int i = p.odd_idx+1; i<p.size;i++){
        printf("%d ", p.elements[i]);
    }
}

void dump(ParityArray p){
    FILE *pt = fopen("dump.txt", "w");

    for(int i = 0; i<p.even_idx;i++){
        fprintf(pt,"%d ", p.elements[i]);
    }
    for(int i = p.odd_idx+1; i<p.size;i++){
        fprintf(pt,"%d ", p.elements[i]);
    }

    fclose(pt);
}

void destroy(ParityArray *p){
    free(p->elements);
}