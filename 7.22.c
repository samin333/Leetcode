#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

void InitList(node *L)
{
	node* r,*s;
	r = L;
	int flag = 1;
	while (flag)
	{
		int i;
		scanf("%d", &i);
		if (i != -1)
		{
			s = (node*)malloc(sizeof(node));
			r->next = s;
			s->data = i;
			r = s;
		}
		else
		{
			flag = 0;
			r->next = NULL;
		}
	}
}

void print(node *L)
 {
	node* p = L->next;
	while (p)
	 {
		 printf("%d ", p->data);
		 p = p->next;
	 }
 }

node*  Merege(node* L1, node* L2)
{
	node* L3;
	node* p = L1->next;
	node* q = L2->next;
	L3 = L1;
	L3->next = NULL;
	node* r = L3;
	while (p && q)
	{
		if (p->data <= q->data)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}	
	}
	if (p) r->next = p;
	else r->next = q;


	return L3;
}

int main()
{

	node* L1 = (node*)malloc(sizeof(node));
	node* L2 = (node*)malloc(sizeof(node));
	InitList(L1);
	InitList(L2);
	node* L3 = Merege(L1, L2);
	print(L3);

	return 0;
}