
//2: ɾ�����������е��ظ�Ԫ��
//����
//����һ��������������ͷ head �� ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� �����������������
//����
//��������������������нڵ���Ŀ�ڷ�Χ[0, 300] �ڣ� - 100 <= Node.val <= 100����Ŀ���ݱ�֤�����Ѿ�����������
//- 1��ʾ���������
//���
//��������������
//��������
//1 1 2 3 3 - 1
//�������
//1 2 3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct LNode {
	int val=-333;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //��β�巨������ͷ���ĵ�����
LinkList DeleteList(LinkList L);    //ɾ���ظ�ֵ�Ľ��,������
void Printlist(LinkList L);//��ӡ���
int main(void) {
	LinkList head = CreatList();
	DeleteList(head);
	Printlist(head);
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
LinkList DeleteList(LinkList L) {
	LinkList p = L;
	while (p->next) {
		if (p->next->val == p->val) p->next = p->next->next;
		else p = p->next;
	}
	return L;
}
void Printlist(LinkList L) {
	LinkList p;
	p = L->next;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
}