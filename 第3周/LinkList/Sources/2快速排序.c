#include <stdio.h>
#include <stdlib.h>

long long int m = 0;
long long int n = 0;
long long int i = 0;
long long int a[200005];

// 快速排序函数
void quick_sort(long long int *a, long long int left, long long int right)
{
    if (left >= right) return; // 递归结束条件

    long long int pivot = a[left]; // 选择基准值
    long long int l = left;
    long long int r = right;

    while (l < r)
    {
        // 从右向左找到第一个小于基准值的元素
        while (l < r && a[r] >= pivot) r--;
        if (l < r) a[l++] = a[r];//这里的是赋值后l++

        // 从左向右找到第一个大于基准值的元素
        while (l < r && a[l] <= pivot) l++;
        if (l < r) a[r--] = a[l];//最后a[l]空了，放基准值
    }

    a[l] = pivot; // 将基准值放到正确位置

    // 对左右两部分递归排序
    quick_sort(a, left, l - 1);
    quick_sort(a, l + 1, right);
}

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

    while (fscanf(fp, "%lld", &n) != EOF)
    {
        a[i++] = n;
        if (i == m) break; // 读到指定数量的数据就停止
    }
    fclose(fp);

    // 调用快速排序
    quick_sort(a, 0, m - 1);

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