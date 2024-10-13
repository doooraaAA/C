//3: 查找
//输入 n(n≤106) 个不超过 109的单调不减的（就是后面的数字不小于前面的数字）非负整数 a1, a2, …, an ，然后进行 m(m≤105) 次询问。对于每次询问，给出一个整数 q(q≤109)，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出 - 1 。
//输入
//第一行 2 个整数 n 和 m，表示数字个数和询问次数。
//第二行 n 个整数，表示这些待查询的数字。
//第三行 m 个整数，表示询问这些数字的编号，从 1 开始编号。
//输出
//m 个整数表示答案。
//输入
//11 3
//1 3 3 3 5 7 9 11 13 15 15
//1 3 6
//输出
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

LinkList CreatList(int n);            //用尾插法建立带头结点的单链表
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