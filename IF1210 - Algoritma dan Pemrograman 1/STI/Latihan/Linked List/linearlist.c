#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define NIL NULL
#define IDX_UNDEF -1



typedef int Eltype;
typedef struct node* Address;
typedef struct node{
    Eltype info;
    Address next;
} Node;
typedef Address list;


void CreateList(list l){
    l = NIL;
}

Address newNode(Eltype var){
    Address p = malloc(sizeof(Node));
    p->info = var;
    p->next = NIL;
    return p;
}

boolean isEmpty(list l){
    return l == NIL;
}

int indexOf(list l, Eltype x){
    int idx = 0;
    Address p = l;
    boolean found = false;

    while(p!=NIL && !found){
        if(p->info == x){
            found = true;
        }else{
            idx++;
            p = p->next;
        }
    }

    if(found){
        return idx;
    } else return IDX_UNDEF;
}

int length(list l){
    Address p = l;
    int ctr = 0;
    while(p!=NIL){
        ctr++;
        p = p->next;
    }

    return ctr;
}

Eltype getElmt(list l, int idx){
    Address p = l;
    int ctr = 0;
    while(ctr<idx){
        ctr++;
        p = p->next;
    }
    return p->info;
}

void setElmt(list *l, int idx, Eltype var){
    Address p = l;
    int ctr = 0;
    while(ctr<idx){
        ctr++;
        p = p->next;
    }

    p->info = var;
    
}

void insertFirst(list *l, Eltype var){
    Address p;
    p = newNode(var);
    if(p!=NIL){
        p->next = l;
        l = p;
    }
}

void insertAt(list *l, Eltype var, int idx){
    Address p;
    if(l == NIL){
        insertFirst(l,var);
    }else{
        p = newNode(var);
        if(p!=NIL){
            int ctr = 0;
            Address loc = l;

            while(ctr<idx-1){
                ctr++;
                loc = loc->next;
            }

            p->next = loc->next;
            loc->next = p;
        }
    }
}

void inserLast(list *l, Eltype var){
    Address p;
    if(l == NIL){
        insertFirst(l, var);
    }else{
        p = newNode(var);
        if(p!=NIL){
            Address last = l;
            while(last->next != NIL){
                last = last->next;
            }
            last->next = p;

        }
    }
    
}

void deleteFirst(list *l, Eltype *var){
    Address p;
    p = l;
    var = p->info;
    l = p->next;
    free(p);
}

void deleteAt(list *l, Eltype *var, int idx){
    Address p;
    if(idx == 0){
        deleteFirst(l,var);
        return;
    }else{
        int ctr = 0;
        Address loc = l;
        while (ctr < idx-1){
            ctr++;
            loc = loc->next;
        }
        //ctr = idx-1
        //loc = id
        p = loc->next;
        var = loc->info;
        loc->next = p->next;
        free(p);
    }

    
}

void deleteLast(list *l, Eltype *var){
    Address p, loc;
    p = l;
    loc = NIL;

    while(p->next != NIL){
        loc = p;
        p = p->next;

    }

    if(loc!=NIL){
        l = NIL;
    }else{
        loc->next = NIL;
        var = p->info;
        free(p);
    }
}

list concat (list l1, list l2){
    Address p;
    list l3;
    CreateList(l3);
    p = l1;
    while(p!=NIL){
        inserLast(&l3, p->info);
        p = p->next;
    }

    p = l2;
    while(p!=NIL){
        inserLast(&l3, p->info);
        p = p->next;
    }

    return l3;
}

// void deleteNegative(list *l){
//     Address p = l;
//     Address prev = NIL;

//     while(p != NIL)
// }
int main(){
    list l;
    Address p1;
    Address p2;
}