//9: ��������
//����һ�������� L ��ͷ�ڵ� head �������� L ��ʾΪ��
//L0 �� L1 �� �� �� Ln - 1 �� Ln
//�뽫���������к��Ϊ��
//L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
//����ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
//��������ĳ��ȷ�ΧΪ[1, 5 * 10 ^ 4]
//1 <= node.val <= 1000
//- 1��ʾ���������
//�����������
//��������
//1 2 3 4 5 - 1
//�������
//1 5 2 4 3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"ctype.h"
#include<math.h>
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //��β�巨������ͷ���ĵ�����
LinkList SwitchList(LinkList L);//ɾ�����ֽڵ�
void PrintList(LinkList L);

int main(void) {
	LinkList head = CreatList();
 	SwitchList(head);
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
LinkList SwitchList(LinkList L) {
	int len = 0;
	LinkList p = L;
	while (p->next) {
		len++;
		p = p->next;//һ��len���ڵ�
	}
	int b = floor((len-1)/ 2);
	p = L->next;
	while(b){
		LinkList r = L->next;
		while (r->next->next)
		{
			r = r->next;
		}//rָ�����ڶ���
		r->next->next = p->next;
		p->next = r->next;
		r->next = NULL;
		p = p->next->next;
		b--;//��Զ�������ڶ������뵽p����һ��
	}
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
