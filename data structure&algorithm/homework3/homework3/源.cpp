//3: ��β��ͷ��ӡ����
//����
//����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
//��������0 <= ������ <= 10000
//- 1��ʾ���������
//�����ת�������
//��������
//1 2 6 3 4 5 6 - 1
//�������
//6 5 4 3 6 2 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //��β�巨������ͷ���ĵ�����
LinkList SwitchList(LinkList L);//ͷβת��
void Printlist(LinkList L);//��ӡ���
int main(void) {
	LinkList head = CreatList();
	LinkList P= SwitchList(head);
	Printlist(P);
}

LinkList CreatList(void) {
	LinkList head = new LNode;
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	int e;
	while (1) {
		scanf("%d", &e);
		if (e == -1) break;//�жϽ���
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return head;
}
LinkList SwitchList(LinkList L)
{
	LinkList P = new LNode;
	P->next = NULL;
	LinkList r, q;
	r = P;
	q = L->next;
	while (q)
	{
		LinkList s = new LNode;
		s->next =r->next;
		s->val = q->val;
		r->next = s;
		q = q->next;
	}
	return P;
}
void Printlist(LinkList L) {
	LinkList p;
	p = L->next;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
}
