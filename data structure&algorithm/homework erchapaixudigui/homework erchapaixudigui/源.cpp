//7: �����������ݹ�
//��֪�������������ö�������洢�ṹ��������ָ��Ϊ T, �����ĽṹΪ(lchild, data�� rchild), ����lchild��rchild�ֱ�ָ��ý�����Һ��ӵ�ָ�룬data���Ž������� ��Ϣ����д���ݹ��㷨����С���������������������������ֵ >= x�Ľ������ݡ�
//����
//�� 1 ��Ϊһ�������� N��x��ʾ����N���㣬xΪ��ѯֵ
//�� 2 ~N + 1�� �ڵ�i����������Li, Ri, Vi���ֱ��ʾ��i - 1�����������±꣬�Ҷ����±��ֵ�������i - 1��������Ӳ�������Li = 0���Ҷ���ͬ�����ݱ�֤Vi������ͬ�������Ϊһ�źϷ�������������
//���
//1�У���С����������� >= x�������ÿո�ָ�
//����
//4 5
//2 3 5
//0 4 3
//0 0 7
//0 0 4
//���
//5 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void inorderTraversal(struct TreeNode* root, int x) {
    if (root != NULL) {
        inorderTraversal(root->left, x);
        if (root->val >= x) {
            printf("%d ", root->val);
        }
        inorderTraversal(root->right, x);
    }
}

int main() {
    int N, x;
    scanf("%d %d", &N, &x);

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

    inorderTraversal(nodes[1], x);

    for (int i = 0; i <= N; i++) {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}