//6: �ϲ���������
//������������ list1 �� list2 �����ǰ�����Ԫ�طֱ�Ϊ n ���� m ����
//���㽫 list1 ���±�� a �� b ��ȫ���ڵ㶼ɾ��������list2 ���ڱ�ɾ���ڵ��λ�á�
//3 <= list1.length <= 10 ^ 4
//1 <= a <= b < list1.length - 1
//	1 <= list2.length <= 10 ^ 4
//	- 1��Ϊ���������
//	�������
//	��������
//	0 1 2 3 4 5 - 1
//	3
//	4
//	1000000 1000001 1000002 - 1
//	�������
//	0 1 2 1000000 1000001 1000002 5
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
LinkList DeleteList(LinkList L,int a,int b);//ɾ�����ֽڵ�
LinkList AddList(LinkList L1, LinkList L2,int a);//�ϲ�
void PrintList(LinkList L);

int main(void) {
	LinkList head1 = CreatList();
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	LinkList head2 = CreatList();
	DeleteList(head1,a,b);
	AddList(head1, head2,a);
	PrintList(head1);
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
LinkList DeleteList(LinkList L, int a, int b) {
	LinkList q = L;
	int c = b - a+1;
	while (a)
	{
		q = q->next;//��ɾ��q->next
		a--;
	}
	while (c) {
		q->next = q->next->next;
		c--;
	}
	return L;
}
LinkList AddList(LinkList L1, LinkList L2,int a) {
	LinkList q=L1;
	LinkList p = L2->next;
	while (a)
	{
		q = q->next;//����q����
		a--;
	}
	while (p->next)
	{
		p = p->next;//������β��
	}
	p->next = q->next;
	q->next = L2->next;
	return L1;
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