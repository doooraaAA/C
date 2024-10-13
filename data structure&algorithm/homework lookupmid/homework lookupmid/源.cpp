//��д���۰���ҵĵݹ��㷨��
//�� 1 ��Ϊһ�������� N��M����ʾ���� N ��1 <= N <= 105������, M��1 <= M <= 105����ѯ�ʡ�
//��2�У�N����С�����������
//�� 3 ~M + 2�У�ÿ��һ����x��ʾ��Ҫ���ҵ�����
//���
//M �У�ÿ��һ������ʾ��i��ѯ�ʵ������������һ�γ��ֵ��±꣬������������ - 1��
//����
//4 3
//1 2 2 4
//2
//1
//3
//���
//2
//1
//- 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[150];
// �ݹ�ʵ���۰����
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