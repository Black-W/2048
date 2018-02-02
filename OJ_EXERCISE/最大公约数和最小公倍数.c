#include <stdio.h>
#include <math.h>
int main(void) {
	int a,b,x,y,z,idx;
	while(scanf("%d%d",&a,&b)!=EOF){
		z=a*b;
		if(a<b){
			idx=a;
			a=b;
			b=idx;
		}
		while(1){
			if(a%b==0){
				x=b;
				break;
			}
			else{
				b=a%b;
			}
		}
		y=z/x;
		printf("%d %d\n",x,y);
	}
	return 0;
}
