//4: 奖学金
//描述
//某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前 5 名学生发奖学金。期末，每个学生都有 3 门课的成绩 : 语文、数学、英语。先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面，这样，每个学生的排序是唯一确定的。
//任务：先根据输入的 3 门课的成绩计算总分，然后按上述规则排序，最后按排名顺序输出前五名名学生的学号和总分。注意，在前 5 名同学中，每个人的奖学金都不相同，因此，你必须严格按上述规则排序。例如，在某个正确答案中，如果前两行的输出数据(每行输出两个数 : 学号、总分) 是 :
//	7 279
//	5 279
//	这两行数据的含义是 : 总分最高的两个同学的学号依次是 7 号、5 号。这两名同学的总分都是 279 (总分等于输入的语文、数学、英语三科成绩之和)，但学号为 7 的学生语文成绩更高一些。如果你的前两名的输出数据是 :
//	5 279
//	7 279
//	则按输出错误处理，不能得分。
//	输入
//	共 n + 1行。
//	第 1 行为一个正整数n（n≤300)，表示该校参加评选的学生人数。
//	第 2 到 n + 1 行，每行有 3 个用空格隔开的数字，每个数字都在 0 到 100之间。第 j行的 3 个数字依次表示学号为 j - 1 的学生的语文、数学、英语的成绩。每个学生的学号按照输入顺序编号为 1~n（恰好是输入数据的行号减 1）。
//	输出
//	共 5 行，每行是两个用空格隔开的正整数，依次表示前 5 名学生的学号和总分。
//	输入1
//	6
//	90 67 80
//	87 66 91
//	78 89 91
//	88 99 77
//	67 89 64
//	78 89 98
//	输出1
//	6 265
//	4 264
//	3 258
//	2 244
//	1 237
//	输入2
//	8
//	80 89 89
//	88 98 78
//	90 67 80
//	87 66 91
//	78 89 91
//	88 99 77
//	67 89 64
//	78 89 98
//	输出2
//	8 265
//	2 264
//	6 264
//	1 258
//	5 258
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student {
    int id;
    int chinese;
    int math;
    int english;
    int total;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].total < arr[j + 1].total ||
                (arr[j].total == arr[j + 1].total && arr[j].chinese < arr[j + 1].chinese) ||
                (arr[j].total == arr[j + 1].total && arr[j].chinese == arr[j + 1].chinese && arr[j].id > arr[j + 1].id)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Student students[1000];

    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        scanf("%d %d %d", &students[i].chinese, &students[i].math, &students[i].english);
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }

    bubbleSort(students, n);

    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", students[i].id, students[i].total);
    }

    return 0;
}