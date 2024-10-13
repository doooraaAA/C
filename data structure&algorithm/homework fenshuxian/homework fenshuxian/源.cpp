//7: 分数线划定
//世博会志愿者的选拔工作正在 A 市如火如荼的进行。为了选拔最合适的人才，A 市对所有报名的选手进行了笔试，笔试分数达到面试分数线的选手方可进入面试。面试分数线根据计划录取人数的 150 % 划定，即如果计划录取 m 名志愿者，则面试分数线为排名第 m ×150 % （向下取整）名的选手的分数，而最终进入面试的选手为笔试成绩不低于面试分数线的所有选手。
//现在就请你编写程序划定面试分数线，并输出所有进入面试的选手的报名号和笔试成绩。
//输入
//第一行，两个整数 n, m(5≤n≤5000, 3≤m≤n)，中间用一个空格隔开，其中 n 表示报名参加笔试的选手总数，m 表示计划录取的志愿者人数。输入数据保证 m ×150% 向下取整后小于等于 n。
//第二行到第 n + 1行，每行包括两个整数，中间用一个空格隔开，分别是选手的报名号 k(1000≤k≤9999)和该选手的笔试成绩 s(1≤s≤100)。数据保证选手的报名号各不相同。
//输出
//第一行，有 2 个整数，用一个空格隔开，第一个整数表示面试分数线；第二个整数为进入面试的选手的实际人数。
//从第二行开始，每行包含 2 个整数，中间用一个空格隔开，分别表示进入面试的选手的报名号和笔试成绩，按照笔试成绩从高到低输出，如果成绩相同，则按报名号由小到大的顺序输出。
//输入
//6 3
//1000 90
//3239 88
//2390 95
//7231 84
//1005 95
//1001 88
//输出
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

    // 首先按照分数从高到低排序
    if (p1->score > p2->score) {
        return -1;
    }
    else if (p1->score < p2->score) {
        return 1;
    }
    else {
        // 如果分数相同，则按照报名号从小到大排序
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

    // 读取选手的报名号和笔试成绩
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(participants[i].regNum), &(participants[i].score));
    }

    // 按照规定的比较函数对选手进行排序
    qsort(participants, n, sizeof(Participant), compare);

    // 计算面试分数线
    int cutoffIndex = (m * 150) / 100;
    int cutoffScore = participants[cutoffIndex - 1].score;

    // 统计笔试成绩不低于面试分数线的选手人数
    int actualCount = 0;
    for (int i = 0; i < n; i++) {
        if (participants[i].score >= cutoffScore) {
            actualCount++;
        }
    }

    // 输出面试分数线和实际人数
    printf("%d %d\n", cutoffScore, actualCount);

    // 输出进入面试的选手的报名号和笔试成绩
    for (int i = 0; i < actualCount; i++) {
        printf("%d %d\n", participants[i].regNum, participants[i].score);
    }

    free(participants);
    return 0;
}