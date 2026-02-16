
#include <stdio.h>
#include <stdlib.h>
#include "prioritas.h"


void prioritizeValue(Queue *q, int x){
    Queue result;
    Queue temp;
    CreateQueue(&temp);
    CreateQueue(&result);

    int jumlahPrioritas = 0;
    while(!isEmpty(*q)){
        int val;
        dequeue(q, &val);
        if(val == x){
            jumlahPrioritas++;
        }
        else{
            enqueue(&temp, val);
        }
    }

    for(int i = 0; i < jumlahPrioritas; i++){
        enqueue(&result, x);
    }

    while(!isEmpty(temp)){
        int val;
        dequeue(&temp, &val);
        enqueue(&result, val);
    }

    while(!isEmpty(result)){
        int val;
        dequeue(&result, &val);
        enqueue(q, val);
    }
}