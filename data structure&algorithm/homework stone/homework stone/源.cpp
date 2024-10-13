//9: 砾石
//设有顺序放置的n个桶，每个桶中装有一粒砾石，每粒砾石的颜色是红，白，蓝之一。要求重新安排这些砾石，使得所有红色砾石在前，所有白色砾石居中，所有蓝色砾石居后，重新安排时对每粒砾石的颜色只能看一次，并且只允许交换操作来调整砾石的位置。
//输入
//每组数据两行。第一行为砾石的数量n，第二行有n(1 <= n <= 105）个字母，代表每个砾石的颜色（字母之间用空格分隔，R代表红色，W代表白色，B代表蓝色）。
//	输出
//	n个按题意排序好后的字符，用空格分隔。
//	样例
//	输入
//	5
//	R W R B R
//	输出
//	R R R W B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 交换两个元素的值
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// 重新安排砾石
void rearrangePebbles(char* pebbles, int n) {
    int left = 0; // 指向最左侧红色砾石的指针
    int right = n - 1; // 指向最右侧蓝色砾石的指针
    int current = 0; // 遍历砾石数组的指针

    while (current <= right) {
        if (pebbles[current] == 'R') {
            swap(&pebbles[current], &pebbles[left]);
            left++;
            current++;
        }
        else if (pebbles[current] == 'B') {
            swap(&pebbles[current], &pebbles[right]);
            right--;
        }
        else {
            current++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char* pebbles = (char*)malloc(n * sizeof(char));

    // 输入砾石颜色
    for (int i = 0; i < n; i++) {
        scanf(" %c", &pebbles[i]);
    }

    rearrangePebbles(pebbles, n);

    // 输出重新排列后的砾石
    for (int i = 0; i < n; i++) {
        printf("%c ", pebbles[i]);
    }
    printf("\n");

    free(pebbles);

    return 0;
}