#include <stdio.h>
#include <stdlib.h>

long long int m = 0;
long long int n = 0;
long long int i = 0;
long long int a[200005];
long long int temp[200005]; // 临时数组用于合并

// 合并两个有序子数组
void merge(long long int *a, long long int left, long long int mid, long long int right)
{
    long long int i = left;     // 左子数组起始位置
    long long int j = mid + 1;  // 右子数组起始位置
    long long int k = left;     // 临时数组起始位置

    // 合并两个子数组
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    // 将剩余的左子数组元素拷贝到临时数组
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    // 将剩余的右子数组元素拷贝到临时数组
    while (j <= right)
    {
        temp[k++] = a[j++];
    }

    // 将临时数组中的元素拷贝回原数组
    for (i = left; i <= right; i++)
    {
        a[i] = temp[i];
    }
}

// 归并排序函数
void merge_sort(long long int *a, long long int left, long long int right)
{
    if (left >= right) return; // 递归结束条件

    long long int mid = (left + right) / 2;

    // 递归排序左半部分
    merge_sort(a, left, mid);

    // 递归排序右半部分
    merge_sort(a, mid + 1, right);

    // 合并两个有序子数组
    merge(a, left, mid, right);
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

    // 调用归并排序
    merge_sort(a, 0, m - 1);

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