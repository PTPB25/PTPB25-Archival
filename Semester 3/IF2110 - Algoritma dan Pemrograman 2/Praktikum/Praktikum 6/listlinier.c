#include "listlinier.h"

#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(List l) {
    return (FIRST(l) == NULL);
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

ElType getElmt(List l, int idx) {
/* KAMUS LOKAL */
    int ctr;
    Address p;
/* ALGORITMA */
    ctr = 0;
    p = FIRST(l);
    while (ctr<idx) {
        ctr++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
/* KAMUS LOKAL */
    int ctr;
    Address p;
/* ALGORITMA */
    ctr = 0;
    p = FIRST(*l);
    while (ctr<idx) {
        ctr++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
/* KAMUS LOKAL */
    int idx;
    Address p;
    boolean found;
/* ALGORITMA */
    p = FIRST(l);
    found = false;
    idx = 0;
    while (p!=NULL && !found) {
        if (INFO(p)==val) {
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }
    if (found) {
        return idx;
    } else {
        return IDX_UNDEF;
    }
}

void insertFirst(List *l, ElType val) {
/* KAMUS LOKAL */
    Address p;
/* ALGORITMA */
    p = newNode(val);
    if (p!=NULL) { /* alokasi berhasil */
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val) {
/* KAMUS LOKAL */
    Address p, last;
/* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l,val);
    } else { /* List tidak kosong */
        p = newNode(val);
        if (p!=NULL) { /* alokasi berhasil */
            last = FIRST(*l);
            while (NEXT(last)!=NULL) { /* cari alamat node terakhir */
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
/* KAMUS LOKAL */
    int ctr;
    Address p, loc;
/* ALGORITMA */
    if (idx==0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p!=NULL) { /* alokasi berhasil */
            ctr = 0;
            loc = FIRST(*l);
            while (ctr<idx-1) {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val) {
/* KAMUS LOKAL */
    Address p;
/* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val) {
/* KAMUS LOKAL */
    Address p, loc;
/* ALGORITMA */
    p = FIRST(*l);
    loc = NULL;
    while (NEXT(p)!=NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc==NULL) { FIRST(*l)=NULL; }
    else { NEXT(loc)=NULL; }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
/* KAMUS LOKAL */
    int ctr;
    Address p, loc;
/* ALGORITMA */
    if (idx==0) {
        deleteFirst(l, val);
    } else {
        ctr = 0;
        loc = FIRST(*l);
        while (ctr<idx-1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayList(List l) {
/* KAMUS LOKAL */
    Address p;
/* ALGORITMA */
    p = FIRST(l);
    printf("[");
    while (p!=NULL) {
        printf("%d", INFO(p));
        if (NEXT(p)!=NULL) {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l) {
/* KAMUS LOKAL */
    int ctr;
    Address p;
/* ALGORITMA */
    ctr = 0;
    p = FIRST(l);
    while (p!=NULL) {
        ctr++;
        p = NEXT(p);
    }
    return ctr;
}

List concat(List l1, List l2) {
/* KAMUS LOKAL */
    Address p;
    List l3;
/* ALGORITMA */
    CreateList(&l3);
    p = FIRST(l1);
    while (p!=NULL) {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p!=NULL) {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    return l3;
}