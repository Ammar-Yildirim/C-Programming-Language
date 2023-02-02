#include "dictionary.h"
#include <stdio.h>

int main(){
    
    Map m;
    
    init(&m);
    /*
    set(&m,"Ammar",6);
    set(&m,"Ammar",2);
    set(&m,"Semra",3);
    set(&m,"esat",33);

    print(m);

    //printf("%s \n", (*(find(m, "Ammar"))).str );

    printf("%d \n", get(&m,"Ammar"));
    */
    

    

    FILE *pt = fopen("cry.txt", "r");
    char str[WORD_BUFFER_SIZE];
    while(fscanf(pt, "%s", str) == 1){
        if(find(m,str) == NULL){
            set(&m, str, 1);
        }
        else{
            set(&m, str, get(&m,str)+1);
        }
    }

    print(m);

    fclose(pt);
    dest(&m);


    return 0;
}