#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �����ά�����ṹ��
typedef struct {
    int x;
    int y;
} Vector2D;

// �����ά������ģ��
double calculateMagnitude(Vector2D vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

// �ȽϺ��������������ά����
int compareVectors(const void* a, const void* b) {
    Vector2D* vectorA = (Vector2D*)a;
    Vector2D* vectorB = (Vector2D*)b;

    double magnitudeA = calculateMagnitude(*vectorA);
    double magnitudeB = calculateMagnitude(*vectorB);

    if (magnitudeA < magnitudeB) {
        return -1;
    }
    else if (magnitudeA > magnitudeB) {
        return 1;
    }
    else {
        if (vectorA->x < vectorB->x) {
            return -1;
        }
        else if (vectorA->x > vectorB->x) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

// �ҳ�ģ����С��k����ά����
void findSmallestVectors(int* list1, int list1Size, int* list2, int list2Size, int k) {
    Vector2D* vectors = (Vector2D*)malloc(sizeof(Vector2D) * list1Size * list2Size);

    int index = 0;
    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            vectors[index].x = list1[i];
            vectors[index].y = list2[j];
            index++;
        }
    }

    qsort(vectors, list1Size * list2Size, sizeof(Vector2D), compareVectors);

    printf("ģ����С��%d����ά������\n", k);
    for (int i = 0; i < k; i++) {
        printf("[%d, %d] ", vectors[i].x, vectors[i].y);
    }

    free(vectors);
}

int main() {
    int list1[200];
    char b;
    int i = 0;
    while (1)
    {
        b = getchar();
        if (b == ']') break;
        scanf("%d", &list1[i]);
        i++;//iΪ����Ԫ�ظ�����������+1,������
    }
    printf("list2=[");
    int c[200];
    char d;
    int j = 0;
    while (1)
    {
        d = getchar();
        if (d == ']') break;
        scanf("%d", &c[j]);
        j++;//iΪ����Ԫ�ظ�����������+1,������
    }
    int m;
    scanf("%d", &m);

    findSmallestVectors(list1, i, c, j,m);

    return 0;
}
