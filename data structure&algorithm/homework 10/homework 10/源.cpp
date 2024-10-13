//10: 链表最大孪生和
//在一个大小为 n 且 n 为 偶数 的链表中，对于 0 <= i <= (n / 2) - 1 的 i ，第 i 个节点（下标从 0 开始）的孪生节点为第(n - 1 - i) 个节点 。
//比方说，n = 4 那么节点 0 是节点 3 的孪生节点，节点 1 是节点 2 的孪生节点。这是长度为 n = 4 的链表中所有的孪生节点。
//孪生和定义为一个节点和它孪生节点两者值之和。
//给你一个长度为偶数的链表的头节点 head ，请你返回链表的 最大孪生和 。
//输入链表的节点数目是[2, 10 ^ 5] 中的 偶数 。
//1 <= Node.val <= 10 ^ 5
//- 1是链表结束符
//输出孪生和
//输入样例  5 4 2 1 - 1
//输出样例  6
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);//创建链表
LinkList AddList(LinkList L);//加出孪生和
int Compare(LinkList L);//比较出最大的孪生和

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
		if (e == -1) break;//判断结束
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
		p = p->next;//一共n个节点
	}
	int b = n / 2;
	p = L->next;
	while (b) {
		LinkList r = L->next;
		while (r->next->next)
		{
			r = r->next;
		}//r指向倒数第二个
		LinkList s=new LNode;
		s->val = r->next->val+p->val;
		s->next = NULL;
		q->next = s;
		q = s;
		r->next = NULL;
		p = p->next;
		b--;//永远将倒数第二个插入到p的下一个
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
