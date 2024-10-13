//5: 纪念品分组
//元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得 的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品， 并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。
//你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。
//输入
//共 n + 2行：
//第一行包括一个整数 w，为每组纪念品价格之和的上限。
//第二行为一个整数 n，表示购来的纪念品的总件数 G。
//第 3 ∼n + 2 行每行包含一个正整数 Pi 表示所对应纪念品的价格。
//输出
//一个整数，即最少的分组数目。
//样例
//输入
//100
//9
//90
//20
//20
//30
//50
//60
//70
//80
//90
//输出
//6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void quickSort(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j) {
        quickSort(arr, low, j);
    }
    if (i < high) {
        quickSort(arr, i, high);
    }
}

int minGroups(int arr[], int n, int w) {
    int count = 0;
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        if (arr[left] + arr[right] <= w) {
            left++;
            right--;
            count++;
        }
        else {
            right--;
            count++;
        }
    }

    return count;
}

int main() {
    int w, n;
    scanf("%d", &w);
    scanf("%d", &n);

    int prices[200];

    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    quickSort(prices, 0, n - 1);

    int min = minGroups(prices, n, w);
    printf("%d\n", min);

    return 0;
}