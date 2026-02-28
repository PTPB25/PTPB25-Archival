#include "prioqueuelist.h"
#include <stdio.h>

Address newNode(ElType x, int pr){
    Address new = malloc(sizeof(Node));
    if(new == NULL) return Nil;
    INFO(new) = x;
    PRIO(new) = pr;
    NEXT(new) = Nil;
    return  new;
}

void delNode(Address *P){
    free(*P);
}

boolean isEmpty(PrioQueue q){
    return q.addrHead == Nil; //Cuma ada head
}

int length(PrioQueue q){
    int count = 0;
    Address traversal = ADDR_HEAD(q);
    while(traversal != Nil){
        count++;
        traversal = NEXT(traversal);
    }
    
    return count;
}

void CreateQueue(PrioQueue *q){
    ADDR_HEAD(*q) = Nil;
}

void enqueue(PrioQueue *q, ElType x, int pr){
    Address new = newNode(x,pr);
    if(new == Nil) return;

    if(isEmpty(*q)){
        ADDR_HEAD(*q) = new;
    }else{
        Address traversal = ADDR_HEAD(*q);
        Address prev = Nil;
        while(PRIO(new) >= PRIO(traversal) && NEXT(traversal) != Nil){
            printf("traversal %d\n", INFO(traversal));
            prev = traversal;
            
            traversal = NEXT(traversal);
        }


        if (PRIO(new) >= PRIO(traversal) && NEXT(traversal) == Nil){ //New node prio terbesar
            NEXT(traversal) = new;
        }
        else if(prev == Nil){ //Q punya satu elemen saja / new Node terkecil
            NEXT(new) = traversal;
            ADDR_HEAD(*q) = new;
        }else{ //New node di tengah
            NEXT(prev) = new;
            NEXT(new) = traversal;
        }
        

    }
}

void dequeue(PrioQueue *q, ElType *x, int *pr){
    Address temp = ADDR_HEAD(*q);
    if(NEXT(temp) == Nil){
        ADDR_HEAD(*q) = Nil;
    }else{
        ADDR_HEAD(*q) = NEXT(temp);
    }

    *x = INFO(temp);
    *pr = PRIO(temp);
    
    delNode(&temp);
}