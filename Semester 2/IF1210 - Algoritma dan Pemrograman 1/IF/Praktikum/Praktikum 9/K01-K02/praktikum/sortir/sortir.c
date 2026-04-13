#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"
#include "../queue.h"


/* Sorting array but no list data structure can be used, only stack and queue */

int main(){
    int n;
    scanf("%d", &n);

    Stack copy, temp;
    CreateEmpty(&copy);
    CreateEmpty(&temp);

    Queue q;
    CreateQueue(&q);

    for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        Push(&temp, val);
    }

    /* Strategy: bruteforce to find the max of current stack, remove it from stack, and add the max to a queue, that queue will be the final result */
    while(length(q) < n){

        int max = (1 << 31);
        while(!IsEmpty(temp)){
            int val;
            Pop(&temp, &val);
            Push(&copy, val);
            if(max < val){
                max = val;
            }
        }

        int found = 0;
        while(!IsEmpty(copy)){
            int val;
            Pop(&copy, &val);
            if(val == max && !found){
                found = 1;
            }
            else{
                Push(&temp, val);
            }
        }

        enqueue(&q, max);
    }

    displayQueue(q);

    return 0;
}