#include <stdio.h>
#include <stdlib.h>

long long int m = 0;
long long int n = 0;
long long int i = 0;
long long int a[200005];

int main()
{
    printf("告诉我你的数据量\n");
    scanf("%lld", &m);

    // 打开文件读取数据
    FILE *fp = fopen("Test.txt", "r");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return -1;
    }

    // 读取数据到数组 a
    long long int max_val = 0; // 用于记录最大值
    for (i = 0; i < m && fscanf(fp, "%lld", &n) != EOF; i++)
    {
        a[i] = n;
        if (n > max_val) max_val = n; // 更新最大值
    }
    fclose(fp);

    // 创建计数数组并初始化
    long long int *count = (long long int *)calloc(max_val + 1, sizeof(long long int));
    if (count == NULL)
    {
        printf("内存分配失败\n");
        return -1;
    }

    // 统计每个元素的出现次数
    for (i = 0; i < m; i++)
    {
        count[a[i]]++;
    }

    // 根据计数数组生成排序后的数组
    long long int index = 0;
    for (i = 0; i <= max_val; i++)
    {
        while (count[i] > 0)
        {
            a[index++] = i;
            count[i]--;
        }
    }

    free(count); // 释放计数数组的内存

    // 打开文件写入排序后的数据
    fp = fopen("Test.txt", "w");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return -1;
    }
    for (i = 0; i < m; i++)
    {
        fprintf(fp, "%lld\n", a[i]);
    }
    fclose(fp);

    printf("排序完成，结果已写入 Test.txt\n");
    return 0;
}