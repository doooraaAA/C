//1: �ϲ�������������
//����
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//����
//��������˳���l1��l2��l1��l2�����ǵݼ�˳�����У���������Ľڵ���Ŀ��Χ��[0, 50]�� - 100 <= Node.val <= 100
//- 1��ʾ���������
//���
//����ϲ����˳���
//��������
//
//1 2 4 - 1
//1 3 4 - 1
//�������
//
//1 1 2 3 4 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main() {
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next = NULL;
    struct ListNode* p = l1;
    int val;
    while (scanf("%d", &val) != EOF && val != -1) {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = val;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }

    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next = NULL;
    p = l2;
    while (scanf("%d", &val) != EOF && val != -1) {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = val;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }

    struct ListNode* mergedList = mergeTwoLists(l1->next, l2->next);
    for (p = mergedList; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }

    return 0;
}