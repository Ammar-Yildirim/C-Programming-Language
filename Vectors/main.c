#include <stdio.h>
#include "vector.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    Vector v;

    initialize(&v, atoi(argv[1]));
    for(int i = 2; i<argc ; i++){
        printf("%c", argv[i][0] );
    }
    print(v);

    dispose(&v);

    return 0;
}