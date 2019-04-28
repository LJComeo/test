#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Menu(){
	printf("***********************************\n");
	printf("            1.开始游戏             \n");
	printf("            0.结束游戏             \n");
	printf("***********************************\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MAX_ROW 3
#define MAX_COL 3

char chess_board[MAX_ROW][MAX_COL];

void Init(){
	//创建棋盘
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			chess_board[row][col] = ' ';
		}
	}
}
void Print(){
	//打印棋盘
	for (int row = 0; row < MAX_ROW; ++row){
		printf("| %c | %c | %c |\n", chess_board[row][0],
			chess_board[row][1], chess_board[row][2]);
		if (row != MAX_ROW - 1){
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove(){
	//玩家落子
	printf("玩家落子！\n");
	while (1){
		int row = 0;
		int col = 0;
		printf("请输入一组坐标(row,col): ");
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0
			|| col >= MAX_COL || col < 0){
			printf("您的输入非法！\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("您输入的位置已经被占用！\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
//返回x表示玩家胜利
//返回o表示电脑胜利
//返回q表示和棋
//返回‘ ’表示未分出胜负，也不是和棋，游戏继续

int IsFull(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
char CheckGameOver(){
	//判断游戏是否结束
	//检查所有的行
	for (int col = 0; col < MAX_COL; ++col){
		if (chess_board[0][col] == chess_board[1][col] &&
			chess_board[0][col] == chess_board[2][col])
			return chess_board[0][col];
	}
	//检查所有的列
	for (int row = 0; row < MAX_ROW; ++row){
		if (chess_board[row][0] == chess_board[row][1] &&
			chess_board[row][0] == chess_board[row][2])
			return chess_board[row][0];
	}
	//检查所有的对角线
	if (chess_board[0][0] == chess_board[1][1] &&
		chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] &&
		chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	if (IsFull()){
		return 'q';
	}
	return ' ';
}
void ComputerMove(){
	//电脑落子
	printf("电脑落子！\n");
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' '){
			continue;
		}
		else{
			chess_board[row][col] = 'o';
			break;
		}
	}
}
void Game(){

	//1.创建并初始化一个棋盘
	Init();
	char winner = ' ';
	while (1){
		system("cls");
		//2.打印棋盘
		Print();
		//3.玩家落子
		PlayerMove();
		//4.判断游戏是否结束
		winner = CheckGameOver(); {
			if (winner != ' ')
				break;
		}
		//5.电脑落子
		ComputerMove();
		//6.判断游戏是否结束
		winner = CheckGameOver();
		if (winner != ' '){
			break;
		}
	}
	system("cls");
	Print();
	if (winner == 'x'){
		printf("玩家胜利!\n");
	}
	else if (winner == 'o'){
		printf("你真菜，连电脑都下不过!\n");
	}
	else if (winner == 'q'){
		printf("你还是真菜，和电脑五五开!\n");
	}
	else{
		printf("好像出错了!\n");
	}
}
int main(){
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();

		}
		else if (choice == 0){
			printf("期待与您的下次皇城PK\n");
			break;
		}
		else{
			printf("您的输入有误！\n");
		}
	}
	system("pause");
	return 0;
}