#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	LNode *next;
} LNode, *Linklist;
void creat(Linklist &L)
{
	ElemType x;
	Linklist p=nullptr;
	Linklist q;
	L = new LNode;
	q = L;
	cout << "pleas enter x:";
	cin >> x;
	while (x)
	{
		p = new LNode;
		p->data = x;
		q->next = p;
		q = p;
		cout << "pleas enter x:";
		cin >> x;
	}
	p->next = NULL;
}
void display(Linklist &L)
{
	Linklist p;
	p = L->next;
	cout << endl;
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}
void reverse(Linklist &L)
{
	Linklist p, q, tmp;
	p = L;
	q = L->next;
	p = NULL;
	while (q != NULL)
	{
		tmp = q->next;
		q->next = p;
		p = q;
		q = tmp;
	}
	q = new LNode;
	q->next = p;
	L = q;
}
void deleven(Linklist &L, ElemType x)
{
	Linklist p, q;
	q = L->next;
	p = L;

	while (q&&q->data != x){
		p = q;
		q = q->next;
	}
	if (!q){
		printf("not deleted");
	}
	else {
		p->next = q->next;
		free(q);
	}
}
void insert(Linklist &L, Linklist &q)
{
	Linklist p;
	p = L->next;
	if (p == NULL)
	{
		L->next = q;
		return;
	}
	int flag = 0;
	while (p->next != NULL)
	{
		if (q->data >= p->data&&q->data <= p->next->data)
		{
			q->next = p->next;
			p->next = q;
			flag = 1;
			return;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		if (q->data >= p->data)
		{
			p->next = q;
			q->next = NULL;
		}
		else
		{
			p = L->next;
			L->next = q;
			q->next = p;
		}
	}
	return;
}
void creat2(Linklist &L)
{
	ElemType x;
	Linklist p;
	L = new LNode;
	L->next = NULL;
	cout << "pleas enter x:";
	cin >> x;
	while (x)
	{
		p = new LNode;
		p->data = x;
		p->next = NULL;
		insert(L, p);
		//display(L);
		cout << "pleas enter x:";
		cin >> x;
	}
}
void  merge(Linklist &A, Linklist &B)
{
	Linklist p, q;
	p = B->next;
	while (p != NULL)
	{
		q = new LNode;
		q->data = p->data;
		insert(A, q);
		p = p->next;
	}
}
void divide(Linklist &L)
{
	Linklist A = L;
	Linklist B = new LNode;
	Linklist p = L->next, a = A, b = B;
	while (p != NULL)
	{
		if (p->data % 2 == 1)
		{
			a->next = p;
			a = a->next;
		}
		else
		{
			b->next = p;
			b = b->next;
		}
		p = p->next;
	}
	a->next = NULL;
	b->next = NULL;
	display(A);
	display(B);
}
int main()
{
	printf("1.创建链表(输入值为0时停止)\n");
	printf("2.历遍链表并输出元素\n");
	printf("3.元素逆序\n");
	printf("4.建立一个非递减有序单向链表\n");
	printf("5.删除所有的偶数元素结点\n");
	printf("6.在已知非递减有序链表中插入一个元素\n");
	printf("7.创建两个非递减链表并合并成非递增链表\n");
	printf("8.菜单提示\n");
	printf("9.退出\n");
	Linklist L;
	while (1)
	{
		int num;
		printf("请输入功能:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
				  creat(L);
				  break;
		}
		case 2:
		{
				  display(L);
				  break;
		}
		case 3:
		{
				  reverse(L);
				  display(L);
				  break;
		}
		case 4:
		{ 
				  creat2(L);
				  display(L);
				  break;
		} 
		case 5: 
		{ 
				  creat2(L);
				  display(L);
				  int x;
				  printf("输入要删除的元素:");
				  scanf("%d", &x);
				  deleven(L,x); 
				  display(L); 
				  break; 
		} case 6: 
		{ 
			int x; 
			printf("输入一个新元素:");
			scanf("%d", &x);
			Linklist q = new LNode;
			q->data = x;
			q->next = NULL;
			insert(L, q);
			display(L);
			break;
		} 
		
		case 7:
		{ 
				  Linklist A, B;
				  creat2(A);
				  creat2(B); 
				  merge(A, B);
				  reverse(A); 
				  display(A); 
				  break; 
		} 
		case 8:
		{ 
				  printf("1.创建链表(输入值为0时停止)\n");
				  printf("2.历遍链表并输出元素\n");
				  printf("3.元素逆序\n");
				  printf("4.建立一个非递减有序单向链表\n");
				  printf("5.删除输入元素结点x\n");
				  printf("6.在已知非递减有序链表中插入一个元素\n");
				  printf("7.创建两个非递减链表并合并成非递增链表\n");
				  printf("8.菜单提示\n");
				  printf("9.退出\n");
				   break;
		
		} 
		case 9: 
		{ 
				   return 0;
		}
		}
	} return 0;
}
