
#include <stdio.h>
#include "point.h"


/* Driver code for testing */

int main(){
    POINT p, q;
    BacaPOINT(&p);
    BacaPOINT(&q);
    printf("%d\n", IsOnSbY(p));
}
