#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int findnum(int a[][3], int x, int y, int n){
	int i = 0, j = y - 1;
	while (i < x&&y >= 0){
		if (a[i][j]>n){
			j--;
		}
		else if (a[i][j] < n){
			i++;
		}
		else
			return 1;
	}
	return 0;
}
int main(){
	int a[][3] = { { 1, 2, 3 }, { 4, 5, 6, }, { 7, 8, 9 } };

	if (findnum(a, 3, 3, 6)){
		printf("找到了\n");
	}
	else {
		printf("没找到\n");
	}
	

	system("pause");
	return 0;
}