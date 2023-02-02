#include "parityarray.h"
#include <stdio.h>

int main(){
    ParityArray p;
    int num,tmp;
    
    printf("Enter the size of the Parity array: ");
    scanf("%d", &num);

    init(&p,num);

    for(int i = 0; i<num;i++){
        scanf("%d", &tmp);
        insert(&p, tmp);
    }
    
    /*
    init(&p, 10);
    insert(&p, 101);
    insert(&p, 7);
    insert(&p, 1);
    insert(&p, 99);
    insert(&p, 4);
    */
    //Sample input

    print(p);
    dump(p);

    destroy(&p);

    return 0;
}