
#include "polynomial.h"

/* ==================== Polynomial Operations ==================== */

/* Konstruktor */
void CreatePolynomial(Polynomial *p){
    int i;
    p->degree = 0;
    for(i=0; i <= MAX_DEGREE; i++) p->coeff[i] = 0;
}
/**
 * I.S. -
 * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi dengan 0.0
 * dan degree juga diinisialisasi dengan 0
 */

void CreatePolynomialFromArray(Polynomial *p, int coeffArray[], int size){
    int i;
    CreatePolynomial(p);
    for(i=0; i<size; i++){
        p->coeff[i] = coeffArray[i];
        if(coeffArray[i])p->degree = i;
    }
}
/**
 * I.S. CoeffArray adalah array of coefficients yang terdefinisi, 
 * size adalah ukuran dari coeffArray yang terdefinisi
 * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi berdasarkan coeffArray
 * dan degree diinisialisasikan dengan index tertinggi dari elemen coeffArray yang tidak nol
 */

/* Selektor */
int GetCoefficient(Polynomial *p, int exponent){
    return p->coeff[exponent];
}
/**
 * Mengembalikan nilai koefisien pada suku dengan eksponen = exponent
 */

int GetDegree(Polynomial *p){
    return p->degree;
}
/**
 * Mengembalikan derajat tertinggi dari polynomial dengan koefisien tak nol
 */

int Evaluate(Polynomial *p, int x){
    int sum = 0, i;
    for(i = GetDegree(p); i >= 0; i--){
        sum *= x;
        sum += GetCoefficient(p, i);
    }
    return sum;
}
/**
 * Mengembalikan hasil evaluasi polynomial p dengan masukan x
 * Contoh: 
 * p = 3x^2 + 3x + 1
 * Evaluate(p, 1) = 3(1^2) + 3(1) + 1 = 7
 */

/* Mutator */
void SetCoefficient(Polynomial *p, int exponent, int coefficient){
    int i;
    p->coeff[exponent] = coefficient;

    p->degree = 0;
    for(i=0; i<=MAX_DEGREE; i++){
        if(p->coeff[i])p->degree = i;
    }
}
/**
 * I.S. Polynomial p, exponent, dan coefficient terdefinisi
 * F.S. Polynomial p diupdate dengan koefisien baru (coefficient)
 * pada suku dengan eksponen yang diberikan (exponent)
 */

/* Operasi Baca/Tulis */
void ReadPolynomial(Polynomial *p){
    int n, coeff, i;
    CreatePolynomial(p);
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &coeff);
        SetCoefficient(p, i, coeff);
        if(coeff)p->degree = i;
    }
}
/**
 * I.S. Polynomial p belum terdefinisi
 * F.S. Polynomial p terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input
 * - Meminta input size yang merupakan banyak koefisien yang akan dimasukkan (dari koefisien 0)
 * - Meminta input koefisien sebanyak size dan menginisialisasi p berdasarkan nilai ini (dari koefisien 0)
 */

/* Operator Aritmatika */
void AddPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result){
    int i;
    result->degree = 0;
    for(i=0; i <= MAX_DEGREE; i++){
        SetCoefficient(result, i, GetCoefficient(p1, i) + GetCoefficient(p2, i));
        if(result->coeff[i] != 0) result->degree = i;
    }
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Hasil penjumlahan p1 dan p2 (p1 + p2) disimpan di polynomial result
 */

void SubtractPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result){
    int i;
    result->degree = 0;
    for(i=0; i <= MAX_DEGREE; i++){
        SetCoefficient(result, i, GetCoefficient(p1, i) - GetCoefficient(p2, i));
        if(result->coeff[i] != 0) result->degree = i;
    }
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Hasil pengurangan p1 dan p2 (p1 - p2) disimpan di polynomial result
 */

int IsEqual(Polynomial *p1, Polynomial *p2){

    int i;
    for(i=0; i <= MAX_DEGREE; i++){
        if(GetCoefficient(p1, i) != GetCoefficient(p2, i)){
            return 0;
        }
    }
    return 1;
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Mengembalikan 1 jika kedua polynomial adalah sama, dan 0 jika sebaliknya
 * Dua polynomial dianggap sama jika keduanya memiliki derajat yang sama dan semua koefisiennya bernilai sama
 */

/* Operasi Lain */
void PrintPolynomial(Polynomial *p){
    int i, coeff, first = -1, last = -1;

    /* cari first dan last suku polinom yang akan di print, lebih aman gini kayaknya */
    for(i = MAX_DEGREE; i >= 0; i--){
        coeff = GetCoefficient(p, i);
        if(coeff){
            if(first == -1)first = i;
            last = i;
        }
    }

    if(first == -1 && last == -1){
        printf("0\n");
        return;
    }

    /* <nguli> */
    for(i = first; i >= last; i--){
        coeff = GetCoefficient(p, i);
        if(!coeff)continue;
        
        if(i == first){
            if(i == 0){
                printf("%d", coeff);
            }
            else if(i == 1){
                if(coeff == 1)printf("x");
                else if(coeff == -1)printf("-x");
                else printf("%dx", coeff);
            }
            else{
                if(coeff == 1)printf("x^%d", i);
                else if(coeff == -1)printf("-x^%d", i);
                else printf("%dx^%d", coeff, i);
            }
        }
        else{
            if(i == 0){
                if(coeff > 0){printf(" + %d", coeff);}
                else if(coeff < 0)printf(" - %d", -coeff);
            }
            else if(i == 1){
                if(coeff > 0){
                    if(coeff != 1)printf(" + %dx", coeff);
                    else printf(" + x");
                }
                else if(coeff < 0){
                    if(coeff != -1)printf(" - %dx", -coeff);
                    else printf(" - x");
                }
            }
            else{
                if(coeff > 0){
                    if(coeff != 1) printf(" + %dx^%d", coeff, i);
                    else printf(" + x^%d", i);
                }
                else if(coeff < 0){
                    if(coeff != -1) printf(" - %dx^%d", -coeff, i);
                    else printf(" - x^%d", i);
                }
            }
        }
    }
    /*  </nguli>  */

    printf("\n");
}
/**
 * I.S. P terdefinisi
 * F.S. Polynomial p ditampilkan dengan aturan sebagai berikut:
 * - Elemen ditampilkan dari derajat paling tinggi ke derajat paling rendah
 * - Hanya tampilkan elemen dengan koefisien tak nol
 * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien positif, tidak perlu berikan tanda + di depan
 * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien negatif, tidak perlu berikan spasi antara tanda - dan suku (-x^n)
 * - Untuk suku yang bukan derajat tertinggi, tampilkan tanda + dan - dengan diberikan spasi (x^3 + 6x)
 * - Untuk koefisien 1, hanya tampilkan x^n (bukan 1x^n), kecuali untuk suku konstan
 * - Untuk koefisien -1, hanya tampilkan -x^n atau - x^n (bukan -1x^n dan - 1x^n), kecuali untuk suku konstan
 * - Untuk suku derajat 1, tampilkan x (bukan x^1)
 * - Untuk suku derajat 0, tampilkan koefisiennya saja
 * - Berikan newline (\n) di akhir baris
 * Contoh: -4x^3 + 3x^2 - 2x + 1
 */
