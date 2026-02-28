#include "stack.h"

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

/*********** Operasi Tambahan **********/
void copyStack(Stack *sres, Stack s){
    CreateStack(sres);
    Stack temp;
    CreateStack(&temp);

    while(!isEmpty(s)){
        ElType val;
        pop(&s, &val);
        push(&temp, val);
    }

    while(!isEmpty(temp)){
        ElType val;
        pop(&temp, &val);
        push(sres, val);
    }
}
/* Menyalin isi Stack s ke dalam Stack sres
I.S. sres mungkin kosong
F.S. sres berisi salinan dari s
Contoh:
Jika s = [1,2,3] maka setelah dipanggil sres = [1,2,3]
Jika s = [] maka setelah dipanggil sres = []
Jika s = [1] maka setelah dipanggil sres = [1]

Hint: 
- gunakan Stack sementara dan command push & pop
- Jangan lupa konstruk ulang sres

Notes: [ 1, 2, 3 ]
               ⬆️
              Top
*/

void reverseStack(Stack *s){
    Stack reverse;
    CreateStack(&reverse);

    while(s->idxTop != IDX_UNDEF){
        ElType temp;
        pop(s,&temp);
        push(&reverse,temp);
    }
    *s = reverse;
}
/* Membalikkan isi Stack s
I.S. S mungkin kosong
F.S. Isi Stack s dibalik
Contoh:
jika s = [1,2,3] maka setelah dipanggil s = [3,2,1]
Jika s = [1,2,3,4] maka setelah dipanggil s = [4,3,2,1]
Jika s = [] maka setelah dipanggil s = []
Jika s = [1] maka setelah dipanggil s = [1]

Hint: 
- gunakan Stack sementara, lalu copy isi Stack sementara ke dalam Stack s

Notes: [ 1, 2, 3 ]
               ⬆️
              Top
*/

void mergeStack(Stack *sres, Stack *s1, Stack *s2){
    Stack temp;
    CreateStack(&temp);

    while(!isEmpty(*s2)){
        ElType var;
        pop(s2, &var);
        push(&temp, var);
    }

    copyStack(sres, *s1);
    
    while(!isEmpty(temp)){
        ElType var;
        pop(&temp,&var);
        push(sres,var);
    }

}
/* Menggabungkan Stack s1 dan s2 ke dalam Stack sres
I.S. sres, s1, dan s2 mungkin kosong
F.S. sres berisi gabungan dari s1 dan s2 (dengan s1 di bawah s2)
Contoh:
Jika s1 = [1,2,3] dan s2 = [4,5,6] maka setelah dipanggil sres = [1,2,3,4,5,6]
Jika s1 = [] dan s2 = [] maka setelah dipanggil sres = []
Jika s1 = [1,2,3] dan s2 = [] maka setelah dipanggil sres = [1,2,3]
Jika s1 = [] dan s2 = [4,5,6] maka setelah dipanggil sres = [4,5,6]

Hint:
- gunakan konsep yang sama seperti copyStack

Notes: [ 1 , 2, 3 ]
         ⬆️     ⬆️
       bottom  Top
*/

void printStack(Stack s){
    if (isEmpty(s)) {
        printf("Stack: EMPTY\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s.idxTop; i++) {
            printf("%d", s.buffer[i]);
            if (i < s.idxTop) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
/* Menampilkan isi Stack s ke layar
I.S. S mungkin kosong
F.S. Isi Stack s ditampilkan ke layar
Contoh Output:
Jika s = [1,2,3] maka outputnya adalah "Stack: 3 2 1"
Jika s = [] maka outputnya adalah "Stack: EMPTY"

Notes : [ 1, 2, 3 ]
                ⬆️
               Top

Untuk mempermudah, silakan gunakan kode berikut
void printStack(Stack s) {
    if (isEmpty(s)) {
        printf("Stack: EMPTY\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s.idxTop; i++) {
            printf("%d", s.buffer[i]);
            if (i < s.idxTop) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
*/
