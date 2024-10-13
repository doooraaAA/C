//3: 隔层层序遍历
//描述
//给出题目所给的二叉树的隔层层序遍历
//
//输入
//第一行输入一个正整数nn，代表二叉树的节点数目，节点编号为11\sim∼nn，其中节点11是树根。第二行输入二叉数从上到下，从左到右的节点值，若不存在，则以 - 1−1表示。#表示输入结束。
//
//输出
//输出对应二叉树的隔层层序遍历，即当节点所在层为奇数层时，输出节点。同一层节点按照从左到右的顺序输出
//输入
//5
//1 2 3 - 1 - 1 4 5 #
//输出
//1 4 5
//提示
//其中，n≤100
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include "malloc.h"
#include"math.h"
int main() {
	int n;
	scanf("%d", &n);
	int a[110];
	int i = 0;
	char b;
	while (1)
	{
		b=getchar();
		if (b == '#') break;
		scanf("%d", &a[i]);
		i++;//i为数组元素个数比数组编号+1
	}
	for (int j = 0; pow(2,j)< i-1; j++)
	{
		if (j%2 == 0) {
			for (int m = pow(2, j); m < pow(2, j+1)&&m<=i-1; m++)
			{
				if (a[m-1] != -1) {
					printf("%d ", a[m-1]);
				}
			}
		}
	}

	return 0;
}