//10: �ҳ���Ϸ�Ļ�ʤ��
//���� n ��С���һ������Ϸ��С�����Χ��һȦ���� ˳ʱ��˳�� �� 1 �� n ��š�ȷ�е�˵���ӵ� i ��С���˳ʱ���ƶ�һλ�ᵽ���(i + 1) ��С����λ�ã����� 1 <= i < n ���ӵ� n ��С���˳ʱ���ƶ�һλ��ص��� 1 ��С����λ�á�
//	��Ϸ��ѭ���¹���
//	�ӵ� 1 ��С�������λ�� ��ʼ ��
//	����˳ʱ�뷽���� k ��С��飬����ʱ��Ҫ ���� ��ʼʱ����λС��顣�����Ȧ���м�����һЩС�����ܻᱻ������ֹһ�Ρ�
//	�����������һ��С�����Ҫ�뿪Ȧ�ӣ������������Ϸ��
//	���Ȧ������Ȼ�в�ֹһ��С��飬�Ӹո������С���� ˳ʱ����һλ С��� ��ʼ���ص����� 2 ����ִ��
//	����Ȧ�������һ��С���Ӯ����Ϸ��
//	���������Ϸ��С������� n ����һ������ k ��������Ϸ�Ļ�ʤ�ߡ�
//	����Ϊ����������n��k(1��k��n��500)
//	�����Ϸ�Ļ�ʤ��
//	�����������
//	����
//	5 2
//	���
//	3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include "malloc.h"
#include<string.h>
typedef struct Lnode {
	int val;
	struct Lnode * next;
}Lnode ,*linklist;

linklist Createlist(int n) {
	linklist head = new Lnode;
	head->next = NULL;
	linklist r = new Lnode;
	r = head;
	for (int i = 1; i <= n; i++)
	{
		linklist p = new Lnode;
		p->next = head->next;
		p->val = i;
		r->next = p;
		r = p;
	}
	return head;
}
void CountList(linklist L, int k) {
	linklist p = new Lnode;
	p = L->next;
	int a = k;
	if (L->next != L) {
		while (k - 2) {
			k--;
			p = p->next;
		}
		p->next = p->next->next;
		CountList(p, a);
	}
	else printf("%d", p->val);
}
int main() {
	int n=0, k = 0;
	scanf("%d %d", &n, &k);
	linklist head = Createlist(n);
	CountList(head, k);
	return 0;
}