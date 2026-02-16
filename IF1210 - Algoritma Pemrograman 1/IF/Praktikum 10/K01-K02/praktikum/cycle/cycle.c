#include "../listlinier.h"
#include "../Boolean.h"
#include "cycle.h"
#include <stdlib.h>

Address findCycleEntryPoint(List l){
    Address slow, fast;
    slow = fast = FIRST(l);

    /* Use Floyd cycle detection algorithm on functional graph */
    while(1){
        if(slow == NULL || fast == NULL || NEXT(fast) == NULL){
            return NULL;
        }

        slow = NEXT(slow);
        fast = NEXT(NEXT(fast));
        if(slow == fast){
            break;
        }
    }

    slow = FIRST(l);
    while(slow != fast){
        slow = NEXT(slow);
        fast = NEXT(fast);
    }

    return slow;
}
