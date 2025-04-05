#include <stdio.h>
#include <stdlib.h>

int main()
{
    //先进行一个数据量的输入
    int k = 0;
    int i = 0;
    int n = 0;
    int a[10] = {0};
    printf("请输入数据，以 -1 结束输入：\n");
    while (scanf("%d", &k) != EOF ) // 输入以 -1 结束
    {
        a[i++] = k;
        n++;
    }
    //printf("111111111111\n");
    //设定一个三指针的方式来进行排序
    //一左一右，剩下这个遍历
    int p1 = 0;    
    int p2 = n-1;
    int p3 = 0;
    
    while (p3 <= p2) // 遍历数组
    {
        if (a[p3] == 0) // 如果当前值是 0
        {
            int temp = a[p1];
            a[p1] = a[p3];
            a[p3] = temp;
            p1++;
            p3++;
        }
        else if (a[p3] == 2) // 如果当前值是 2
        {
            int temp = a[p2];
            a[p2] = a[p3];
            a[p3] = temp;
            p2--;
        }
        else // 如果当前值是 1
        {
            p3++;
        }
    }
    //这里是输出排序后的数据
    for(i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    
    return 0;
}