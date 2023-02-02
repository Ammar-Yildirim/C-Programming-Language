#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init (Map* m){
    m->items = NULL;
    m->size = 0;
}
void dest(Map *m){
    free(m->items);
    m->size = 0;
}
void set(Map *m, char* word, int id){
    if(m->items == NULL){
        m->items = malloc(sizeof(Pair) * 1);

        strcpy(m->items[m->size].str, word);
        m->items[m->size].num = id;
        m->size++;
    }
    else{
        m->items = realloc(m->items,sizeof(Pair) * (m->size + 1));
        for(int i=0; i<m->size; i++){
            if(strcmp(m->items[i].str, word) == 0){
                m->items[i].num = id;

                return;
            }
        }
        strcpy(m->items[m->size].str, word);
        m->items[m->size].num = id;
        m->size++;
    }
}

Pair* find(Map m, char* str){
    for( int i =0; i< m.size; i++){
        if(strcmp(m.items[i].str,str) == 0){
            return &m.items[i];
        }
    }
    return NULL;
};

int get(Map *m, char* str){
    for(int i = 0; i<m->size; i++){
        if( strcmp( m->items[i].str, str) == 0){
            return m->items[i].num;
        }
    }
    strcpy(m->items[m->size].str, str);
    m->items[m->size].num = 0;
    m->size ++;

    return 0;
}

//helper
void print(Map m){
    printf("Size: %d \n", m.size);
    for(int i = 0; i<m.size ; i++){
        printf("%s -> %d \n", m.items[i].str, m.items[i].num);
    }
}