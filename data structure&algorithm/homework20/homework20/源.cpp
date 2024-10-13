//10: 找出游戏的获胜者
//共有 n 名小伙伴一起做游戏。小伙伴们围成一圈，按 顺时针顺序 从 1 到 n 编号。确切地说，从第 i 名小伙伴顺时针移动一位会到达第(i + 1) 名小伙伴的位置，其中 1 <= i < n ，从第 n 名小伙伴顺时针移动一位会回到第 1 名小伙伴的位置。
//	游戏遵循如下规则：
//	从第 1 名小伙伴所在位置 开始 。
//	沿着顺时针方向数 k 名小伙伴，计数时需要 包含 起始时的那位小伙伴。逐个绕圈进行计数，一些小伙伴可能会被数过不止一次。
//	你数到的最后一名小伙伴需要离开圈子，并视作输掉游戏。
//	如果圈子中仍然有不止一名小伙伴，从刚刚输掉的小伙伴的 顺时针下一位 小伙伴 开始，回到步骤 2 继续执行
//	否则，圈子中最后一名小伙伴赢得游戏。
//	给你参与游戏的小伙伴总数 n ，和一个整数 k ，返回游戏的获胜者。
//	输入为两个整数，n和k(1≤k≤n≤500)
//	输出游戏的获胜者
//	输入输出样例
//	输入
//	5 2
//	输出
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