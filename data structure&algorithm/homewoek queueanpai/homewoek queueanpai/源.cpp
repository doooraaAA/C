//2: 队列安排
//一个学校里老师要将班上 N 个同学排成一列，同学被编号为1∼N，他采取如下的方法：
//先将 1 号同学安排进队列，这时队列中只有他一个人；
//2 - N 号同学依次入列，编号为 i 的同学入列方式为：老师指定编号为 i 的同学站在编号为 1∼(i−1) 中某位同学（即之前已经入列的同学）的左边或右边；
//最后，从队列中去掉 M(M < N） 个同学，其他同学位置顺序不变。
//	在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。
//	输入
//	第 1 行为一个正整数 N，表示了有 N 个整数。
//	第 2∼N行，第 i 行包含两个整数 k, p，其中 k 为小于i 的正整数，p 为 0 或者 1。若 p 为0，则表示将 i 号同学插入到 k 号同学的左边，p 为 1 则表示插入到右边。
//	第 N + 1 行为一个正整数 M，表示去掉的同学数目。
//	接下来 M行，每行一个正整数 x，表示将 x 号同学从队列中移去，如果 x 号同学已经不在队列中则忽略这一条指令。
//	输出
//	1 行，包含最多 N 个空格隔开的正整数，表示了队列从左到右所有同学的编号，行末换行且无空格。
//	输入
//	4
//	1 0
//	2 1
//	1 0
//	2
//	3
//	3
//	输出
//	2 4 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int queue[150];

// 移除指定的学生
void removeStudent(  int N,int student) {
    int i;
    for ( i = 0; i < N; i++)
    {
        if (student == queue[i]) {
            queue[i] = -1;
        }
    }
}

int main() {
    int N, i;
    int size = 1;
    queue[0] = 1;
    // 输入 N，表示队列中的学生个数
    scanf("%d", &N);
    int s;
    // 循环读取 N-1 行学生的位置信息
    for (i = 1; i < N; i++) {
        int k, p;
        scanf("%d %d", &k, &p);
        for (int t = 0; t < size; t++)
        {
            if (queue[t] == k) {
                s = t;
                break;
            }
        }
        if (p == 1) {
            // 移动后面的学生位置，为新学生腾出位置
            int j;
            for (j = size - 1; j >s; j--) {
                queue[j + 1] = queue[j];
            }
            queue[s+1] = i + 1;
            size++;
           
        }
        else if (p == 0) {
            int j;
            for (j = size - 1; j >= s; j--) {
                queue[j + 1] = queue[j];
            }
            queue[s] = i + 1;
            size++;
           
        }
    }
 
    int M;
    // 输入 M，表示要移除的学生个数
    scanf("%d", &M);

    // 循环读取要移除的学生序号，然后移除队列中对应的学生
    for (i = 0; i < M; i++) {
        int removedStudent;
        scanf("%d", &removedStudent);
        removeStudent( N,removedStudent);
    }

    // 输出最终队列中的学生序号
    
        for (i = 0; i < size; i++) {
            if (queue[i] != -1) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    

    return 0;
}