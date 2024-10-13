//8: �ϲ�����
//��һ����԰�����Ѿ������еĹ��Ӵ������������Ұ����ӵĲ�ͬ����ֳ��˲�ͬ�Ķѡ������������еĹ��Ӻϳ�һ�ѡ�
//ÿһ�κϲ��������԰����ѹ��Ӻϲ���һ�����ĵ������������ѹ��ӵ�����֮�͡����Կ��������еĹ��Ӿ��� n - 1�κϲ�֮�� ��ֻʣ��һ���ˡ�����ںϲ�����ʱ�ܹ����ĵ���������ÿ�κϲ���������֮�͡�
//��Ϊ��Ҫ������������Щ���Ӱ�ؼң����Զ���ںϲ�����ʱҪ�����ܵؽ�ʡ�������ٶ�ÿ������������Ϊ 1 ��������֪���ӵ����� ����ÿ�ֹ��ӵ���Ŀ�������������Ƴ��ϲ��Ĵ��򷽰���ʹ���ķѵ��������٣�����������С�������ķ�ֵ��
//������ 3 �ֹ��ӣ���Ŀ����Ϊ 1 �� 2 �� 9 �������Ƚ� 1 �� 2 �Ѻϲ����¶���ĿΪ 3 ���ķ�����Ϊ 3 �����ţ����¶���ԭ�ȵĵ����Ѻϲ����ֵõ��µĶѣ���ĿΪ 12 ���ķ�����Ϊ 12 �����Զ���ܹ��ķ����� = 3 + 12 = 15 ������֤�� 15 Ϊ��С�������ķ�ֵ��
//����
//�����С�
//��һ����һ������ n(1��n��10000) ����ʾ���ӵ���������
//�ڶ��а��� n ���������ÿո�ָ����� i ������ai(1��ai��20000) �ǵ� i �ֹ��ӵ���Ŀ��
//���
//һ��������Ҳ������С�������ķ�ֵ���������ݱ�֤���ֵС�� 2e31
//����
//3
//1 2 9
//���
//15
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���ȶ��У���С�ѣ�
typedef struct {
    int size; // ���д�С
    int capacity; // ��������
    int* heap; // ������
} PriorityQueue;

// ��ʼ�����ȶ���
PriorityQueue* initPriorityQueue(int capacity) {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->heap = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// ���
void enqueue(PriorityQueue* queue, int value) {
    int i = queue->size;
    while (i > 0 && value < queue->heap[(i - 1) / 2]) {
        queue->heap[i] = queue->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->heap[i] = value;
    queue->size++;
}

// ����
int dequeue(PriorityQueue* queue) {
    int min = queue->heap[0];
    int last = queue->heap[queue->size - 1];
    queue->size--;

    int i = 0, child;
    while (2 * i + 1 < queue->size) {
        child = 2 * i + 1;
        if (child < queue->size - 1 && queue->heap[child + 1] < queue->heap[child]) {
            child++;
        }
        if (last > queue->heap[child]) {
            queue->heap[i] = queue->heap[child];
            i = child;
        }
        else {
            break;
        }
    }
    queue->heap[i] = last;

    return min;
}

// ������С�������ķ�ֵ
int calculateMinEnergy(int* arr, int n) {
    PriorityQueue* queue = initPriorityQueue(n);

    for (int i = 0; i < n; i++) {
        enqueue(queue, arr[i]);
    }

    int minEnergy = 0;
    while (queue->size > 1) {
        int sum = dequeue(queue) + dequeue(queue); // �ϲ����ѹ���
        minEnergy += sum;
        enqueue(queue, sum); // ���¶Ѽ������ȶ���
    }

    free(queue->heap);
    free(queue);

    return minEnergy;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minEnergy = calculateMinEnergy(arr, n);
    printf("%d\n", minEnergy);

    free(arr);

    return 0;
}