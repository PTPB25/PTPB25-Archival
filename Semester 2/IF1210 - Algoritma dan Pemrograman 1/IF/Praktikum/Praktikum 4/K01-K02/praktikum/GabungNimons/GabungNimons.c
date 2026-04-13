#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int mark(int a, int b){
    return (a == -1) && (b == 99);
}

int main(){
    init();
    FILE * a = fopen("file_a.txt","r");
    FILE * b = fopen("file_b.txt", "r");
    int id1, id2, value1, value2;

    fscanf(a, "%d %d", &id1, &value1);
    fscanf(b, "%d %d", &id2, &value2);
    while(!mark(id1, value1) || !mark(id2, value2)){
    
        if (mark(id1, value1)) {
            while(!mark(id2, value2)){
                printf("%d %d\n", id2, value2);
                fscanf(b, "%d %d", &id2, &value2);
            }

        } 
        else if (mark (id2, value2)) {
            while(!mark(id1, value1)){
                printf("%d %d\n", id1, value1);
                fscanf(a, "%d %d", &id1, &value1);
            }

        } 
        else {
            if (id1 < id2) {
                printf("%d %d\n", id1, value1);
                fscanf(a, "%d %d", &id1, &value1);

            }
            else{
                printf("%d %d\n", id2, value2);
                fscanf(b, "%d %d", &id2, &value2);
            }
        }
    }
    fclose(a);
    fclose(b);
    return 0;
}
