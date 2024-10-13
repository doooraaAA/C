//1: 普通二叉树
//您需要写一种数据结构，来维护一些数（都是 1e9 以内的数字）的集合，最开始时集合是空的。其中需要提供以下操作，操作次数 q 不超过 104：
//查询值为x的数的排名（排名定义为比当前数小的数的个数 + 1。若有多个相同的数，应输出最小的排名）。
//查询排名为 x 的数。
//求 x 的前驱（前驱定义为小于 x，且最大的数）。若未找到则输出−2147483647。
//求 x 的后继（后继定义为大于 x，且最小的数）。若未找到则输出 2147483647。
//插入一个数 x。
//输入
//第一行是一个整数 q，表示操作次数。//接下来 q 行，每行两个整数 op, x，分别表示操作序号以及操作的参数 x。
//输出
//输出有若干行。对于操作 1, 2, 3, 4输出一个整数，表示该操作的结果。
//样例
//输入
//7
//5 1
//5 3
//5 5
//1 3
//2 2
//3 3
//4 3
//输出
//2
//3
//1
//5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 节点的结构体定义
typedef struct TreeNode {
    int val;
    int size;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新的树节点
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->size = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 获取节点的大小（包括左右子树的节点数）
int getSize(TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->size;
}

// 更新节点的大小
void updateSize(TreeNode* node) {
    if (node == NULL)
        return;
    node->size = getSize(node->left) + getSize(node->right) + 1;
}

// 左旋操作
TreeNode* rotateLeft(TreeNode* node) {
    TreeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    updateSize(node);
    updateSize(newRoot);

    return newRoot;
}

// 右旋操作
TreeNode* rotateRight(TreeNode* node) {
    TreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateSize(node);
    updateSize(newRoot);

    return newRoot;
}

// 插入节点
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val) {
        root->left = insert(root->left, val);
        if (getSize(root->left->left) > getSize(root->right)) {
            root = rotateRight(root);
        }
    }
    else {
        root->right = insert(root->right, val);
        if (getSize(root->right->right) > getSize(root->left)) {
            root = rotateLeft(root);
        }
    }

    updateSize(root);
    return root;
}

// 删除节点
// 删除节点
TreeNode* removeNode(TreeNode* root, int val) {
    if (root == NULL)
        return NULL;

    if (val < root->val) {
        root->left = removeNode(root->left, val);
        updateSize(root);
    }
    else if (val > root->val) {
        root->right = removeNode(root->right, val);
        updateSize(root);
    }
    else {
        if (root->left == NULL) {
            TreeNode* newRoot = root->right;
            free(root);
            return newRoot;
        }
        else if (root->right == NULL) {
            TreeNode* newRoot = root->left;
            free(root);
            return newRoot;
        }
        else {
            // 用后继节点替换被删除节点，并递归删除后继节点
            TreeNode* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = removeNode(root->right, successor->val);
            updateSize(root);
        }
    }

    return root;
}

// 查询值为x的数的排名
int getRank(TreeNode* root, int x) {
    int rank = 0;
    while (root != NULL) {
        if (x < root->val) {
            root = root->left;
        }
        else if (x > root->val) {
            rank += getSize(root->left) + 1;
            root = root->right;
        }
        else {
            rank += getSize(root->left) + 1;
            break;
        }
    }
    return rank;
}

// 查询排名为x的数
int getValue(TreeNode* root, int x) {
    while (root != NULL) {
        int leftSize = getSize(root->left);
        if (x <= leftSize) {
            root = root->left;
        }
        else if (x == leftSize + 1) {
            return root->val;
        }
        else {
            x -= (leftSize + 1);
            root = root->right;
        }
    }
    return -1; // not found
}

// 求x的前驱
int getPredecessor(TreeNode* root, int x) {
    int predecessor = -2147483647;
    while (root != NULL) {
        if (x > root->val) {
            predecessor = root->val;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return predecessor;
}

// 求x的后继
int getSuccessor(TreeNode* root, int x) {
    int successor = 2147483647;
    while (root != NULL) {
        if (x < root->val) {
            successor = root->val;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return successor;
}

int main() {
    int q;
    scanf("%d", &q);

    TreeNode* root = NULL;

    for (int i = 0; i < q; i++) {
        int op, x;
        scanf("%d%d", &op, &x);

        if (op == 1) {
            int rank = getRank(root, x);
            printf("%d\n", rank);
        }
        else if (op == 2) {
            int value = getValue(root, x);
            printf("%d\n", value);
        }
        else if (op == 3) {
            int predecessor = getPredecessor(root, x);
            printf("%d\n", predecessor);
        }
        else if (op == 4) {
            int successor = getSuccessor(root, x);
            printf("%d\n", successor);
        }
        else if (op == 5) {
            root = insert(root, x);
        }
        else {
            // 操作无效
        }
    }

    // 释放内存
    // 略（可选）

    return 0;
}