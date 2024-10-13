//9: ��ʯ
//����˳����õ�n��Ͱ��ÿ��Ͱ��װ��һ����ʯ��ÿ����ʯ����ɫ�Ǻ죬�ף���֮һ��Ҫ�����°�����Щ��ʯ��ʹ�����к�ɫ��ʯ��ǰ�����а�ɫ��ʯ���У�������ɫ��ʯ�Ӻ����°���ʱ��ÿ����ʯ����ɫֻ�ܿ�һ�Σ�����ֻ������������������ʯ��λ�á�
//����
//ÿ���������С���һ��Ϊ��ʯ������n���ڶ�����n(1 <= n <= 105������ĸ������ÿ����ʯ����ɫ����ĸ֮���ÿո�ָ���R�����ɫ��W�����ɫ��B������ɫ����
//	���
//	n������������ú���ַ����ÿո�ָ���
//	����
//	����
//	5
//	R W R B R
//	���
//	R R R W B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ�ص�ֵ
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// ���°�����ʯ
void rearrangePebbles(char* pebbles, int n) {
    int left = 0; // ָ��������ɫ��ʯ��ָ��
    int right = n - 1; // ָ�����Ҳ���ɫ��ʯ��ָ��
    int current = 0; // ������ʯ�����ָ��

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

    // ������ʯ��ɫ
    for (int i = 0; i < n; i++) {
        scanf(" %c", &pebbles[i]);
    }

    rearrangePebbles(pebbles, n);

    // ����������к����ʯ
    for (int i = 0; i < n; i++) {
        printf("%c ", pebbles[i]);
    }
    printf("\n");

    free(pebbles);

    return 0;
}