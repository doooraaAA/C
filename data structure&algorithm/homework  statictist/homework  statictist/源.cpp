//6: ͳ������
//����
//ĳ�ο��е���ʱ�õ���n����Ȼ����ÿ������������1500000000(1.5��109
//)����֪����ͬ����������10000����������Ҫͳ����Щ��Ȼ�����Գ��ֵĴ�������������Ȼ����С�����˳�����ͳ�ƽ����
//����
//��n + 1�С�
//��һ��������n����ʾ��Ȼ���ĸ�����
//��2��n + 1ÿ��һ����Ȼ����
//���
//��m�У�mΪn����Ȼ���в���ͬ���ĸ�������������Ȼ����С�����˳�������
//ÿ�����2���������ֱ�����Ȼ���͸������ֵĴ����������һ���ո������
//����
//8
//2
//4
//2
//4
//5
//100
//2
//100
//���
//2 3
//4 2
//5 1
//100 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortArray(int arr[], int size) {
    // ʹ��ð����������������������
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
    sortArray(arr, size); // �������������

    int i, count = 1;

    for (i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        }
        else {
                printf("%d %d \n", arr[i], count);
            count = 1; // ���ü�����
        }
    }

    // ������һ��Ԫ��
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