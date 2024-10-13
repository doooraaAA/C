//3: �����������
//��������ѧУ����һЩͬѧһ����һ���ʾ���飬Ϊ��ʵ��Ŀ͹��ԣ������ü���������� N�� 1�� 1000 ֮���������� ��N <= 100�������������ظ������֣�ֻ����һ������������ͬ����ȥ������ͬ������Ӧ�Ų�ͬ��ѧ����ѧ�š�Ȼ���ٰ���Щ����С�������򣬰����źõ�˳��ȥ��ͬѧ�����顣����Э��������ɡ�ȥ�ء��롰���򡱵Ĺ�����
//����
//���������У��� 1 ��Ϊ 1 ������������ʾ�����ɵ�������ĸ��� N��
//�� 2 ���� N���ÿո��������������Ϊ���������������
//���
//���Ҳ�����У��� 1 ��Ϊ 1 �������� M����ʾ����ͬ��������ĸ�����
//�� 2 ��Ϊ M ���ÿո��������������Ϊ��С�����ź���Ĳ���ͬ���������
//����
//10
//20 40 32 67 40 20 89 300 400 15
//���
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