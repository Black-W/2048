#include <stdio.h>
#define ROW_SIZE 4
#define COL_SIZE 4
typedef struct rowmax {
	int max;
	int row;
	int col;
} Rowmax;
typedef struct colmin {
	int min;
	int row;
	int col;
} Colmin;
int main() {
	int a[ROW_SIZE][COL_SIZE];
	int exit=1;
	Rowmax max[ROW_SIZE];
	Colmin min[COL_SIZE];

	for(int i=0; i<ROW_SIZE; i++) {
		for(int j=0; j<COL_SIZE; j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=0; i<ROW_SIZE; i++) {
		max[i].max=a[i][0];
		max[i].row=i;
		max[i].col=0;
		for(int j=0; j<COL_SIZE; j++) {
			if(max[i].max<a[i][j]) {
				max[i].max=a[i][j];
				max[i].col=j;
			}
		}
	}
	for(int j=0; j<COL_SIZE; j++) {
		min[j].min=a[0][j];
		min[j].row=0;
		min[j].col=j;
		for(int i=0; i<ROW_SIZE; i++) {
			if(min[j].min>a[i][j]) {
				min[j].min=a[i][j];
				min[j].row=i;
			}
		}
	}
	for(int i=0;i<ROW_SIZE;i++){
		if(max[i].max==min[max[i].col].min){
		exit=0;
		printf("value=%d row=%d col=%d\n",max[i].max,max[i].row+1,max[i].col+1);}
	}
	if(exit)printf("there is no andian.\n");
	return 0;
}

