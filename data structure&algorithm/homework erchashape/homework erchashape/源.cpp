//5: 确定树的形态
//现在给出一棵二叉树的前序遍历和后序遍历，输出树的后序遍历
//输入
//第一行一个正整数 n，表示给定的树的节点的数目，规定节点编号 1∼n，其中节点 1是树根。
//第二行 n 个正整数，用一个空格分隔，代表二叉树的前序遍历
//第三行 n 个正整数，用一个空格分隔，代表二叉树的中序遍历
//输出
//一行，n个数，用一个空格分隔，表示二叉树的后序遍历
//输入
//3
//1 2 3
//2 1 3
//输出
//2 3 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的节点结构
struct TreeNode {
    int val;  // 节点值
    struct TreeNode* left;  // 左子节点指针
    struct TreeNode* right;  // 右子节点指针
};

// 递归构建二叉树
struct TreeNode* buildTree(int* preorder, int* inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd) {
        return NULL;
    }

    // 根节点的值为前序遍历的第一个元素
    int rootVal = preorder[preStart];

    // 在中序遍历中找到根节点的位置
    int rootIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }

    int leftSize = rootIndex - inStart;  // 左子树的节点个数
    int rightSize = inEnd - rootIndex;  // 右子树的节点个数

    // 递归构建左子树和右子树
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
    root->right = buildTree(preorder, inorder, preEnd - rightSize + 1, preEnd, rootIndex + 1, inEnd);

    return root;
}

// 后序遍历二叉树
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);  // 后序遍历左子树
    postorderTraversal(root->right);  // 后序遍历右子树
    printf("%d ", root->val);  // 输出当前节点的值
}

int main() {
    // 读取输入
    int n;
    scanf("%d", &n);

    int* preorder = (int*)malloc(n * sizeof(int));
    int* inorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    // 构建二叉树
    struct TreeNode* root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1);

    // 后序遍历二叉树并输出结果
    postorderTraversal(root);
    printf("\n");

    return 0;
}