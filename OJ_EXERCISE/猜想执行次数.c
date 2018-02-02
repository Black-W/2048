#include <stdio.h>
#include <math.h>
double fact(double n){
	if(n==1){
		return 1;
	}
	else{
	n=n*fact(n-1);

	return n; 
}
}

double mypow(double x,double n){
	return pow(x,n);
}
int main() {
	double x,n;
	double sum=0;
	while(scanf("%lf%lf",&x,&n)==2) {
		for (double i=1;i<=n;i++){
			sum+=(pow(-1,i-1)*mypow(x,i))/fact(i);
		}
		printf("%.4lf\n",sum);
		sum=0;
		
	}
	return 0;
}
