#include "polynomial.h"

/* For testing */

int main(){
    Polynomial p, q;
    ReadPolynomial(&p);
    ReadPolynomial(&q);
    PrintPolynomial(&p);
    PrintPolynomial(&q);
    printf("%d\n", IsEqual(&p, &q));
    printf("%d %d\n", GetDegree(&p), GetDegree(&q));
}