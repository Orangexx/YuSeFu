//

#include "stdafx.h"
#include<stdlib.h>
#include<iostream>


using namespace std;

typedef struct LNode
{
	int number;
	int password;
	struct LNode* next;
}LNode, *LinkList;

void ListIn(LinkList &L, int Password)
{
	LNode* p = L;

	int i = 2;
	while (p->next != L)
	{
		p = p->next;
		i++;
	}
	LNode* q = (LNode*)malloc(sizeof(LNode));
	q->password = Password;
	q->number = i;
	q->next = L;
	p->next = q;
}

void HeXin(LinkList L, int *num, int *pass, int m)
{
	LNode* p = L;
	LNode* q = L;
	LNode* o = L;

	while (o->next != L)
	{
		o = o->next;
	}

	int i = 1;
	int j = -1;
	while (p->next != p)
	{
		i = 1;
		j++;
		while (i != m)
		{
			i++;
			o = o->next;
			p = p->next;
		}
		num[j] = p->number;
		pass[j] = p->password;
		m = p->password;
		o->next = p->next;
		q = p;
		p = o->next;
		free(q);
	}
	j++;
	num[j] = p->number;
	pass[j] = p->password;
}

int main()
{
	LinkList L = (LNode*)malloc(sizeof(LNode));
	L->next = L;

	int num;
	cin >> num;
	int* Number;
	Number = (int*)malloc(sizeof(int)*num);
	int* Password;
	Password = (int*)malloc(sizeof(int)*num);

	int m;
	cin >> m;

	int password;
	for (int i = 0; i < num; i++)
	{
		cin >> password;
		if (i == 0)
		{
			L->number = 1;
			L->password = password;
		}
		else ListIn(L, password);
	}

	HeXin(L, Number, Password, m);

	for (int i = 0; i < num; i++)
	{
		cout << Number[i] << "    " << Password[i] << endl;
	}
}
