/*2048.c
Author:Zhenwei Wang
Email:664129552@qq.com
Data:2017/12/18
*/
#include <stdio.h>
#include <conio.h>		//包含 getch()，按下方向键立刻判断 
#include <stdlib.h> 	//包含srand(),rand(),system(),exit(),用来生成随机数,实现“清屏”,以及终止程序 
#include <time.h>		//包含time(),用来获得随机数种子
#define SIZE 4			//棋盘边长
#define WINSCORE 2048	//判断胜利的分数 
void start_game();		//开始游戏
void initial_game();	//初始化游戏棋盘
//向上下左右移动
void rotate_board();	//顺时针旋转棋盘90度
void move_up();
void move_left();
void move_right();
void move_down();

void add_random();	//向board数组添加一个随机数2或者4（2的概率是4的两倍）
int count_empty();	//返回当前board数组中为空的个数（0表示棋盘已满）
void check_game_ended();	//检查游戏是否结束，结束game_ended=1，未结束game_ended=0
void check_game_win();	//检查游戏是否胜利，胜利game_win=1,未胜利game_win=0
void print_board();		//输出游戏棋盘


int board[SIZE][SIZE];	//定义游戏棋盘数组
int need_add_random=0;	//是否需要添加元素标记（1表示需要，0表示不需要）
int game_ended=0;		//游戏结束标记（1表示结束，0表示未结束）
int game_win=0;		//游戏胜利标记（1表示胜利，0表示未胜利）
int score=0;			//游戏得分
int main() {
	while(1) {						//循环一次就是一次新的游戏
		initial_game();				//初始化棋盘
		start_game();				//游戏运行函数
		if(game_ended) {			//判负
			printf("                       GAME OVER.   PLAY AGAIN? (Y/N)");
			int ch;
			while(ch=getch()) {
				if(ch=='y'||ch=='Y')break;	//继续游戏
				if(ch=='n'||ch=='N')exit(0);//退出游戏
			}
		} else if(game_win) {		//判胜
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
		need_add_random=0;		//每次移动前将添加标记置零
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
		if(need_add_random) {	//添加标记为1时，向棋盘中添加随机数
			add_random();
			print_board();
		}
		check_game_ended();		//检查游戏是否结束，若结束修改game_ended=1
		check_game_win();		//检查游戏是否胜利，若胜利修改game_win=1
	}
}
void initial_game() {
	game_win=0;
	game_ended=0;							//初始化标志
	score=0;
	int x,y;
	for(x=0; x<SIZE; x++) {
		for(y=0; y<SIZE; y++)board[x][y]=0;	//棋盘清零
	}
	add_random();
	add_random();						//棋盘加入2个随机数
	print_board();							//打印棋盘
}
void rotate_board() {	//顺时针旋转棋盘90度
	int board2[SIZE][SIZE];
	int x,y;
	for(x=0; x<SIZE; x++) {				//用board2存储Board旋转后的结果
		for(y=0; y<SIZE; y++) {
			board2[y][SIZE-1-x]=board[x][y];
		}
	}
	for(x=0; x<SIZE; x++) {				//将结果放回Board
		for(y=0; y<SIZE; y++) {
			board[x][y]=board2[x][y];
		}
	}
}
void move_up() {
	int x,y,p;								//y=列数，x=行数，p=扫描行数
	for(y=0; y<SIZE; y++)	    			//从上向下合并相同的元素
		for(x=0; x<SIZE; x++) {
			if(board[x][y]==0);
			else {							//找到每一列第一个非零的元素board[x][y]
				for(p=x+1; p<SIZE; p++) {
					if(board[p][y]==0);
					else if(board[p][y]==board[x][y]) {	//找到离该列第一个非零元素最近的非零元素board[p][y]
						board[x][y]*=2;		//合并到第一个非零元素
						board[p][y]=0;		//另一个元素置为0
						score+=board[x][y];//每合成一个元素，更新得分
						x=p;				//从p开始继续往下寻找新的第一个非零元素，重复上述过程
						need_add_random=1;  //每次有效移动后都需要添加新元素
						break;
					} else break;			//第一对元素不相同则不合并
				}
			}
		}
	for(y=0; y<SIZE; y++)    		//向上移动合并后的元素
		for(x=0; x<SIZE; x++) {
			if(board[x][y]==0);
			else {
				for(p=x; p>0&&board[p-1][y]==0; p--) {
					board[p-1][y]=board[p][y];
					board[p][y]=0;		//找到非零元素，若该元素上面有空格，则上移到没有空格的位置
					need_add_random=1;  //每次有效移动后都需要添加新元素
				}
			}
		}
}
void move_down() {				//旋转到up方向，再移动
	rotate_board();
	rotate_board();
	move_up();					//移动后，旋转回down方向
	rotate_board();
	rotate_board();
}

void move_left() {				//原理同上
	rotate_board();
	move_up();
	rotate_board();
	rotate_board();
	rotate_board();
}
void move_right() {				//原理同上
	rotate_board();
	rotate_board();
	rotate_board();
	move_up();
	rotate_board();
}

void add_random() {		//向board数组添加一个随机数2或者4（2的概率是4的两倍）
	int  n,count,x,y,temp,num;
	if((count=count_empty())==0)return;
	srand(time(0));			//设置随机数种子
	temp=rand()%3;			//取随机数0，1，2
	if(temp==2)num=4;		//若随机数为2，新加元素为4，否则新加元素为2，所以新加元素是2的概率是4的两倍
	else num=2;
	n=(rand()%count)+1;//确定新加元素的位置是第n个空元素
	for(x=0; x<SIZE; x++)
		for(y=0; y<SIZE; y++) {
			if(board[x][y]==0&&--n==0) {
				board[x][y]=num;
				return;
			}
		}
}
int count_empty() {	//返回当前board数组中为空的个数（0表示棋盘已满）
	int count=0,x,y;
	for(x=0; x<SIZE; x++)
		for(y=0; y<SIZE; y++)if(board[x][y]==0)count++;
	return count;
}
void check_game_ended() {	//检查游戏是否结束，结束返回1，未结束返回0
	int x,y;
	if(count_empty())return;//棋盘未满不检查，必定未结束
	for(x=0; x<SIZE; x++) {	//横向纵向比较有无相邻相等的元素，有则游戏不结束，没有则游戏结束
		for(y=0; y<SIZE-1; y++) {
			if(board[x][y]==board[x][y+1]||board[y][x]==board[y+1][x]) {
				game_ended=0;
				return;
			}
		}
	}
	game_ended=1;
}
void check_game_win() {	//检查游戏是否胜利，胜利game_win=1,未胜利game_win=0
	int x,y;
	for(x=0; x<SIZE; x++) {	//若有元素2048，则胜利
		for(y=0; y<SIZE; y++) {
			if(board[x][y]==WINSCORE) {
				game_win=1;
				return;
			}
		}
	}
	game_win=0;
}
void print_board() {		//输出游戏棋盘
	system("cls");		//清屏
	printf("\n\n\n\n");
	printf("                               GAME:    2048\n\n");
	printf("                                 SCORE:%-6d\n\n",score);
	printf("                        W:↑ A:← D:→ S:↓ Q:quit\n");
	printf("             --------------------------------------------------\n\n");
	printf("                        ┌──┬──┬──┬──┐\n");
	for (int i=0; i<SIZE; i++) {
		printf("                        │");
		for (int j=0; j<SIZE; j++) {
			if (board[i][j]!= 0)printf("%-4d│", board[i][j]);
			else printf("    │");
		}
		if (i<SIZE-1) {
			printf("\n                        ├──┼──┼──┼──┤\n");
		} else {
			printf("\n                        └──┴──┴──┴──┘\n");
		}
	}
	printf("\n");
	printf("             --------------------------------------------------\n");
	printf("             Copyright @ 2017, Zhenwei Wang all rights reserved.\n\n");
}
