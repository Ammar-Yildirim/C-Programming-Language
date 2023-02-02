#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct Vector{
    int capacity;
    int size;
    int *elements;
}Vector;

void initialize(Vector *v, int capacity);
void dispose(Vector *v);
bool append(Vector *v, int e);
void retrieve(Vector v, int i);

//increasing capacity
bool insert(Vector* v, int i, int e);
bool erase(Vector *v, int i);
bool set_capacity(Vector *v, int capacity);
void safe_append(Vector *v, int e);
void safe_insert(Vector *v, int i, int e);

//Bonus
void print(Vector v);




#endif