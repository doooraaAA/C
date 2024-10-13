//6: 统计数字
//描述
//某次科研调查时得到了n个自然数，每个数均不超过1500000000(1.5×109
//)。已知不相同的数不超过10000个，现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统计结果。
//输入
//共n + 1行。
//第一行是整数n，表示自然数的个数；
//第2至n + 1每行一个自然数。
//输出
//共m行（m为n个自然数中不相同数的个数），按照自然数从小到大的顺序输出。
//每行输出2个整数，分别是自然数和该数出现的次数，其间用一个空格隔开。
//输入
//8
//2
//4
//2
//4
//5
//100
//2
//100
//输出
//2 3
//4 2
//5 1
//100 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortArray(int arr[], int size) {
    // 使用冒泡排序对数组进行升序排序
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printDuplicates(int arr[], int size) {
    sortArray(arr, size); // 对数组进行排序

    int i, count = 1;

    for (i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        }
        else {
                printf("%d %d \n", arr[i], count);
            count = 1; // 重置计数器
        }
    }

    // 检查最后一个元素
    if (count > 1) {
        printf("%d %d\n", arr[size - 1], count);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printDuplicates(arr, n);

    return 0;
}