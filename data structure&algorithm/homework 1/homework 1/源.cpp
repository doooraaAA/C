//����
//����һ�������ͷ�ڵ� head ��һ������val ������ɾ���������������� Node.val == val �Ľڵ㣬�������µ�ͷ�ڵ�
//����
//���������val���б��еĽڵ���Ŀ�ڷ�Χ [0, 10^4] �ڣ�1 <= Node.val <= 50��0 <= val <= 50
//-1��ʾ���������
//���
//����Ƴ�Ԫ�ص�����
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //��β�巨������ͷ���ĵ�����
LinkList DeleteList(LinkList L, int val);    //ɾ��ָ��ֵ�Ľ��,������
void Printlist(LinkList L);//��ӡ���

int main() {
	LinkList head = CreatList();
	int val;
	scanf("%d", &val);
	DeleteList(head, val);
	Printlist(head);
}

LinkList CreatList(void) {
	LinkList head = (LinkList)malloc(sizeof(LNode));
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	int e;
	while (1) {
		scanf("%d", &e);
		if (e < 0 || e > 50) {
			break;//�ж������Ƿ�Ϸ������Ϸ��򲻷�������
		}
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;;
	}
	return head;
}

LinkList DeleteList(LinkList L, int val) {
	if (L->next == NULL) {
		return 0;//����Ϊ��
	}
	LinkList p = L;
	LinkList q;
	while (p->next) {
		q = new LNode;
		if (p->next->val == val) {
			q = p->next;
			p->next = q->next;
			delete q;//ָ�����¸��ڵ㲢�ͷ���ʱ������
		}//�����ɾ��
		else { p = p->next; }
	}
	return L;
}
void Printlist(LinkList L) {
	LinkList p;
	p = L->next;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
}