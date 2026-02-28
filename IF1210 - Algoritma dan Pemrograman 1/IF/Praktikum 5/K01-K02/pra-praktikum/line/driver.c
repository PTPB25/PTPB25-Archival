#include "line.h"
#include "point.h"
#include <stdio.h>

/* Driver code for testing */

int main(){
    LINE L1, L2;
    BacaLINE(&L1);
    BacaLINE(&L2);
    printf("%d\n", IsSejajar(L1, L2));
    printf("%d\n", IsTegakLurus(L1, L2));
}
