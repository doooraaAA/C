//6: 二叉排序树
//描述
//试写一个判别给定二叉树是否为二叉排序树的算法
//输入
//第 1 行为一个正整数 N表示树有N个点
//第 2 ~N + 1行 在第i行有三个数Li, Ri, Vi，分别表示第i - 1个点的左儿子下标，右儿子下标和值。如果第i - 1个点左儿子不存在则Li = 0，右儿子同理。数据保证Vi互不相同且输入的为一颗合法树。
//输出
//第1行，如果树为合法二叉排序树输出YES，否则输出NO；
//第2行，如果树为合法二叉排序树输出N个数，用空格分隔，表示所有点从小到大排序后的数组。如果树不为合法二叉树则输出一个空行。
//输入
//4
//2 3 5
//0 4 3
//0 0 7
//0 0 4
//输出
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

    int prev = INT_MIN; // 用于保存上一个遍历到的节点的值
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