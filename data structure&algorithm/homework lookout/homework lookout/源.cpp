//3: ����
//���� n(n��106) �������� 109�ĵ��������ģ����Ǻ�������ֲ�С��ǰ������֣��Ǹ����� a1, a2, ��, an ��Ȼ����� m(m��105) ��ѯ�ʡ�����ÿ��ѯ�ʣ�����һ������ q(q��109)��Ҫ�������������������е�һ�γ��ֵı�ţ����û���ҵ��Ļ���� - 1 ��
//����
//��һ�� 2 ������ n �� m����ʾ���ָ�����ѯ�ʴ�����
//�ڶ��� n ����������ʾ��Щ����ѯ�����֡�
//������ m ����������ʾѯ����Щ���ֵı�ţ��� 1 ��ʼ��š�
//���
//m ��������ʾ�𰸡�
//����
//11 3
//1 3 3 3 5 7 9 11 13 15 15
//1 3 6
//���
//1 2 - 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(int n);            //��β�巨������ͷ���ĵ�����
int Lookout(LinkList L,int e);
int main(void) {
	int n,m;
	scanf("%d %d", &n,&m);
	LinkList head = CreatList(n);
	while (m)
	{
		m--;
		int e = 0;
		scanf("%d", &e);
		int ans = Lookout(head, e);
		printf("%d ", ans);
	}
	return 0;
}

LinkList CreatList(int n) {
	LinkList head = new LNode;
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	int e;
	while (n) {
		scanf("%d", &e);
		n--;
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return head;
}
int Lookout(LinkList L,int e) {
	LinkList p = L->next;
	int count=0, ans = -1;
	while (p)
	{
		count++;
		if (e == p->val) {
			ans = count;
			break;
		}
		p = p->next;
	}
	return ans;
}