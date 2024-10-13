//7: �����߻���
//������־Ը�ߵ�ѡ�ι������� A �������ݱ�Ľ��С�Ϊ��ѡ������ʵ��˲ţ�A �ж����б�����ѡ�ֽ����˱��ԣ����Է����ﵽ���Է����ߵ�ѡ�ַ��ɽ������ԡ����Է����߸��ݼƻ�¼ȡ������ 150 % ������������ƻ�¼ȡ m ��־Ը�ߣ������Է�����Ϊ������ m ��150 % ������ȡ��������ѡ�ֵķ����������ս������Ե�ѡ��Ϊ���Գɼ����������Է����ߵ�����ѡ�֡�
//���ھ������д���򻮶����Է����ߣ���������н������Ե�ѡ�ֵı����źͱ��Գɼ���
//����
//��һ�У��������� n, m(5��n��5000, 3��m��n)���м���һ���ո���������� n ��ʾ�����μӱ��Ե�ѡ��������m ��ʾ�ƻ�¼ȡ��־Ը���������������ݱ�֤ m ��150% ����ȡ����С�ڵ��� n��
//�ڶ��е��� n + 1�У�ÿ�а��������������м���һ���ո�������ֱ���ѡ�ֵı����� k(1000��k��9999)�͸�ѡ�ֵı��Գɼ� s(1��s��100)�����ݱ�֤ѡ�ֵı����Ÿ�����ͬ��
//���
//��һ�У��� 2 ����������һ���ո��������һ��������ʾ���Է����ߣ��ڶ�������Ϊ�������Ե�ѡ�ֵ�ʵ��������
//�ӵڶ��п�ʼ��ÿ�а��� 2 ���������м���һ���ո�������ֱ��ʾ�������Ե�ѡ�ֵı����źͱ��Գɼ������ձ��Գɼ��Ӹߵ������������ɼ���ͬ���򰴱�������С�����˳�������
//����
//6 3
//1000 90
//3239 88
//2390 95
//7231 84
//1005 95
//1001 88
//���
//88 5
//1005 95
//2390 95
//1000 90
//1001 88
//3239 88
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int regNum;
    int score;
} Participant;

int compare(const void* a, const void* b) {
    Participant* p1 = (Participant*)a;
    Participant* p2 = (Participant*)b;

    // ���Ȱ��շ����Ӹߵ�������
    if (p1->score > p2->score) {
        return -1;
    }
    else if (p1->score < p2->score) {
        return 1;
    }
    else {
        // ���������ͬ�����ձ����Ŵ�С��������
        if (p1->regNum < p2->regNum) {
            return -1;
        }
        else if (p1->regNum > p2->regNum) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Participant* participants = (Participant*)malloc(n * sizeof(Participant));

    // ��ȡѡ�ֵı����źͱ��Գɼ�
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(participants[i].regNum), &(participants[i].score));
    }

    // ���չ涨�ıȽϺ�����ѡ�ֽ�������
    qsort(participants, n, sizeof(Participant), compare);

    // �������Է�����
    int cutoffIndex = (m * 150) / 100;
    int cutoffScore = participants[cutoffIndex - 1].score;

    // ͳ�Ʊ��Գɼ����������Է����ߵ�ѡ������
    int actualCount = 0;
    for (int i = 0; i < n; i++) {
        if (participants[i].score >= cutoffScore) {
            actualCount++;
        }
    }

    // ������Է����ߺ�ʵ������
    printf("%d %d\n", cutoffScore, actualCount);

    // ����������Ե�ѡ�ֵı����źͱ��Գɼ�
    for (int i = 0; i < actualCount; i++) {
        printf("%d %d\n", participants[i].regNum, participants[i].score);
    }

    free(participants);
    return 0;
}