//8: 合并果子
//在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
//每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过 n - 1次合并之后， 就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
//因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为 1 ，并且已知果子的种类 数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
//例如有 3 种果子，数目依次为 1 ， 2 ， 9 。可以先将 1 、 2 堆合并，新堆数目为 3 ，耗费体力为 3 。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为 12 ，耗费体力为 12 。所以多多总共耗费体力 = 3 + 12 = 15 。可以证明 15 为最小的体力耗费值。
//输入
//共两行。
//第一行是一个整数 n(1≤n≤10000) ，表示果子的种类数。
//第二行包含 n 个整数，用空格分隔，第 i 个整数ai(1≤ai≤20000) 是第 i 种果子的数目。
//输出
//一个整数，也就是最小的体力耗费值。输入数据保证这个值小于 2e31
//输入
//3
//1 2 9
//输出
//15
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 优先队列（最小堆）
typedef struct {
    int size; // 队列大小
    int capacity; // 队列容量
    int* heap; // 堆数组
} PriorityQueue;

// 初始化优先队列
PriorityQueue* initPriorityQueue(int capacity) {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->heap = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// 入队
void enqueue(PriorityQueue* queue, int value) {
    int i = queue->size;
    while (i > 0 && value < queue->heap[(i - 1) / 2]) {
        queue->heap[i] = queue->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->heap[i] = value;
    queue->size++;
}

// 出队
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

// 计算最小的体力耗费值
int calculateMinEnergy(int* arr, int n) {
    PriorityQueue* queue = initPriorityQueue(n);

    for (int i = 0; i < n; i++) {
        enqueue(queue, arr[i]);
    }

    int minEnergy = 0;
    while (queue->size > 1) {
        int sum = dequeue(queue) + dequeue(queue); // 合并两堆果子
        minEnergy += sum;
        enqueue(queue, sum); // 将新堆加入优先队列
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