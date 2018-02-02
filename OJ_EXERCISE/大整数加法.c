#include <stdio.h>
#include <string.h>
int main() {
	char a[200],b[200],c[200];
	int len1,len2,len3,i,j;
	for(i=0; i<200; i++)a[i]=0;
	for(i=0; i<200; i++)b[i]=0;
	for(i=0; i<200; i++)c[i]=0;
	//printf("c[0]=%d\n",c[0]);
	while(scanf("%s%*c",a)!=EOF&&scanf("%s%*c",b)!=EOF) {
		//	printf("c[0]=%d\n",c[0]);
		//	printf("a[0]=%d\n",a[0]);
		//	printf("a[0]=%d\n",b[0]);
		len1=(strlen(a)<strlen(b)?strlen(a):strlen(b));
		len2=(strlen(a)>strlen(b)?strlen(a):strlen(b));
		//	printf("%d%d\n",len1,len2);
		if(strlen(a)<=strlen(b)){
		
		for(i=len1-1,j=len2-1; i>=0; i--,j--) {
			c[j+1]+=a[i]-48+b[j]-48;
			//	printf("c[j+1]=%d\n",c[j+1]);
			if(c[j+1]>=10) {
				c[j+1]-=10;
				c[j]++;
			}
		}
		//printf("!!%d\n",j);
		if(j>=0) {
			for(; j>=0; j--) {
				c[j+1]+=b[j]-48;
				if(c[j+1]>=10) {
					c[j+1]-=10;
					c[j]++;
				}
			}
		}
		
	}
	
		if(strlen(a)>strlen(b)){
		
		for(i=len1-1,j=len2-1; i>=0; i--,j--) {
			c[j+1]+=a[j]-48+b[i]-48;
			//	printf("c[j+1]=%d\n",c[j+1]);
			if(c[j+1]>=10) {
				c[j+1]-=10;
				c[j]++;
			}
		}
	//	printf("!!%d\n",j);
		if(j>=0) {
			for(; j>=0; j--) {
				c[j+1]+=a[j]-48;
				if(c[j+1]>=10) {
					c[j+1]-=10;
					c[j]++;
				}
			}
		}
		
	}
		for(i=0; i<200; i++)a[i]=0;
		for(i=0; i<200; i++)b[i]=0;
		//printf("c[0]=%d\n",c[0]);
		if(c[0]==1) {
			for(i=0; i<=len2; i++)
				printf("%d",c[i]);
			printf("\n");
		} else {
			for(i=1; i<=len2; i++)
				printf("%d",c[i]);
			printf("\n");
		}
		for(i=0; i<200; i++)c[i]=0;

	}
	return 0;
}
