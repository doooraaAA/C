//4: ����������ת����
//����һ������������ý�� head��������ÿ������ֵ���� 0 ����1����֪��������һ���������ֵĶ����Ʊ�ʾ��ʽ�����㷵�ظ���������ʾ���ֵ� ʮ����ֵ
//������������Ϊ�ա�����Ľ������������ 30��ÿ������ֵ���� 0 ���� 1��
//- 1��ʾ���������
//���ʮ������
//��������
//1 0 1 - 1
//�������
//5
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"math.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //��ͷ�巨������ͷ���ĵ�����
int Switch(LinkList L);//����ת��

int main(void) {
	LinkList head = CreatList();
	int ans = Switch(head);
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
		p->next = q->next;
		q->next = p;
	}
	return head;
}
int Switch(LinkList L)
{
	int ans = 0;
	int i = 0;
	LinkList p = L->next;
	while (p) {
		int e = p->val;
		ans = e * pow(2, i)+ans;
		p = p->next;
		i = i + 1;
	}
	return ans;
}