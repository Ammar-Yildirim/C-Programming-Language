#ifndef PB_H
#define PB_H

#include <stdbool.h>

struct Entry{
    char name[30+1];
    char number[30+1];
};
typedef struct Entry Entry;

struct Phonebook{
    Entry* entries;
    int size;
    int inserted;
};
typedef struct Phonebook Phonebook;

void init(int size, Phonebook* pb);
void destroy(Phonebook* pb);
bool insert(char* name, char* number, Phonebook* pb);
char* get(char* name, Phonebook pb);
void print(Phonebook pb);
void dump(Phonebook pb, char* filename);



#endif
