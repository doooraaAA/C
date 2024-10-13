//3: 点击消除
//给定一个字符串，每次“点击”，可以把字符串中相邻两个相同字母消除，例如，字符串"abbc"点击后可以生成"ac"。但相同而不相邻、不相同的相邻字母都是不可以被消除的。
//通过点击足够多次之后可以把字符串变得尽可能短，编程实现输出给定字符串足够多次点击后的最终形态。
//输入
//一个字符串，仅由小写字母组成。（字符串长度不大于10000）
//输出
//一个字符串，为“点击消除”后的最终形态。若最终的字符串为空串，则输出0。
//输入 abbc
//输出 ac
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include<iostream>
typedef struct LNode {
	char e;
	struct LNode* next;
}LNode,*LinkList;

LinkList CreatList(void);//创建链表
LinkList CompareList(LinkList L);//比较相同并删除
void PrintList(LinkList L);//打印链表

int main(void) {
	LinkList head = CreatList();
	CompareList(head);
	if (head->next == NULL) printf("0");
	else PrintList(head);
	return 0;
}

LinkList CreatList(void) {
	LinkList head = new LNode;
	head->next = NULL;
	LinkList p = head;
	char e ;
	while (true)
	{LinkList q = new LNode;
		e = getchar();
		if (e == '\n') break;
		q->e = e;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return head;
}

LinkList CompareList(LinkList L) {
	LinkList p = L;
	int a = 1;
	while (p->next->next) {
		if (p->next->next->e == p->next->e) {
			p->next = p->next->next->next;
			a = 0;
		}
		else p = p->next;
		if (p->next == NULL) break;
	}
	if (a == 0&&p->next!=NULL) {
		CompareList(L);
	}
	return L;
}

void PrintList(LinkList L) {
	LinkList p = L->next;
	while (p) {
		printf("%c", p->e);
		p = p->next;
	}
}