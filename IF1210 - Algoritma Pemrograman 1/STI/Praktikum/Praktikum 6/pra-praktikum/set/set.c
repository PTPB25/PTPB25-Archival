#include <stdio.h>
#include "set.h"

void CreateEmpty(Set *S){
    S->Count = 0;
}

boolean IsEmpty(Set S){
    boolean empty = false;
    if(S.Count == 0){
        empty =true;
    }
    return empty;
}

boolean IsFull(Set S){
    boolean full = false;
    if(S.Count == MaxEl){
        full =true;
    }
    return full;
}

boolean IsMember(Set S, int Elmt){
    for(int i = 0; i<S.Count; i++){
        if(S.Elements[i] == Elmt){
            return true;
        }
    }
    return false;
}

void Insert(Set *S, int Elmt){
    if(!IsMember(*S, Elmt)){
        int i = S->Count-1;
        while(i>=0 && S->Elements[i] > Elmt){
            S->Elements[i+1] = S->Elements[i];
            i--;
        }

        S->Elements[i+1] = Elmt;
        S->Count++;
    }
}

void Delete(Set *S, int Elmt){
    int index = -1;
    for(int i = 0;i < S->Count; i++){
        if(S->Elements[i] = Elmt){
            index = i;
            break;
        }
    }

    if(index != -1){
        for(int i = index; i<S->Count-1; i++){
            S->Elements[i] = S->Elements[i+1];
        }
        S->Count--;
    }
}