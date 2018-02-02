#include <stdio.h>
#include <string.h>
int main() {
	char a[500],b[500],c[1000];
	int len1,len2,len3,i,j;
	for(i=0; i<500; i++)a[i]=0;
	for(i=0; i<500; i++)b[i]=0;
	for(i=0; i<500; i++)c[i]=0;
	//printf("c[0]=%d\n",c[0]);
	while(scanf("%s%*c",a)!=EOF&&scanf("%s%*c",b)!=EOF) {
		//	printf("c[0]=%d\n",c[0]);
		//	printf("a[0]=%d\n",a[0]);
		//	printf("a[0]=%d\n",b[0]);
		len1=(strlen(a)<strlen(b)?strlen(a):strlen(b));
		len2=(strlen(a)>strlen(b)?strlen(a):strlen(b));
		//	printf("%d%d\n",len1,len2);
		if(strlen(a)<=strlen(b)){
		for(i=len1-1;i>=0; i--) {
			for(j=len2-1;j>=0;j--){
				int num=len1+len2-2-i-j;
			c[num]+=((a[i]-48)*(b[j]-48));
				//printf("c[%d]=%d\n",num,c[num]);
			if(c[num]>=10) {
				c[num+1]+=c[num]/10;
				c[num]%=10;
			//	printf("c[%d]=%d\n",num+1,c[num+1]);
			}
		}
	}
}
	
	
		if(strlen(a)>strlen(b)){	
		for(i=len1-1;i>=0; i--) {
			for(j=len2-1;j>=0;j--){
				int num=len1+len2-2-i-j;
			c[num]+=((a[j]-48)*(b[i]-48));
//				printf("c[%d]=%d\n",num,c[num]);
			if(c[num]>=10) {
				c[num+1]+=c[num]/10;
				c[num]%=10;
//				printf("c[%d]=%d\n",num+1,c[num+1]);
			}
		}
	}
}
		for(i=0; i<500; i++)a[i]=0;
		for(i=0; i<500; i++)b[i]=0;
		//printf("c[0]=%d\n",c[0]);
		if(c[len1+len2-1]==0) {
			for(i=len1+len2-2; i>=0; i--)
				printf("%d",c[i]);
			printf("\n");
		} else {
			for(i=len1+len2-1; i>=0; i--)
				printf("%d",c[i]);
			printf("\n");
		}
		for(i=0; i<1000; i++)c[i]=0;

	}
	return 0;
}
