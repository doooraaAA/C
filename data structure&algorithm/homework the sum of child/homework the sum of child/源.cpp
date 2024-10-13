//4: 二叉树的子树和
//现在给出一棵二叉树，每个结点有一个权值，希望你依次输出每一个节点为根的子树的子树权值和
///输入
//第一行一个正整数 n，表示给定的树的节点的数目，规定节点编号 1∼n，其中节点 1是树根。
//第二行 n 个正整数，用一个空格分隔，第 i 个正整数vi，代表节点 i 的权值。
//接下来 n 行，每行两个正整数 li, ri ​ ，分别表示节点 i 的左右孩子的编号。如果不存在左 / 右孩子，则以 −1 表示。两个数之间用一个空格隔开。
//输出
//一行，n个数，分别表示i号结点为根的子树的子树权值和
//输入
//3
//1 1000 1000
//2 3
//- 1 - 1
//- 1 - 1
//输出
//2001 1000 1000
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

// 定义二叉树的节点结构
struct TreeNode {
    int val;  // 节点值
    struct TreeNode* left;  // 左子节点指针
    struct TreeNode* right;  // 右子节点指针
};

// 计算二叉树的子树权值和
int subtreeSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = subtreeSum(root->left);  // 左子树的权值和
    int rightSum = subtreeSum(root->right);  // 右子树的权值和

    return leftSum + rightSum + root->val;  // 返回左右子树权值和加上当前节点值
}

int main() {
    // 读取输入
    int n;
    scanf("%d", &n);

    struct TreeNode* nodes[300];
    for (int i = 0; i < n; i++) {
        nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));  // 动态分配节点内存
        scanf("%d", &(nodes[i]->val));
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

    // 计算每一个结点为根的子树权值和
    for (int i = 0; i < n; i++) {
        int sum = subtreeSum(nodes[i]);
        printf("%d ", sum);
    }
    printf("\n");

    return 0;
}