#include "prioqueuelist.h"
#include <stdio.h>

void print(PrioQueue q){
    Address traversal = q.addrHead;
    if(traversal == Nil){
        printf("Kosong\n");
        return;
    }

    while(traversal != Nil){
        printf("[%d p%d] ", INFO(traversal), PRIO(traversal));
        traversal = NEXT(traversal);
    }
    printf("\n");
}

int main(){
    PrioQueue que;
    CreateQueue(&que);
    print(que);

    ElType x = 1;
    int prio = 3;
    enqueue(&que, x, prio);
    print(que);

    x = 2;
    prio = 1;
    enqueue(&que, x, prio);
    print(que);

    x = 3;
    prio = 2;
    enqueue(&que, x, prio);
    print(que);

    x = 4;
    prio = 4;
    enqueue(&que, x, prio);
    print(que);

    x = 5;
    prio = 2;
    enqueue(&que, x, prio);
    print(que);

    while(!isEmpty(que)){
        dequeue(&que, &x, &prio);
    printf("%d p%d dihapus\n", x, prio);
    print(que);
    }
    
}