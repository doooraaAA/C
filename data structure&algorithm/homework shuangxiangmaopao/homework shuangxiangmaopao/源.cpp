//10: ˫��ð������
//��n����¼�洢�ڴ�ͷ����˫�������У�����˫��ð�����򷨶��䰴�������������д������������㷨��(ע��˫��ð���������������������෴��������)��
//����
//�����С�
//��һ����һ������ n(1��n��3000) ����ʾ���ĸ�����
//�ڶ��а��� n ���������ÿո�ָ����� i ������ai(1��ai��231 - 1)��
//���
//n����С�����������������ÿո�ָ���
//����
//5
//4 2 4 5 1
//���
//1 2 4 4 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ����Ԫ��
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