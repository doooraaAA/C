//5: �����봮 - Һ����
//��Ŀ����
//Һ�����ϣ�ÿ�����������ֶ��ǿ�����ʾ�� 3��5 �ĵ���ģ����� X ��ʾ���㣬.��ʾ���㣩�����ڸ�������λ���������� 100����һ�����֣�Ҫ�������Щ��������ʾ���ϵ�Ч�������ֵ���ʾ��ʽ��ͬ���������ע��ÿ������֮�䶼��һ�м����
//��һ������һ�������� n����ʾ���ֵ�λ����
//�ڶ�������һ������Ϊ n ����Ȼ��
//������У���ʾ��ʾ���ϵ����֡�
//��Щͬѧ��Ӧ������������۲�һ�¾�֪����
//ÿ��������һ��3��5�ľ���
//ÿ������֮����һ��1��5��.���
//��������е���ʾ�ַ�ռλ��һ����������ʾ���⡣
//���������һ��ͼƬ�����ҹ۲�
//���룺
//10
//0123456789
//�����
//XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
//X.X...X...X...X.X.X.X...X.....X.X.X.X.X
//X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
//X.X...X.X.....X...X...X.X.X...X.X.X...X
//XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
char *a[10][5];
char str[22];

int main()
{
    char str0[] = "XXX";
    char str1[] = "X.X";
    char str2[] = "..X";
    char str3[] = "X..";
    a[0][0] = str0;
    a[0][1] =str1 ;
    a[0][2] = str1;
    a[0][3] = str1;
    a[0][4] = str0;

    a[1][0] = str2;
    a[1][1] = str2;
    a[1][2] = str2;
    a[1][3] = str2;
    a[1][4] = str2;

    a[2][0] = str0;
    a[2][1] = str2;
    a[2][2] = str0;
    a[2][3] = str3;
    a[2][4] = str0;

    a[3][0] = str0;
    a[3][1] = str2;
    a[3][2] = str0;
    a[3][3] = str2;
    a[3][4] =str0;

    a[4][0] = str1;
    a[4][1] = str1;
    a[4][2] = str0;
    a[4][3] = str2;
    a[4][4] = str2;

    a[5][0] = str0;
    a[5][1] = str3;
    a[5][2] = str0;
    a[5][3] = str2;
    a[5][4] = str0;

    a[6][0] = str0;
    a[6][1] = str3;
    a[6][2] = str0;
    a[6][3] = str1;
    a[6][4] = str0;

    a[7][0] = str0;
    a[7][1] = str2;
    a[7][2] = str2;
    a[7][3] = str2;
    a[7][4] = str2;

    a[8][0] = str0;
    a[8][1] = str1;
    a[8][2] = str0;
    a[8][3] = str1;
    a[8][4] = str0;

    a[9][0] = str0;
    a[9][1] = str1;
    a[9][2] = str0;
    a[9][3] = str2;
    a[9][4] = str0;
    int n;
    scanf("%d", &n);
    for (int i = -1; i < n; i++)
    {
        char b;
        scanf("%c", &b);
        if(i>=0)str[i] = b;
    }
    for (int i = 0; i < 5; i++)//i���Ƶڼ���
    {
        for (int j = 0; j < n; j++) {//j���ƶ���ڼ����ַ�
            if (str[j] == '0')
            {
                printf("%s", a[0][i]);
            }
            if (str[j] =='1')
            {
                printf("%s", a[1][i]);
            }
            if (str[j] == '2')
            {
                printf("%s", a[2][i]);
            }
            if (str[j] == '3')
            {
                printf("%s", a[3][i]);
            }
            if (str[j] == '4')
            {
                printf("%s", a[4][i]);
            }
            if (str[j] == '5')
            {
                printf("%s", a[5][i]);
            }
            if (str[j] == '6')
            {
                printf("%s", a[6][i]);
            }
            if (str[j] == '7')
            {
                printf("%s", a[7][i]);
            }
            if (str[j] == '8')
            {
                printf("%s", a[8][i]);
            }
            if (str[j] == '9')
            {
                printf("%s", a[9][i]);
            }
            if (j == n - 1) printf("\n");
            if (j < n - 1) printf(".");
           
        }
    }
}
