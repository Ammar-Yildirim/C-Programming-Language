#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pb.h"

void init(int size, Phonebook* pb){
    pb->inserted = 0;
    pb->size = size;
    pb->entries = malloc(sizeof(Entry)*size);
}

void destroy(Phonebook* pb){
    pb->inserted = 0;
    pb->size = 0;
    free(pb->entries);
}

bool insert(char* name, char* number, Phonebook* pb){
    for(int i = 0; i<pb->inserted; i++){
        if(strcmp(name, pb->entries[i].name) == 0){
            strcpy(pb->entries[i].number, number);
            return true;
        }
    }
    if(pb->inserted >= pb->size){
        return false;
    }
    else{
        strcpy(pb->entries[pb->inserted].name, name);
        strcpy(pb->entries[pb->inserted].number, number);
        pb->inserted++;
        return true;
    }
}

void print(Phonebook pb){
    for(int i=0; i<pb.inserted; i++){
        printf("%s - %s \n", pb.entries[i].name, pb.entries[i].number);
    }
    printf("Size:%d  Inserted:%d \n", pb.size, pb.inserted);
}

char* get(char* name, Phonebook pb){
    for(int i=0; i<pb.inserted; i++){
        if(strcmp(name, pb.entries[i].name) == 0){
            return pb.entries[i].number;
        }
    }
    return NULL;
}

void dump(Phonebook pb, char* filename){
    FILE* pt = fopen(filename, "w");
    for(int i=0; i<pb.inserted; i++){
        fprintf(pt, "%s\t%s \n", pb.entries[i].name , pb.entries[i].number);
    }
    fclose(pt);
}