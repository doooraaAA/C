//1: ��������
//�����ġ�ָ������������ͬ���ַ����У��硰abcdcba���͡�abba�����ǻ��ģ�ʹ��ջ�������ݽṹ�жϸ����ַ������Ƿ�Ϊ���ģ�Ҫ��ʹ����ջʵ�֡�
//����
//һ���ַ����У��ַ����г��ȡ�1000
//���
//���Ϊtrue / false���ֱ��ʾ������ַ������Ƿ�Ϊ����
//����
//����  abcda
//���  false
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include "math.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);//��������
int CompareList(LinkList L);//�ӳ�������

int main(void) {
	LinkList head = CreatList();
	int Ans = CompareList(head);
	if (Ans == 0) {
		printf("false");
	}
	else printf("true");
}

LinkList CreatList(void) {
	LinkList head = new LNode;
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	char e;
	while (1) {
		e = getchar();
		if (e == '\n') break;//�жϽ���
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return head;
}
int CompareList(LinkList L) {
	int n = 0;
	int ans = 1;
	LinkList p = L;
	while (p->next) {
		n++;
		p = p->next;//һ��n���ڵ�
	}
	int b = floor(n / 2);
	p = L->next;
	while (b) {
		LinkList r = L->next;
		while (r->next->next)
		{
			r = r->next;
		}//rָ�����ڶ���
		if (r->next->val != p->val) {
			ans = 0;
		}
		r->next = NULL;
		p = p->next;
		b--;
	}
	return ans;
}