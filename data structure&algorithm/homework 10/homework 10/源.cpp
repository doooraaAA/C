//10: �������������
//��һ����СΪ n �� n Ϊ ż�� �������У����� 0 <= i <= (n / 2) - 1 �� i ���� i ���ڵ㣨�±�� 0 ��ʼ���������ڵ�Ϊ��(n - 1 - i) ���ڵ� ��
//�ȷ�˵��n = 4 ��ô�ڵ� 0 �ǽڵ� 3 �������ڵ㣬�ڵ� 1 �ǽڵ� 2 �������ڵ㡣���ǳ���Ϊ n = 4 �����������е������ڵ㡣
//�����Ͷ���Ϊһ���ڵ���������ڵ�����ֵ֮�͡�
//����һ������Ϊż���������ͷ�ڵ� head �����㷵������� ��������� ��
//��������Ľڵ���Ŀ��[2, 10 ^ 5] �е� ż�� ��
//1 <= Node.val <= 10 ^ 5
//- 1�����������
//���������
//��������  5 4 2 1 - 1
//�������  6
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);//��������
LinkList AddList(LinkList L);//�ӳ�������
int Compare(LinkList L);//�Ƚϳ�����������

int main(void) {
	LinkList head = CreatList();
	LinkList Ans=AddList(head);
	int ans=Compare(Ans);
	printf("%d", ans);
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
LinkList AddList(LinkList L) {
	int n = 0;
	LinkList p = L;
	LinkList Ans=new LNode;
	LinkList q = Ans;
	while (p->next) {
		n++;
		p = p->next;//һ��n���ڵ�
	}
	int b = n / 2;
	p = L->next;
	while (b) {
		LinkList r = L->next;
		while (r->next->next)
		{
			r = r->next;
		}//rָ�����ڶ���
		LinkList s=new LNode;
		s->val = r->next->val+p->val;
		s->next = NULL;
		q->next = s;
		q = s;
		r->next = NULL;
		p = p->next;
		b--;//��Զ�������ڶ������뵽p����һ��
	}
	return Ans;
}
int Compare(LinkList L){
	LinkList q;
	int ans = 0;
	q = L->next;
	while (q)
	{
		ans = q->val;
		if (q->next) {
			if (q->val >= q->next->val) {
				q->next = q->next->next;
			}
			else {
				q = q->next;
			}
			ans = q->val;
		}
		else break;
	}
	return ans;
}
