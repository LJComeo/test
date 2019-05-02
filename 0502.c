#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Menu(){
	printf("---------------------\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("---------------------\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			mine_map[row][col] = '0';
		}
	}
	int mine_count = MINE_COUNT;
	while (mine_count>0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1'){
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}

void Print(char map[MAX_ROW][MAX_COL]){
	printf("  |");
	for (int col = 0; col < MAX_COL; ++col){
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL - 2; ++col){
		printf("---");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; ++row){
		printf("%d |", row);
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(int row, int col, char mine_map[MAX_ROW][MAX_COL],
	char show_map[MAX_ROW][MAX_COL]){
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0
		&& mine_map[row - 1][col - 1] == '1'){
		++count;
	}
	if (row - 1 >= 0
		&& mine_map[row - 1][col] == '1'){
		++count;
	}
	if (row - 1 >= 0 && col + 1<MAX_COL
		&& mine_map[row - 1][col + 1] == '1'){
		++count;
	}
	if (col - 1 >= 0
		&& mine_map[row][col - 1] == '1'){
		++count;
	}
	if (col + 1 <MAX_COL
		&& mine_map[row][col + 1] == '1'){
		++count;
	}
	if (row + 1 <MAX_ROW  && col - 1 >= 0
		&& mine_map[row + 1][col - 1] == '1'){
		++count;
	}
	if (row + 1 <MAX_ROW
		&& mine_map[row - 1][col] == '1'){
		++count;
	}
	if (row + 1 <MAX_ROW && col + 1 <MAX_COL
		&& mine_map[row + 1][col + 1] == '1'){
		++count;
	}
	show_map[row][col] = count + '0';
}


void Game(){
	//1.使用二维数组表示地图
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//2.对数组进行初始化为全未翻开
	Init(show_map, mine_map);
	int black_count = 0;
	while (1){
		system("cls");
		//3.打印地图
		Print(show_map);
		//4.题是玩家输入一个坐标表示翻开一个位置，并校验坐标的有效性
		printf("请输入你要翻开的坐标(row,col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("您的输入有误！\n");
			continue;
		}
		if (show_map[row][col] != '*'){
			printf("您输入的位置已翻开！\n");
			continue;
		}


		//5.先判断是否踩雷，若踩雷，则提示“game over！”
		if (mine_map[row][col] == '1'){
			system("cls");
			printf("踩雷了！\n");
			return;
		}
		//6.若未踩雷，则判断游戏是否胜利（翻开所有不是雷的格子）
		if (black_count == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("恭喜你，扫雷成功！\n");
			return;
		}
		//7.若未踩雷，则告诉玩家当前位置周围有几个雷
		UpdateShowMap(row, col, mine_map, show_map);
	}
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		printf("请输入您的选择:\n");
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("欢迎下次游戏！\n");
			break;
		}
		else{
			printf("您的输入有误！\n");
		}
	}
	system("pause");
	return 0;
}