/* Muhammad Fatih Irkham Mauludi - 13524004 - K02 */
#include <stdio.h>
#include <math.h>


double convert_temp(double x, char a, char b){
	if(a == 'C'){
		if(b == 'F'){
			return x * 9 / 5 + 32;
		}
		else{
			return x + 273.15;
		}
	}
	else if(a == 'F'){
		if(b == 'C'){
			return (x - 32) * 5 / 9;
		}
		else{
			return (x - 32) * 5 / 9  + 273.15;
		}
	}
	else{
		if(b == 'C'){
			return x - 273.15;
		}
		else{
			return (x - 273.15) * 9 / 5 + 32;
		}
	}
}

int main(){
	int n, i;
	double x;
	char a,b;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%lf %c %c", &x, &a, &b);
		printf("%.2lf\n", floor(convert_temp(x, a, b)));
	}
}