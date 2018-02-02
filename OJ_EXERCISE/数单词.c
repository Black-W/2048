#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(void) {
	int sum;
	char ch;
	while(scanf("%c%*c",&ch)!=EOF) {
		if(ch=='#') {
			sum=0;
			while((ch=getchar())!='#') {
				if(isalpha(ch)||ispunct(ch)||isdigit(ch)) {
					while((ch=getchar())!='\n'&&ch!='\t'&&ch!=' ') {
						if(ch=='#') {
							getchar();
							goto end;
						}
					}
					sum++;
				}
			}
			getchar();
end:
			printf("%d\n",sum);
		}
	}
	return 0;
}
