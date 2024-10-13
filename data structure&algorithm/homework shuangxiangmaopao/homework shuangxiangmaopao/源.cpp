//10: 双向冒泡排序
//有n个记录存储在带头结点的双向链表中，现用双向冒泡排序法对其按升序进行排序，请写出这种排序的算法。(注：双向冒泡排序即相邻两趟排序向相反方向起泡)。
//输入
//共两行。
//第一行是一个整数 n(1≤n≤3000) ，表示数的个数。
//第二行包含 n 个整数，用空格分隔，第 i 个整数ai(1≤ai≤231 - 1)。
//输出
//n个从小到大排序后的整数，用空格分隔。
//输入
//5
//4 2 4 5 1
//输出
//1 2 4 4 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
    int n;
    scanf("%d", &n);

    int arr[3010];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}