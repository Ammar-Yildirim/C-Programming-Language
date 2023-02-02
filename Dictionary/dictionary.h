#ifndef DICTIONARY_H
#define DICTIONARY_H

#define WORD_BUFFER_SIZE 32

typedef struct Pair{
    char str[WORD_BUFFER_SIZE];
    int num;
}Pair;

typedef struct Map{
    Pair *items;
    int size;
}Map;

//Functions
void init(Map *m);
void dest(Map *m);
void set(Map *m, char* word, int id);
Pair* find(Map m, char* str);
int get(Map *m, char* str);

//helper
void print(Map m);



#endif