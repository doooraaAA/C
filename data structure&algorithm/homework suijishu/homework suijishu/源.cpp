//3: 明明的随机数
//明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了 N个 1到 1000 之间的随机整数 （N <= 100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
//输入
//输入有两行，第 1 行为 1 个正整数，表示所生成的随机数的个数 N。
//第 2 行有 N个用空格隔开的正整数，为所产生的随机数。
//输出
//输出也是两行，第 1 行为 1 个正整数 M，表示不相同的随机数的个数。
//第 2 行为 M 个用空格隔开的正整数，为从小到大排好序的不相同的随机数。
//输入
//10
//20 40 32 67 40 20 89 300 400 15
//输出
//8
//15 20 32 40 67 89 300 400
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int uniqueArray(int arr[], int n) {
    int uniqueArr[200];
    int uniqueCount = 0;

    if (n > 0) {
        uniqueArr[uniqueCount++] = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                uniqueArr[uniqueCount++] = arr[i];
            }
        }
    }

    for (int i = 0; i < uniqueCount; i++) {
        arr[i] = uniqueArr[i];
    }

    return uniqueCount;
}

int main() {
    int N;
    scanf("%d", &N);

    int randomArr[200];
    for (int i = 0; i < N; i++) {
        scanf("%d", &randomArr[i]);
    }

    bubbleSort(randomArr, N);

    int uniqueCount = uniqueArray(randomArr, N);

    printf("%d\n", uniqueCount);
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", randomArr[i]);
    }
    printf("\n");

    return 0;
}