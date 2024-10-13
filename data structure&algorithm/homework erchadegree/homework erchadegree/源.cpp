﻿//2: 二叉树的最大深度
//现在给出一棵二叉树，希望你输出二叉树的深度
//输入
//第一行一个正整数 n，表示给定的树的节点的数目，规定节点编号 1∼n，其中节点 1是树根。
//接下来 n 行，每行两个正整数 li, ri ​ ，分别表示节点 i 的左右孩子的编号。如果不存在左 / 右孩子，则以 −1 表示。两个数之间用一个空格隔开。
//输出
//输出对应二叉树的深度
//输入
//3
//2 3
//- 1 - 1
//- 1 - 1
//输出
//2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

// 定义二叉树的节点结构
struct TreeNode {
    int val;  // 节点值
    struct TreeNode* left;  // 左子节点指针
    struct TreeNode* right;  // 右子节点指针
};

// 计算二叉树的最大深度
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);  // 左子树的深度
    int rightDepth = maxDepth(root->right);  // 右子树的深度

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;  // 返回较大的子树深度加1
}

int main() {
    // 读取输入
    int n;
    scanf("%d", &n);

    struct TreeNode* nodes[300];
    for (int i = 0; i < n; i++) {
        nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));  // 动态分配节点内存
        nodes[i]->val = i + 1;  // 节点的值为节点编号
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    for (int i = 0; i < n; i++) {
        int left, right;
        scanf("%d %d", &left, &right);

        if (left != -1) {
            nodes[i]->left = nodes[left - 1];  // 设置左子节点指针
        }

        if (right != -1) {
            nodes[i]->right = nodes[right - 1];  // 设置右子节点指针
        }
    }

    struct TreeNode* root = nodes[0];  // 根节点

    // 计算二叉树的最大深度
    int depth = maxDepth(root);

    printf("%d\n", depth);

    return 0;

}