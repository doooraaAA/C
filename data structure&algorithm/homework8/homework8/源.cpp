//8: ɾ������ĵ����� N �����
//����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
//���������Ҫɾ����n �������н�����ĿΪ sz��
//1 <= sz <= 30��0 <= Node.val <= 100��1 <= n <= sz
//- 1��ʾ���������
//�������
//��������
//1 2 3 4 5 - 1
//2
//�������
//1 2 3 5
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //��β�巨������ͷ���ĵ�����
LinkList DeleteList(LinkList L, int n);//ɾ�����ֽڵ�
void PrintList(LinkList L);

int main(void) {
	LinkList head = CreatList();
	int n;
	scanf("%d", &n);
	DeleteList(head, n);
	PrintList(head);
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
LinkList DeleteList(LinkList L, int n) {
	int a = 0;
	LinkList p = L;
	LinkList q = L;
	while (p->next) {
		p = p->next;
		a++;
	}
	int c = a - n;
	while (c) {
		q = q->next;
		c--;
	}
	q->next = q->next->next;
	return L;
}

void PrintList(LinkList L) {
	LinkList q;
	q = L->next;
	while (q)
	{
		printf("%d ", q->val);
		q = q->next;
	}
}