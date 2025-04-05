#include <stdio.h>
#include <stdlib.h>

long long int m = 0;
long long int n = 0;
long long int i = 0;
long long int j = 0;
long long int a[200005] ;
int main()
{
    printf("告诉我你的数据量\n");
    scanf("%lld", &m);
    FILE *fp = fopen("Test.txt", "r");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return -1;
    }
    while(fscanf(fp,"%lld", &n) != EOF)
    {
        a[i++] = n;
        if (i == m) break; // 读到指定数量的数据就停止(一个保险)
    }

    

    // 这里是插入排序，和打扑克一样
    for (i= 1; i < m; i++)
    {
       for(j = i; j > 0 && a[j] < a[j-1]; j--)//相当于是每次都捋一遍手牌
       {
           long long int temp = a[j];
           a[j] = a[j-1];
           a[j-1] = temp;
       }
    }
    // 这里是输出排序后的数据
    //要先删除文件中的数据
    fclose(fp);
    fp = fopen("Test.txt", "w+");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return -1;
    }
    for (i = 0; i < m; i++)
    {
        fprintf(fp, "%lld\n", a[i]);
    }
    return 0;
}