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
	printf("1.��������(����ֵΪ0ʱֹͣ)\n");
	printf("2.�����������Ԫ��\n");
	printf("3.Ԫ������\n");
	printf("4.����һ���ǵݼ�����������\n");
	printf("5.ɾ�����е�ż��Ԫ�ؽ��\n");
	printf("6.����֪�ǵݼ����������в���һ��Ԫ��\n");
	printf("7.���������ǵݼ������ϲ��ɷǵ�������\n");
	printf("8.�˵���ʾ\n");
	printf("9.�˳�\n");
	Linklist L;
	while (1)
	{
		int num;
		printf("�����빦��:");
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
				  printf("����Ҫɾ����Ԫ��:");
				  scanf("%d", &x);
				  deleven(L,x); 
				  display(L); 
				  break; 
		} case 6: 
		{ 
			int x; 
			printf("����һ����Ԫ��:");
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
				  printf("1.��������(����ֵΪ0ʱֹͣ)\n");
				  printf("2.�����������Ԫ��\n");
				  printf("3.Ԫ������\n");
				  printf("4.����һ���ǵݼ�����������\n");
				  printf("5.ɾ������Ԫ�ؽ��x\n");
				  printf("6.����֪�ǵݼ����������в���һ��Ԫ��\n");
				  printf("7.���������ǵݼ������ϲ��ɷǵ�������\n");
				  printf("8.�˵���ʾ\n");
				  printf("9.�˳�\n");
				   break;
		
		} 
		case 9: 
		{ 
				   return 0;
		}
		}
	} return 0;
}
