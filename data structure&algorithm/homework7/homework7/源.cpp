//7: ��ת�����
//���㵥�����ͷָ�� head ���������� left �� right ������ left <= right �����㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת������� ��
///�����нڵ���ĿΪ n
//1 <= n <= 500
//- 500 <= Node.val <= 500
//1 <= left <= right <= n
//- 1��ʾ���������
//�������
//��������
//1 2 3 4 5 - 1 2 4
//�������
//1 4 3 2 5
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
LinkList SwitchList(LinkList L, int a, int b);//ת�����ֽڵ�
void PrintList(LinkList L);

int main(void) {
	LinkList head = CreatList();
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	SwitchList(head, a, b);
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
LinkList SwitchList(LinkList L, int a, int b) {
	LinkList q = L;
	int c = b - a + 1;
	LinkList head = new LNode;
	head->next = NULL;
	while (a-1)
	{
		a = a - 1;
		q = q->next;//��q->next�޸�
	}
	while (c) {//ͷ�巨����������
		LinkList r=new LNode;
 		r->val = q->next->val;
		r->next = head->next;
		head->next = r;
		q->next = q->next->next;
		c--;
	}
	LinkList s = head;
	while (s->next)
	{
		s = s->next;
	}
	s->next = q->next;
	q->next = head->next;
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
