//5: �ϲ�������������
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//��������˳���l1��l2��l1��l2�����ǵݼ�˳�����У���������Ľڵ���Ŀ��Χ��[0, 50]�� - 100 <= Node.val <= 100
//- 1��ʾ���������
//����ϲ����˳���
//��������
//1 2 4 - 1
//1 3 4 - 1
//�������
//1 1 2 3 4 4
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
LinkList AddList(LinkList L1, LinkList L2);//�ϲ�
void PrintList(LinkList L);

int main(void) {
	LinkList head1 = CreatList();
	LinkList head2 = CreatList();
	LinkList L = AddList(head1, head2);
	PrintList(L);
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

LinkList AddList(LinkList L1, LinkList L2) {
	LinkList q;
	q = L2->next;
	while (q)
	{
		int a = 1;
		LinkList p = L1;
		LinkList r=new LNode;
		while (q->val >= p->next->val) {
			LinkList s=new LNode;
			if (p->next->next == NULL) {
				p->next->next=q;
				a = 0;
				break;
			}
			else p = p->next;
		}
		if (a != 0) {
			r->val = q->val;
			r->next = p->next;
			p->next = r;
			q = q->next;
		}
		else break;
	}
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