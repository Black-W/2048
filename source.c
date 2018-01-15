Author:Zhenwei Wang
Email:664129552@qq.com
Data:2017/12/18
*/
#include <stdio.h>
#include <conio.h>		//���� getch()�����·����������ж� 
#include <stdlib.h> 	//����srand(),rand(),system(),exit(),��������������,ʵ�֡�������,�Լ���ֹ���� 
#include <time.h>		//����time(),������������������
#define SIZE 4			//���̱߳�
#define WINSCORE 2048	//�ж�ʤ���ķ��� 
void start_game();		//��ʼ��Ϸ
void initial_game();	//��ʼ����Ϸ����
//�����������ƶ�
void rotate_board();	//˳ʱ����ת����90��
void move_up();
void move_left();
void move_right();
void move_down();

void add_random();	//��board��������һ��������2����4��2�ĸ�����4��������
int count_empty();	//���ص�ǰboard������Ϊ�յĸ�����0��ʾ����������
void check_game_ended();	//������Ϸ�Ƿ�����������game_ended=1��δ����game_ended=0
void check_game_win();	//������Ϸ�Ƿ�ʤ����ʤ��game_win=1,δʤ��game_win=0
void print_board();		//������Ϸ����


int board[SIZE][SIZE];	//������Ϸ��������
int need_add_random=0;	//�Ƿ���Ҫ����Ԫ�ر��ǣ�1��ʾ��Ҫ��0��ʾ����Ҫ��
int game_ended=0;		//��Ϸ�������ǣ�1��ʾ������0��ʾδ������
int game_win=0;		//��Ϸʤ�����ǣ�1��ʾʤ����0��ʾδʤ����
int score=0;			//��Ϸ�÷�
int main() {
	while(1) {						//ѭ��һ�ξ���һ���µ���Ϸ
		initial_game();				//��ʼ������
		start_game();				//��Ϸ���к���
		if(game_ended) {			//�и�
			printf("                       GAME OVER.   PLAY AGAIN? (Y/N)");
			int ch;
			while(ch=getch()) {
				if(ch=='y'||ch=='Y')break;	//������Ϸ
				if(ch=='n'||ch=='N')exit(0);//�˳���Ϸ
			}
		} else if(game_win) {		//��ʤ
			printf("                        YOU WIN.   PLAY AGAIN? (Y/N)");
			int ch;
			while(ch=getch()) {
				if(ch=='y'||ch=='Y')break;
				if(ch=='n'||ch=='N')exit(0);
			}
		}
	}
	return 0;
}
void start_game() {
	int ch;
	while(!game_ended&&!game_win) {
		need_add_random=0;		//ÿ���ƶ�ǰ�����ӱ�������
		ch=getch();
		switch(ch) {
			case'w':
			case'W':
			case 72:
				move_up();
				break;
			case's':
			case'S':
			case 80:
				move_down();
				break;
			case'a':
			case'A':
			case 75:
				move_left();
				break;
			case'd':
			case'D':
			case 77:
				move_right();
				break;
			case'q':
			case'Q':
				printf("Thanks for using.Bye.");
				exit(0);
				break;
			default:
				;
		}
		if(need_add_random) {	//���ӱ���Ϊ1ʱ��������������������
			add_random();
			print_board();
		}
		check_game_ended();		//������Ϸ�Ƿ��������������޸�game_ended=1
		check_game_win();		//������Ϸ�Ƿ�ʤ������ʤ���޸�game_win=1
	}
}
void initial_game() {
	game_win=0;
	game_ended=0;							//��ʼ����־
	score=0;
	int x,y;
	for(x=0; x<SIZE; x++) {
		for(y=0; y<SIZE; y++)board[x][y]=0;	//��������
	}
	add_random();
	add_random();						//���̼���2��������
	print_board();							//��ӡ����
}
void rotate_board() {	//˳ʱ����ת����90��
	int board2[SIZE][SIZE];
	int x,y;
	for(x=0; x<SIZE; x++) {				//��board2�洢Board��ת���Ľ���
		for(y=0; y<SIZE; y++) {
			board2[y][SIZE-1-x]=board[x][y];
		}
	}
	for(x=0; x<SIZE; x++) {				//�������Ż�Board
		for(y=0; y<SIZE; y++) {
			board[x][y]=board2[x][y];
		}
	}
}
void move_up() {
	int x,y,p;								//y=������x=������p=ɨ������
	for(y=0; y<SIZE; y++)	    			//�������ºϲ���ͬ��Ԫ��
		for(x=0; x<SIZE; x++) {
			if(board[x][y]==0);
			else {							//�ҵ�ÿһ�е�һ��������Ԫ��board[x][y]
				for(p=x+1; p<SIZE; p++) {
					if(board[p][y]==0);
					else if(board[p][y]==board[x][y]) {	//�ҵ������е�һ������Ԫ�������ķ���Ԫ��board[p][y]
						board[x][y]*=2;		//�ϲ�����һ������Ԫ��
						board[p][y]=0;		//��һ��Ԫ����Ϊ0
						score+=board[x][y];//ÿ�ϳ�һ��Ԫ�أ����µ÷�
						x=p;				//��p��ʼ��������Ѱ���µĵ�һ������Ԫ�أ��ظ���������
						need_add_random=1;  //ÿ����Ч�ƶ�������Ҫ������Ԫ��
						break;
					} else break;			//��һ��Ԫ�ز���ͬ�򲻺ϲ�
				}
			}
		}
	for(y=0; y<SIZE; y++)    		//�����ƶ��ϲ�����Ԫ��
		for(x=0; x<SIZE; x++) {
			if(board[x][y]==0);
			else {
				for(p=x; p>0&&board[p-1][y]==0; p--) {
					board[p-1][y]=board[p][y];
					board[p][y]=0;		//�ҵ�����Ԫ�أ�����Ԫ�������пո��������Ƶ�û�пո���λ��
					need_add_random=1;  //ÿ����Ч�ƶ�������Ҫ������Ԫ��
				}
			}
		}
}
void move_down() {				//��ת��up���������ƶ�
	rotate_board();
	rotate_board();
	move_up();					//�ƶ�������ת��down����
	rotate_board();
	rotate_board();
}

