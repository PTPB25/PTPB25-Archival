
#include <stdio.h>

// Menghitung FPB antara A dan B
int main(){
	int A, B, dummy;
	scanf("%d", &A);
	scanf("%d", &B);
	while(B > 0){
		dummy = B;
		B = A % B;
		A = dummy;
	}
	printf("%d\n", A);
}
