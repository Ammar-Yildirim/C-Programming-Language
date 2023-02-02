#ifndef PARITYARRAY_H
#define PARITYARRAY_H

#define ARRAY_SIZE 10

typedef struct ParityArray{
    //int numbers[ARRAY_SIZE];
    int even_idx;
    int odd_idx;
    //Task 2
    int* elements;
    int size;

}ParityArray;

void init(ParityArray* p, int size);
void insert(ParityArray* p, int number);
void print(ParityArray p);
void destroy(ParityArray *p);
void dump(ParityArray p);

#endif