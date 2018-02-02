#include <stdio.h>
int main() {
	int n;
	char a[200];
	char b[200];
	for(int i=0; i<200; i++) {
		a[i]=b[i]=0;
	}
	while(scanf("%d%s%*c",&n,a)==2) {
		for(int i=0; i<n; i++) {
			a[i]-=48;
		}
		for(int i=0,j=n; j>0; i++,j--) {
			b[j]=a[i];
		}
		b[n]+=1;
		for(int i=n; i>0; i--) {
			if(b[i]>=10) {
				b[i]%=10;
				b[i-1]+=1;
			}
		}
		for(int i=n; i>0; i--) {
			printf("%d",b[i]);
		}
		if(b[0]!=0)printf("%d",b[0]);
		printf("\n");
		for(int i=0; i<200; i++) {
			a[i]=b[i]=0;
		}
	}
	return 0;
}
