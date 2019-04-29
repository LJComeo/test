#include <stdio.h>
#include <stdlib.h>
//逻辑表达式
//int main(){
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++&&++b&&d++;
//	printf("a=%d\nb=%d\nc=%d\nd=%d\ni=%d\n", a, b, c, d, i);
//	system("pause");
//	return 0;
//}

//逗号表达式
//int main(){
//	int a = 1;
//	int b = 2;
//	int c = (a > b, a = b + 10, a, b = a + 1);
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}

//函数调用操作
//void test1()
//{
//	printf("hehe\n");
//}
//void test2(const char *str)
//{
//	printf("%s\n", str);
//}
//int main(){
//	test1();
//	test2("hellow bit.");
//	system("pause");
//	return 0;
//}

//结构体成员访问
//struct Stu{
//	char name[10];
//	int age;
//	char sex[5];
//	double score;
//};
//void set_agel(struct Stu stu)
//{
//	stu.age = 18;
//}
//void set_age2(struct Stu* pStu)
//{
//	pStu->age = 18;
//}
//int main(){
//	struct Stu stu;
//	struct Stu* pStu = &stu;
//
//	pStu->age = 20;
//	set_age2(pStu);
//	system("pause");
//	return 0;
//}

//整形提升
//int main(){
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//	if (c == 0xb6000000)
//		printf("c");
//	system("pause");
//	return 0;
//}
//int main(){
//	char c = 1;
//	printf("%u\n", sizeof(c));
//	printf("%u\n", sizeof(+c));
//	printf("%u\n", sizeof(!c));
//	system("pause");
//	return 0;
//}

int main(){
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("%d\n", ret);
	printf("%d\n", i);
	system("pause");
	return 0;
}