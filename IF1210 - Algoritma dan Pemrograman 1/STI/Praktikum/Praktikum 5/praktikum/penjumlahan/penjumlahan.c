#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "ListStatik.h"

#define MAX_DIGITS 1000

typedef struct {
    int *data;
    int ukuran;
    int kapasitas;
} ListStatik;

void inisialisasiList(ListStatik *list, int capacity){
    list->ukuran = 0;
    list->kapasitas = capacity;
    list->data = (int *)malloc(capacity * sizeof(int));
}

int tambahElemen(ListStatik *list, int nilai){
    if (list->ukuran >= list->kapasitas) {
        return 0;
    }
    list->data[list->ukuran] = nilai;
    list->ukuran++;
    return 1;
}

void tampilkanList(ListStatik list){
    if (list.ukuran == 0){
        printf("List kosong");
    } else {
        for (int i = list.ukuran - 1; i >= 0; i--){
            printf("%d", list.data[i]);
        }
    }
    printf("\n");
}

void tambahBesar(ListStatik *result, ListStatik *num1, ListStatik *num2) {
    int i = 0, carry = 0;

    while (i < num1->ukuran || i < num2->ukuran || carry) {
        int digit1 = (i < num1->ukuran) ? num1->data[i] : 0;
        int digit2 = (i < num2->ukuran) ? num2->data[i] : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        
        tambahElemen(result, sum % 10);
        i++;
    }
}

void prosesMasukan(char *input1, char *input2, ListStatik *num1, ListStatik *num2) {
    inisialisasiList(num1, MAX_DIGITS);
    inisialisasiList(num2, MAX_DIGITS);
    
    int len1 = strlen(input1);
    for (int i = len1 - 1; i >= 0; i--) {
        if (input1[i] != '-') {
            tambahElemen(num1, input1[i] - '0');
        }
    }

    int len2 = strlen(input2);
    for (int i = len2 - 1; i >= 0; i--) {
        if (input2[i] != '-') {
            tambahElemen(num2, input2[i] - '0');
        }
    }
}

int main() {
    int m, n;
    char num1[1001], num2[1001];
    scanf("%d %d", &m, &n);
    scanf("%s", num1);
    scanf("%s", num2);

    ListStatik num1List, num2List, resultList;
    inisialisasiList(&resultList, MAX_DIGITS);

    prosesMasukan(num1, num2, &num1List, &num2List);

    tambahBesar(&resultList, &num1List, &num2List);

    tampilkanList(resultList);

    return 0;
}
