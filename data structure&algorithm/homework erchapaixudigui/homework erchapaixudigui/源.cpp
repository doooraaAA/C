//7: 二叉排序树递归
//巳知二叉排序树采用二叉链表存储结构，根结点的指针为 T, 链结点的结构为(lchild, data， rchild), 其中lchild、rchild分别指向该结点左、右孩子的指针，data域存放结点的数据 信息。请写出递归算法，从小到大输出二叉排序树中所有数据值 >= x的结点的数据。
//输入
//第 1 行为一个正整数 N和x表示树有N个点，x为查询值
//第 2 ~N + 1行 在第i行有三个数Li, Ri, Vi，分别表示第i - 1个点的左儿子下标，右儿子下标和值。如果第i - 1个点左儿子不存在则Li = 0，右儿子同理。数据保证Vi互不相同且输入的为一颗合法二叉排序树。
//输出
//1行，从小到大输出所有 >= x的数，用空格分隔
//输入
//4 5
//2 3 5
//0 4 3
//0 0 7
//0 0 4
//输出
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