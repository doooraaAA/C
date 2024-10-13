//���ڸ���һ�ö�������ϣ������������������
//����
//��һ��һ�������� n����ʾ���������Ľڵ����Ŀ���涨�ڵ��� 1?n�����нڵ� 1��������
//������ n �У�ÿ������������ li, ri ? ���ֱ��ʾ�ڵ� i �����Һ��ӵı�š������������ / �Һ��ӣ����� ?1 ��ʾ��������֮����һ���ո������
//���
//�����Ӧ���������������
//����
//3
//2 3
//- 1 - 1
//- 1 - 1
//���
//2 1 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

// ����������Ľڵ�ṹ
struct TreeNode {
    int val;  // �ڵ�ֵ
    struct TreeNode* left;  // ���ӽڵ�ָ��
    struct TreeNode* right;  // ���ӽڵ�ָ��
};

// �����������
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);  // ����������
    printf("%d ", root->val);  // ����ڵ�ֵ
    inorderTraversal(root->right);  // ����������
}

int main() {
    // ��ȡ����
    int n;
    scanf("%d", &n);

    struct TreeNode* nodes[200];
    for (int i = 0; i < n; i++) {
        nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));  // ��̬����ڵ��ڴ�
        nodes[i]->val = i + 1;  // �ڵ��ֵΪ�ڵ���
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    for (int i = 0; i < n; i++) {
        int left, right;
        scanf("%d %d", &left, &right);

        if (left != -1) {
            nodes[i]->left = nodes[left - 1];  // �������ӽڵ�ָ��
        }

        if (right != -1) {
            nodes[i]->right = nodes[right - 1];  // �������ӽڵ�ָ��
        }
    }

    struct TreeNode* root = nodes[0];  // ���ڵ�

    // �������������
    inorderTraversal(root);

    return 0;
}