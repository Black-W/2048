#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void) {
	char a,b,c,ch,code[2000];
	int i=0;
	while(scanf("%c%c%c%*c",&a,&b,&c)!=EOF) {
		i=0;
		if(a=='#'&&b=='#'&&c=='#') {
scan:
			while((ch=getchar())!='#') {
				if(ch!='/') {
					code[i++]=ch;
				} else {
					if((a=getchar())!='/'&&a!='*') {
						code[i++]=ch;
						code[i++]=a;
					} else if(a=='/') {
						while(getchar()!='\n');
						code[i++]='\n';
					} else {
scan2:
						while(getchar()!='*');
						if(getchar()=='/');
						else  goto scan2;
					}
				}
			}

			if((b=getchar())=='#'&&(c=getchar())=='#')getchar();
			else {
				code[i++]=ch;
				if(b!='#') {
					code[i++]=b;
					code[i++]=getchar();
				} else {
					code[i++]=b;
					code[i++]=c;
				}
				goto scan;
			}
		}
		for(int j=0; j<i; j++) {
			if(code[j]=='\n'&&code[j+1]=='\n');
			else printf("%c",code[j]);
		}

	}
	return 0;
}
