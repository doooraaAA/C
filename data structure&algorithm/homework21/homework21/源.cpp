//1: 数组与串 - 小鱼的数字游戏
//题目描述
//小鱼最近被要求参加一个数字游戏，要求它把看到的一串数字 a_i（长度不一定，以 00 结束），记住了然后反着念出来（表示结束的数字 00 就不要念出来了）。这对小鱼的那点记忆力来说实在是太难了，你也不想想小鱼的整个脑袋才多大，其中一部分还是好吃的肉！所以请你帮小鱼编程解决这个问题。
//题目难度 简单
//输入描述
//一行内输入一串整数，以 00 结束，以空格间隔。
//输出描述
//一行内倒着输出这一串整数，以空格间隔。
//输入输出样例
//输入
//3 65 23 5 34 1 30 0
//输出
//30 1 34 5 23 65 3
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
int main() {
	int a[10000] = {0};
	int i = 0;
	while (1) {
		scanf("%d", &a[i]);
		if (a[i] == 00) break;
		i++;
	}
	i = i - 1;
	while (i>-1) {
		printf("%d ", a[i]);
		i--;
	}
	return 0;
}