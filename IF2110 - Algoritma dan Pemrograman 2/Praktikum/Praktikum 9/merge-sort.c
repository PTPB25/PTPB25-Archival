#include "list.h"
#include <stdio.h>

void split(List l, List *l1, List *l2){
    if(length(l) <= length(*l1) + 1) *l2 = copy(l);
    else{
        *l1 =  konsDot(*l1, head(l));
        split(tail(l), l1, l2);
    }
}

List mergeSorted(List l1, List l2){
    if(isEmpty(l1) && isEmpty(l2)) return l1;
    else if(isEmpty(l1)) return l2;
    else if(isEmpty(l2)) return l1;
    else{
        if(head(l1) <= head(l2)) return konso(head(l1), mergeSorted(tail(l1), l2));
        else return konso(head(l2), mergeSorted(l1, tail(l2)));
    }
}

List mergeSort(List l){
    List l1 = NIL;
    List l2 = NIL;
    if(length(l) > 1){
        split(l, &l1, &l2);
        l1 = mergeSort(l1);
        l2 = mergeSort(l2);
        List temp = mergeSorted(l1, l2);
        displayList(temp); printf("\n");
        return temp;
    }
    else return l;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    List l = NIL;
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 0;
        }
        l = konsDot(l, value);
    }

    List result = mergeSort(l);

    return 0;
}