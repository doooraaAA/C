//3: �����봮 - �������
//��Ŀ����
//���� n(n��20)�����������ǵ�ǰ n �С�
//����㲻֪��ʲô��������ǣ����Թ۲��������ҹ��ɡ�
//
//��������
//����һ�����ֽ���
//
//�������
//����������
//
//�����������
//���� : 6
//��� :
//	1
//	1 1
//	1 2 1
//	1 3 3 1
//	1 4 6 4 1
//	1 5 10 10 5 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
int main() {
	int n = 0;
	scanf("%d", &n);
	int a[1000] = { 1 };
	a[1] = 1;
	int b[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
		printf("1 ");
		if (i == 0) printf("\n");
		for (int j = 1; j < i; j++)
		{
			b[j] = a[j - 1] + a[j];
			printf("%d ", b[j]);
		}
		for (int j = 1; j < i; j++) {
			a[j] = b[j];
		}
		if (i >= 1)printf("1\n");
	}
}