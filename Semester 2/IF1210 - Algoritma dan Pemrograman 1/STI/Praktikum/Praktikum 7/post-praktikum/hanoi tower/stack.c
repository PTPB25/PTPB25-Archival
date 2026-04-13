#include "stack.h"
#include <stdio.h>
//ts
// void printStack(Stack s)
// {
//     if (isEmpty(s))
//     {
//         printf("EMPTY\n");
//     }
//     else
//     {
//         for (int i = 0; i <= s.idxTop; i++)
//         {
//             printf("%d ", s.buffer[i]);
//         }
//         printf("\n");
//     }
// }

void CreateStack(Stack *s){
    s -> idxTop = IDX_UNDEF;
}

boolean isEmpty(Stack s){
    return s.idxTop == IDX_UNDEF;
}

boolean isFull(Stack s){
    return s.idxTop == CAPACITY -1;
}

int length(Stack s){
    return s.idxTop + 1;
    
}

void push(Stack *s, ElType val){
    s->idxTop++;
    TOP(*s) = val;
}

void pop(Stack *s, ElType *val){
    *val = TOP(*s);
    s->idxTop--;
}

void SortirStack(Stack *S1, Stack *S2){
    int sorted = 0;
    while(IDX_TOP(*S1) != IDX_UNDEF){
        Stack buffer;
        CreateStack(&buffer);
        ElType min = S1->buffer[IDX_TOP(*S1)];
        for(int i = 0; i<=IDX_TOP(*S1); i++){
            if(S1->buffer[i] < min){
                min=S1->buffer[i];
            }
        }
        // printf("Lewat cek min %d\n", min);

        while(S1->buffer[IDX_TOP(*S1)] > min){
            ElType temp;
            pop(S1, &temp);
            push(S2,temp);
        }
        // printStack(*S1);
        // printStack(*S2);
        
        // printf("Lewat keuar sampai min\n");
        while(S2->idxTop >= sorted){
            ElType temp;
            pop(S2, &temp);
            push(&buffer,temp);
        }
        ElType done;
        pop(S1,&done);
        push(S2,done);
        while(buffer.idxTop != IDX_UNDEF){
            ElType temp;
            pop(&buffer, &temp);
            push(S1,temp);
        }
        sorted++;
    }
}
