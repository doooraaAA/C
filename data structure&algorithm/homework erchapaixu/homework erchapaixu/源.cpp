//6: ����������
//����
//��дһ���б�����������Ƿ�Ϊ�������������㷨
//����
//�� 1 ��Ϊһ�������� N��ʾ����N����
//�� 2 ~N + 1�� �ڵ�i����������Li, Ri, Vi���ֱ��ʾ��i - 1�����������±꣬�Ҷ����±��ֵ�������i - 1��������Ӳ�������Li = 0���Ҷ���ͬ�����ݱ�֤Vi������ͬ�������Ϊһ�źϷ�����
//���
//��1�У������Ϊ�Ϸ��������������YES���������NO��
//��2�У������Ϊ�Ϸ��������������N�������ÿո�ָ�����ʾ���е��С�������������顣�������Ϊ�Ϸ������������һ�����С�
//����
//4
//2 3 5
//0 4 3
//0 0 7
//0 0 4
//���
//YES
//3 4 5 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <climits>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int checkBST(struct TreeNode* root, int* prev) {
    if (root == NULL) {
        return 1;
    }

    if (!checkBST(root->left, prev)) {
        return 0;
    }

    if (root->val <= *prev) {
        return 0;
    }

    *prev = root->val;

    return checkBST(root->right, prev);
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    struct TreeNode** nodes = (struct TreeNode**)malloc((N + 1) * sizeof(struct TreeNode*));
    for (int i = 0; i <= N; i++) {
        nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    int Li, Ri, Vi;

    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &Li, &Ri, &Vi);

        nodes[i]->val = Vi;

        if (Li != 0) {
            nodes[i]->left = nodes[Li];
        }

        if (Ri != 0) {
            nodes[i]->right = nodes[Ri];
        }
    }

    int prev = INT_MIN; // ���ڱ�����һ���������Ľڵ��ֵ
    if (checkBST(nodes[1], &prev)) {
        printf("YES\n");
        inorderTraversal(nodes[1]);
        printf("\n");
    }
    else {
        printf("NO\n");
    }

    for (int i = 0; i <= N; i++) {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}