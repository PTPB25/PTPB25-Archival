#include <stdio.h>
#include "time.h"

/* Driver code for testing */

int main(){
    TIME T;
    BacaTIME(&T);
    TulisTIME(T);
    printf("\n");
    printf("%ld\n", Durasi(T, PrevNDetik(T, 100)));
}
