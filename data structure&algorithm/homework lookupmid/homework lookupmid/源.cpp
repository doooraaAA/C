//试写出折半查找的递归算法。
//第 1 行为一个正整数 N，M，表示了有 N （1 <= N <= 105）个数, M（1 <= M <= 105）次询问。
//第2行，N个从小到大的整数。
//第 3 ~M + 2行，每行一个数x表示需要查找的数。
//输出
//M 行，每行一个数表示第i次询问的数在数组里第一次出现的下标，如果不存在输出 - 1。
//输入
//4 3
//1 2 2 4
//2
//1
//3
//输出
//2
//1
//- 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[150];
// 递归实现折半查找
int binary_search( int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target && arr[mid - 1] != target)
        return mid + 1;
    else if (arr[mid] == target && arr[mid - 1] == target)
    {
        while (arr[mid - 1] == target) {
            mid--;
        }
        return mid + 1;
    }
    else if (arr[mid] < target)
        return binary_search( mid + 1, right, target);
    else
        return binary_search( left, mid - 1, target);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        int index = binary_search( 0, N - 1, x);
        printf("%d\n", index);
    }

    return 0;
}