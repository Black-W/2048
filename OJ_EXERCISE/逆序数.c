#include <stdio.h>
#include <string.h>
int main() {
	char a[4];
	int i,l;
	for(i=0; i<4; i++) {
		a[i]='\0';
	}
	while(scanf("%s%*c",&a)==1) {
		//printf("a=%d\n",strlen(a));
		l=strlen(a);
		for(i=0; i<l; i++) {
			a[i]-=48;
		}
		for(i=l-1;i>=0;i--){
			//printf("1i=%d\n",i);
			if(a[i]!=0){
				for(i;i>=0;i--){
					//printf("2i=%d\n",i);
					printf("%d",a[i]);
				}
				printf("\n");
				break;
			}
		}
		
		

	}

	return 0;
}
