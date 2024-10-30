#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 计算基尼系数
double calculateGini(double wealth[], int n) {
    double sumOfAbsoluteDifferences = 0.0;
    double sumOfWealth = 0.0;

    for (int i = 0; i < n; i++) {
        sumOfWealth += wealth[i];
        for (int j = 0; j < n; j++) {
            sumOfAbsoluteDifferences += fabs(wealth[i] - wealth[j]);
        }
    }
    return sumOfAbsoluteDifferences / (2 * n * sumOfWealth);
}

void experiment(int n, int t) {
    double wealth[n];
    for (int i = 0; i < n; i++) {
        wealth[i] = 100.0; // 初始化每个人的财富为100元
    }

    for (int i = 0; i < t; i++) {
        int hasMoney[n]; // 标记每个人是否有钱
        for (int j = 0; j < n; j++) {
            hasMoney[j] = (wealth[j] > 0) ? 1 : 0;
        }

        for (int j = 0; j < n; j++) {
            if (hasMoney[j]) {
                int other;
                do {
                    other = rand() % n; // 随机选择一个其他人
                } while (other == j);

                wealth[j]--; // 给自己取出1元
                wealth[other]++; // 给选中的其他人1元
            }
        }
    }

    // 排序财富数组
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (wealth[j] > wealth[j + 1]) {
                double temp = wealth[j];
                wealth[j] = wealth[j + 1];
                wealth[j + 1] = temp;
            }
        }
    }

    printf("列出每个人的财富(贫穷到富有) : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", (int)wealth[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");
    printf("这个社会的基尼系数为 : %lf\n", calculateGini(wealth, n));
}

int main() {
    printf("一个社会的基尼系数是一个在0~1之间的小数\n");
    printf("基尼系数为0代表所有人的财富完全一样\n");
    printf("基尼系数为1代表有1个人掌握了全社会的财富\n");
    printf("基尼系数越小，代表社会财富分布越均衡；越大则代表财富分布越不均衡\n");
    printf("在2022年，世界各国的平均基尼系数为0.44\n");
    printf("目前普遍认为，当基尼系数到达 0.5 时\n");
    printf("就意味着社会贫富差距非常大，分布非常不均匀\n");
    printf("社会可能会因此陷入危机，比如大量的犯罪或者经历社会动荡\n");
    printf("测试开始\n");

    int n = 100; // 人数
    int t = 1000000; // 轮数
    printf("人数 : %d\n", n);
    printf("轮数 : %d\n", t);

    srand(time(NULL)); // 随机数种子
    experiment(n, t);
    printf("测试结束\n");

    return 0;
}
//
// Created by 小画嘉 on 2024/10/30.
//
