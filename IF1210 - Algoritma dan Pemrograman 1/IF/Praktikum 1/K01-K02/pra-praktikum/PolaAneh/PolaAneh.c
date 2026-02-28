/* Muhammad Fatih Irkham Mauludi - 13524004 - K02 */
#include <stdio.h>

int main(){
	int n, i, j, mid;
	scanf("%d", &n);
	mid = n/2;

	for(i=0;i<(n+1)/2;i++){
		for(j=0;j<n;j++){
			if(j == mid-i || j == mid+i){
				printf("*");
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}

	for(i=n/2 - 1;i>=0;i--){
		for(j=0;j<n;j++){
			if(j == mid-i || j == mid+i){
				printf("*");
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}
}