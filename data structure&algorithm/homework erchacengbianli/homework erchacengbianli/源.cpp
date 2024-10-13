//6: 二叉树的层次遍历
//现在给出一棵二叉树，希望你输出它的层次遍历
//输入
//第一行一个正整数 nn，表示给定的树的节点的数目，规定节点编号 1∼nn，其中节点 1是树根。
//接下来 nn 行，每行两个正整数分别表示节点 ii 的左右孩子的编号。如果不存在左 / 右孩子，则以 −1 表示。两个数之间用一个空格隔开。
//输出
//输出对应二叉树的层次遍历，对于同一层节点按照从左到右的顺序输出
//输入
//3
//2 3
//- 1 - 1
//- 1 - 1
//输出
//1 2 3
//提示
//其中，n \le 100n≤100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的节点结构
struct TreeNode {
    int val;  // 节点值
    struct TreeNode* left;  // 左子节点指针
    struct TreeNode* right;  // 右子节点指针
};

// 创建二叉树
struct TreeNode* createTree(int* leftChild, int* rightChild, int n) {
    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    for (int i = 0; i < n; i++) {
        nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        nodes[i]->val = i + 1;
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    for (int i = 0; i < n; i++) {
        int left = leftChild[i];
        int right = rightChild[i];

        if (left != -1) {
            nodes[i]->left = nodes[left - 1];
        }

        if (right != -1) {
            nodes[i]->right = nodes[right - 1];
        }
    }

    return nodes[0];
}

// 层次遍历二叉树
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));  // 使用队列存储节点
    int front = -1;  // 队列前指针
    int rear = -1;  // 队列后指针

    // 根节点入队
    queue[++rear] = root;

    while (front != rear) {
        struct TreeNode* current = queue[++front];  // 队首节点出队

        printf("%d ", current->val);  // 输出当前节点的值

        // 左子节点入队
        if (current->left != NULL) {
            queue[++rear] = current->left;
        }

        // 右子节点入队
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }

    free(queue);
}

int main() {
    // 读取输入
    int n;
    scanf("%d", &n);

    int* leftChild = (int*)malloc(n * sizeof(int));
    int* rightChild = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &leftChild[i], &rightChild[i]);
    }

    // 创建二叉树
    struct TreeNode* root = createTree(leftChild, rightChild, n);

    // 层次遍历二叉树并输出结果
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}