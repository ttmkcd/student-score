#include <stdio.h>
int main()
{
    int chengji[100];   // 100个座位存成绩，用不满没关系
    int n, i, j, t;     // n:几个人  i,j:叫号用的  t:交换时的临时桶
    int sum = 0;        // 累加器，出生必须是0
    double avg;         // 平均分要小数，用double
    int max;            // 擂主

    // ① 录入：一次全读进来，边读边加
    printf("请输入成绩个数：");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &chengji[i]);   // 第 i 号座位 ← 你输的第 i+1 个数
        sum += chengji[i];
    }

    // ② 把存的原样吐出来，验证没存错
    printf("成绩单：");
    for(i = 0; i < n; i++)
        printf("%d ", chengji[i]);
    printf("\n");

    // ③ 平均分
    avg = (double)sum / n;          // (double) 让sum临时变成小数再除，不然小数被切掉
    printf("平均分：%.2f\n", avg);

    // ④ 擂主法：0号房先当擂主，后面全是挑战者
    max = chengji[0];
    for(i = 1; i < n; i++)
        if(chengji[i] > max)
            max = chengji[i];       // 打赢就抢擂，打不赢擂主不动
    printf("最高分：%d\n", max);

    // ⑤ 冒泡：相邻俩俩比，小的往后换，一轮后最小的沉底，共 n-1 轮
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-1-i; j++)  // 右边站好队的人不再动，所以每轮少比一个
            if(chengji[j] < chengji[j+1]) {
                t = chengji[j];
                chengji[j] = chengji[j+1];
                chengji[j+1] = t;
            }

    // ⑥ 排好队，再打印一遍
    printf("从高到低：");
    for(i = 0; i < n; i++)
        printf("%d ", chengji[i]);
    printf("\n");

    return 0;
}
