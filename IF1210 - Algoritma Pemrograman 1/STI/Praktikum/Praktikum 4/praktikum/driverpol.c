
#include <stdio.h>
#include "polynomial.h"

int main() {
    Polynomial P1, P2, sum, product, dP1, dP2;
    int x;

    printf("Masukkan polinomial pertama:\n");
    ReadPolynomial(&P1);
    
    printf("Masukkan polinomial kedua:\n");
    ReadPolynomial(&P2);

    printf("\nPolinomial P1(x): ");
    WritePolynomial(P1);

    printf("Polinomial P2(x): ");
    WritePolynomial(P2);

    sum = AddPolynomial(P1, P2);
    printf("\nP1(x) + P2(x): ");
    WritePolynomial(sum);

    product = MultiplyPolynomial(P1, P2);
    printf("P1(x) * P2(x): ");
    WritePolynomial(product);

    printf("\nMasukkan nilai x untuk evaluasi P1(x) dan P2(x): ");
    scanf("%d", &x);
    printf("P1(%d) = %d\n", x, EvaluatePolynomial(P1, x));
    printf("P2(%d) = %d\n", x, EvaluatePolynomial(P2, x));

    dP1 = DerivativePolynomial(P1);
    dP2 = DerivativePolynomial(P2);
    printf("\nTurunan P1'(x): ");
    WritePolynomial(dP1);

    printf("Turunan P2'(x): ");
    WritePolynomial(dP2);

    return 0;
}