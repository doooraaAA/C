//3: �������
//����һ���ַ�����ÿ�Ρ�����������԰��ַ���������������ͬ��ĸ���������磬�ַ���"abbc"������������"ac"������ͬ�������ڡ�����ͬ��������ĸ���ǲ����Ա������ġ�
//ͨ������㹻���֮����԰��ַ�����þ����̣ܶ����ʵ����������ַ����㹻��ε�����������̬��
//����
//һ���ַ���������Сд��ĸ��ɡ����ַ������Ȳ�����10000��
//���
//һ���ַ�����Ϊ��������������������̬�������յ��ַ���Ϊ�մ��������0��
//���� abbc
//��� ac
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include<iostream>
typedef struct LNode {
	char e;
	struct LNode* next;
}LNode,*LinkList;

LinkList CreatList(void);//��������
LinkList CompareList(LinkList L);//�Ƚ���ͬ��ɾ��
void PrintList(LinkList L);//��ӡ����

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