#include <stdio.h>
#define MAXSIZE 100
int main() {
	int a[MAXSIZE][MAXSIZE];
	int row,col,n,times;
	printf("Please enter n:\n"); 
	while(scanf("%d",&n)!=EOF){
		int num=0;
		if(n%2==0)times=n/2;
		else times=(n+1)/2;
		if(n>0){
			for(int i=0;i<times;i++){
				for(int j=i;j<n-i;j++)a[i][j]=++num;
				for(int k=i+1;k<n-i;k++)a[k][n-i-1]=++num;
				for(int m=n-i-2;m>=i;m--)a[n-i-1][m]=++num;
				for(int s=n-i-2;s>i;s--)a[s][i]=++num;
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(j<n-1)printf("%3d ",a[i][j]);
					else printf("%3d\n",a[i][j]);
				}
			}
		}
		else printf("ERROR!\n");
		printf("Please enter n:\n"); 
	}
	return 0;
}
