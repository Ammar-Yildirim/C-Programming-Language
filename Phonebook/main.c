#include <stdio.h>
#include "pb.h"

int main(){
    Phonebook pb;

    //Demonstrates how init works:
    init(5, &pb);

    //Demonstrates how insert works, taking into account all points
    insert("Person", "06872272", &pb);
    insert("Person", "09988837", &pb);
    insert("Ahmad", "120391039", &pb);
    insert("johnny", "123123123", &pb);
    insert("no", "9797997", &pb);
    insert("ronny", "0101029", &pb);
    insert("hi", "00000", &pb);

    //Demonstrates how the get function works
    printf("get: %s \n", get("Person", pb));

    /* Made a small tweak to print, besides printing all values it also prints
    the size and the number of inserted values */
    print(pb);

    //Demonstrates how the dump function works
    dump(pb,"mytext");

    //Demonstrates how the destroy function works, ensuring NO memory leaks occur
    destroy(&pb);
}