#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Menu(){
	printf("---------------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
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
	//1.ʹ�ö�ά�����ʾ��ͼ
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//2.��������г�ʼ��Ϊȫδ����
	Init(show_map, mine_map);
	int black_count = 0;
	while (1){
		system("cls");
		//3.��ӡ��ͼ
		Print(show_map);
		//4.�����������һ�������ʾ����һ��λ�ã���У���������Ч��
		printf("��������Ҫ����������(row,col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("������������\n");
			continue;
		}
		if (show_map[row][col] != '*'){
			printf("�������λ���ѷ�����\n");
			continue;
		}


		//5.���ж��Ƿ���ף������ף�����ʾ��game over����
		if (mine_map[row][col] == '1'){
			system("cls");
			printf("�����ˣ�\n");
			return;
		}
		//6.��δ���ף����ж���Ϸ�Ƿ�ʤ�����������в����׵ĸ��ӣ�
		if (black_count == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("��ϲ�㣬ɨ�׳ɹ���\n");
			return;
		}
		//7.��δ���ף��������ҵ�ǰλ����Χ�м�����
		UpdateShowMap(row, col, mine_map, show_map);
	}
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		printf("����������ѡ��:\n");
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("��ӭ�´���Ϸ��\n");
			break;
		}
		else{
			printf("������������\n");
		}
	}
	system("pause");
	return 0;
}