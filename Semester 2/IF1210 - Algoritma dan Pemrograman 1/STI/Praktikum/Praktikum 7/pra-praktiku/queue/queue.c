#include <stdio.h>
#include "queue.h"

void initQueue(struct Queue *q){
    q->count = 0;
}

bool isEmpty(struct Queue *q){
    if(q->count == 0) return true;
    return false;
}

bool isFull(struct Queue *q){
    if(q->count == MAX_SIZE) return true;
    return false;
}

void enqueue(struct Queue *q, int value){
    if(!isFull(q)){
        q->items[q->count] = value;
        q->count++;
    }else{
        printf("Queue penuh!\n");
    }
}

int dequeue(struct Queue *q){
    int value;
    if(isEmpty(q)){
        printf("Queue kosong!\n");
        value = SENTINEL;
        return value;
        
    }else{
        value = q->items[0];
        for(int i = 0; i<q->count-1; i++){
            q->items[i] = q->items[i+1];
        }
        q->count--;
        return value;
    }

}

int front(struct Queue *q){
    int value;
    if(!isEmpty(q)){
        value = q->items[0];
    }else{
        printf("Queue kosong!\n");
        value = SENTINEL;
    }
    return value;
}

int size(struct Queue *q){
    return q->count;
}