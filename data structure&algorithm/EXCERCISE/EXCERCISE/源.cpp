//4: 模长最小的k个二维向量
//描述
//已知两个升序顺序表（元素均为整数），list1list1和list2list2，及一个整数mm。
//定义二维向量（x, y）（x, y），xx从list1list1中选择，yy从list2list2中选择。
//试求解模长最小的mm个二维向量，(x1,y1)...(xm,ym)
//	规定：当二维向量模长相等时，取xx值更小的向量。如m = 1m = 1，模长最小二维向量为[1, 2], [2, 1][1, 2], [2, 1]，取[1, 2][1, 2]
//
//	样例1
//输入
//
//list1 = [1, 2, 3], list2 = [1, 2, 3], m = 2
//输出
//
//[1, 1], [1, 2]
//样例2
//输入
//
//list1 = [1, 2, 3], list2 = [1, 2, 3], m = 9
//输出
//
//[1, 1], [1, 2], [2, 1], [2, 2], [1, 3], [3, 1], [2, 3], [3, 2], [3, 3]
//提示
//元素可为负数，如list1 = [-1, 1, 20]list1 = [−1, 1, 20]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"math.h"
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// 交换元素
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main() {
	printf("list1=[");
	int a[200];
	char b;
	int i = 0;
	while (1)
	{
		b = getchar();
		if (b == ']') break;
		a[i] = b;
		i++;//i为数组元素个数比数组编号+1,包含】
	}
	
	printf("list2=[");
	int c[200];
	char d;
	int j = 0;
	while (1)
	{
		d = getchar();
		if (d == ']') break;
		c[j] = d;
		j++;//i为数组元素个数比数组编号+1,包含】
	}
	int m;
	printf("m=");
	scanf("%d", &m);
	int ans[200][200];
	int temp[200];
	int count = 0;
	for (int n = 0; n <i-1 ; n++)
	{
		for (int s = 0;s < j - 1; s++)
		{
			int p = a[n];int q = c[s];
			ans[n][s] = sqrt(pow(p, 2) +pow(q, 2));
			temp[count] = ans[n][s];
			count++;
		}
	}
	bubbleSort(temp, (i-1)*(j-1));
	count = 0;
	int hint = 0;
	while (hint < m)
	{
		for (int n = 0; n < i - 1; n++)
		{
			for (int s = 0; s < j - 1; s++)
			{
				while (count<m)
				{
					if (ans[n][s] == temp[count]) {
						printf("[%d,%d],", a[n], c[s]);
						hint++;
					}
					count++;
				}

			}

		}
	}
		return 0;
	
}