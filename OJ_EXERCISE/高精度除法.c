#include <stdio.h>
int main(){
	long long int a,b,c,y;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF){
		if(c!=0){
		printf("%lld.",a/b);
		while(c--){
			y=a%b;
			a=y*10;
			if(c!=0){
			printf("%lld",a/b);}
			if(c==0){
				if(((a%b)*10/b)>=5){
					printf("%lld",a/b+1);
				}
				else printf("%lld",a/b);
			}	
		}
		printf("\n");
	}
	else if(c==0){
	if(((a%b)*10/b)>=5)
	printf("%lld\n",a/b+1);
	else printf("%lld\n",a/b);
}
}
	return 0;
}
