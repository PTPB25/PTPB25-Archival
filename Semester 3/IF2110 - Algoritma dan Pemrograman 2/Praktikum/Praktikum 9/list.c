#include "list.h"

/* *** Manajemen Memori *** */
Address newNode(ElType x) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NIL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

/* *** Pemeriksaan Kondisi List *** */
boolean isEmpty(List l) { return (l == NIL); }

boolean isOneElmt(List l) { return (!isEmpty(l) && NEXT(l) == NIL); }

/* *** Primitif Pemrosesan List *** */
ElType head(List l) { return INFO(l); }

List tail(List l) { return NEXT(l); }

List konso(ElType e, List l) {
    Address p = newNode(e);
    if (p == NIL)
        return l;
    NEXT(p) = l;
    return p;
}

List konsDot(List l, ElType e) {
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsDot(tail(l), e);
        return l;
    }
}

/* *** Operasi dan Fungsi Lain *** */
void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d ", head(l));
        displayList(tail(l));
    }
}

int length(List l) {
    if (isEmpty(l))
        return 0;
    else
        return 1 + length(tail(l));
}

boolean search(List l, ElType x) {
    if (isEmpty(l))
        return false;
    else if (head(l) == x)
        return true;
    else
        return search(tail(l), x);
}

void deleteX(List *l, ElType x) {
    Address p;
    if (!isEmpty(*l)) {
        deleteX(&NEXT(*l), x);
        if (INFO(*l) == x) {
            p = *l;
            *l = NEXT(*l);
            free(p);
        }
    }
}

List copy(List l) {
    if (isEmpty(l))
        return NIL;
    else
        return konso(head(l), copy(tail(l)));
}

void mCopy(List lin, List *lout) {
    List lTemp;
    if (isEmpty(lin))
        *lout = NIL;
    else {
        mCopy(tail(lin), &lTemp);
        *lout = konso(head(lin), lTemp);
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1))
        return copy(l2);
    else
        return konso(head(l1), concat(tail(l1), l2));
}

void mConcat(List l1, List l2, List *result) {
    List lTemp;
    if (isEmpty(l1))
        *result = copy(l2);
    else {
        mConcat(tail(l1), l2, &lTemp);
        *result = konso(head(l1), lTemp);
    }
}
