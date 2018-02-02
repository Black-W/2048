#include <stdio.h>
#include <math.h>
int main(){
	double x1,x2,a;
	while(scanf("%lf",&a)==1){
		x1=a/2;
		do{
			x2=(x1+a/x1)/2;
			if(fabs(x1-x2)<0.00001){
				printf("%.3lf\n",x2);
				break;
			}
			x1=x2;
		}while(1);
	}
	
	return 0;
} 
