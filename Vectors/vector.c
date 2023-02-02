#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void initialize(Vector *v, int capacity){
    v->capacity = capacity;
    v->size = 0;
    v->elements = malloc(sizeof(int) * capacity);
}

void dispose(Vector *v){
    free(v->elements);
}

bool append(Vector *v, int e){
    if(v->size >= v->capacity){
        return false;
    }
    else{
        v->elements[v->size++] = e;
        return true;
    }
}

void retrieve(Vector v, int i){
    printf("%d \n", v.elements[i]);
}

void print(Vector v){
    printf("Size: %d \t Capacity: %d \n", v.size , v.capacity);
    for(int i =0; i < v.size; i++){
        printf("%d ", v.elements[i]);
    }
    printf("\n");
}

bool insert(Vector* v, int i, int e){
    if( i > v->size){
        return false;
    }
    else{
        for(int j = v->size; j >= i; j--){
            v->elements[j+1] = v->elements[j];
        }
        v->elements[i] = e;
        v->size++;
        return true;
    }
}

bool erase(Vector *v, int i){
    if( i > v->size){
        return false;
    }
    else{
        for(int j = i; j < v->size; j++){
            v->elements[j] = v->elements[j+1];
        }
        v->size--;
    }
}

bool set_capacity(Vector *v, int capacity){
    if(capacity >= v->size){
        v->capacity = capacity;
        v->elements = realloc( v->elements ,sizeof(int) * capacity);

        return true;
    }
    else{
        return false;
    }
}

void safe_append(Vector *v, int e){
    if(v->size >= v->capacity){
        v->capacity = v->capacity * 2;
        v->elements = realloc(v->elements, sizeof(int) * v->capacity );
        v->elements[v->size++] = e;
    }
    else{
        v->elements[v->size++] = e;
    }
}

void safe_insert(Vector *v, int i, int e){
    if(v->size >= v->capacity){
        v->capacity = v->capacity * 2;
        v->elements = realloc(v->elements, sizeof(int)* v->capacity);
        insert(v, i , e);
    }
    else{
        insert(v, i ,e);
    }
}