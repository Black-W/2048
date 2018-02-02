#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char a[36],b[36],c[36],d[36];
	while(scanf("%[^\n]%*c",&a)!=EOF&&scanf("%[^\n]%*c",&b)!=EOF&&scanf("%[^\n]%*c",&c)!=EOF&&scanf("%[^\n]%*c",&d)!=EOF) {
		for(int i=0; i<40; i++)printf("=");
		printf("\n");
		printf("| %s%*c\n",a,40-2-strlen(a),'|');
		if(strlen(b)%2==0) {
			printf("|%*s%*c\n",(38-strlen(b))/2+strlen(b),b,40-((38-strlen(b))/2+strlen(b))-1,'|');
		}
		if(strlen(b)%2!=0) {
			printf("| %*s%*c\n",(38-strlen(b))/2+strlen(b),b,40-((38-strlen(b))/2+strlen(b))-2,'|');
		}
		if(strlen(c)%2==0) {
			printf("|%*s%*c\n",(38-strlen(c))/2+strlen(c),c,40-((38-strlen(c))/2+strlen(c))-1,'|');
		}
		if(strlen(c)%2!=0) {
			printf("| %*s%*c\n",(38-strlen(c))/2+strlen(c),c,40-((38-strlen(c))/2+strlen(c))-2,'|');
		}
		printf("|%*s |\n",37,d);
		for(int i=0; i<40; i++)printf("=");
		printf("\n");
		for(int i=0; i<36; i++) {
			if(a[i]!='\0')a[i]='\0';
			if(b[i]!='\0')b[i]='\0';
			if(c[i]!='\0')c[i]='\0';
			if(d[i]!='\0')d[i]='\0';
		}
	}
	return 0;
}