void move_left() {				//ԭ��ͬ��
	rotate_board();
	move_up();
	rotate_board();
	rotate_board();
	rotate_board();
}
void move_right() {				//ԭ��ͬ��
	rotate_board();
	rotate_board();
	rotate_board();
	move_up();
	rotate_board();
}

void add_random() {		//��board��������һ��������2����4��2�ĸ�����4��������
	int  n,count,x,y,temp,num;
	if((count=count_empty())==0)return;
	srand(time(0));			//��������������
	temp=rand()%3;			//ȡ������0��1��2
	if(temp==2)num=4;		//��������Ϊ2���¼�Ԫ��Ϊ4�������¼�Ԫ��Ϊ2�������¼�Ԫ����2�ĸ�����4������
	else num=2;
	n=(rand()%count)+1;//ȷ���¼�Ԫ�ص�λ���ǵ�n����Ԫ��
	for(x=0; x<SIZE; x++)
		for(y=0; y<SIZE; y++) {
			if(board[x][y]==0&&--n==0) {
				board[x][y]=num;
				return;
			}
		}
}
int count_empty() {	//���ص�ǰboard������Ϊ�յĸ�����0��ʾ����������
	int count=0,x,y;
	for(x=0; x<SIZE; x++)
		for(y=0; y<SIZE; y++)if(board[x][y]==0)count++;
	return count;
}
void check_game_ended() {	//������Ϸ�Ƿ���������������1��δ��������0
	int x,y;
	if(count_empty())return;//����δ�������飬�ض�δ����
	for(x=0; x<SIZE; x++) {	//���������Ƚ������������ȵ�Ԫ�أ�������Ϸ��������û������Ϸ����
		for(y=0; y<SIZE-1; y++) {
			if(board[x][y]==board[x][y+1]||board[y][x]==board[y+1][x]) {
				game_ended=0;
				return;
			}
		}
	}
	game_ended=1;
}
void check_game_win() {	//������Ϸ�Ƿ�ʤ����ʤ��game_win=1,δʤ��game_win=0
	int x,y;
	for(x=0; x<SIZE; x++) {	//����Ԫ��2048����ʤ��
		for(y=0; y<SIZE; y++) {
			if(board[x][y]==WINSCORE) {
				game_win=1;
				return;
			}
		}
	}
	game_win=0;
}
void print_board() {		//������Ϸ����
	system("cls");		//����
	printf("\n\n\n\n");
	printf("                               GAME:    2048\n\n");
	printf("                                 SCORE:%-6d\n\n",score);
	printf("                        W:�� A:�� D:�� S:�� Q:quit\n");
	printf("             --------------------------------------------------\n\n");
	printf("                        �������Щ����Щ����Щ�����\n");
	for (int i=0; i<SIZE; i++) {
		printf("                        ��");
		for (int j=0; j<SIZE; j++) {
			if (board[i][j]!= 0)printf("%-4d��", board[i][j]);
			else printf("    ��");
		}
		if (i<SIZE-1) {
			printf("\n                        �������੤���੤���੤����\n");
		} else {
			printf("\n                        �������ة����ة����ة�����\n");
		}
	}
	printf("\n");
	printf("             --------------------------------------------------\n");
	printf("             Copyright @ 2017, Zhenwei Wang all rights reserved.\n\n");
}
