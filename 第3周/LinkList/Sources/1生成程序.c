#include <stdio.h>
#include <stdlib.h>

//"编写一个按要求生成测试数据，并保存到文件的程序"
//这里应该提供两种输出，一种是大数据量（三种）的，另一种是小数据量但是高频的
int main()
{
    int n = 0;
    a:
    printf("请输入你想选择的模式（1：大数据量|2：大量小数据量）\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        //先做一个可以生成大量数据的，有三个层次可以选择（10000、50000、200000）
        printf("请输入你想生成的数据量（1：10000|2：50000|3：200000）\n");
        int m = 0;
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            //生成10000个数据
            {
                FILE *fp = fopen("Test.txt", "w+");
                if (fp == NULL)
                {
                    printf("文件打开失败\n");
                    return -1;
                }
                for (int i = 0; i < 10000; i++)
                {
                    fprintf(fp, "%d\n", rand() % 1000000);//生成0-999999的随机数
                }
                fclose(fp);
            }
            break;
        case 2:
            //生成50000个数据
            {
                FILE *fp = fopen("Test.txt", "w+");
                if (fp == NULL)
                {
                    printf("文件打开失败\n");
                    return -1;
                }
                for (int i = 0; i < 50000; i++)
                {
                    fprintf(fp, "%d\n", rand() % 1000000);//生成0-999999的随机数
                }
                fclose(fp);
            }
            break;
        case 3:
            
            //生成200000个数据
            {
                FILE *fp = fopen("Test.txt", "w+");
                if (fp == NULL)
                {
                    printf("文件打开失败\n");
                    return -1;
                }
                for (int i = 0; i < 200000; i++)
                {
                    fprintf(fp, "%d\n", rand() % 1000000);//生成0-999999的随机数
                }
                fclose(fp);
            }
            break;
        default:
            printf("输入错误，请重新输入\n");
            goto a;
            break;
        }
        printf("数据生成完毕，文件名为Test.txt\n");
        printf("请查看文件\n");
        
      
        break;
    case 2:
        //再写一个大量小数据量的

        break;
    default:
        printf("输入错误，请重新输入\n");
        goto a;
        break;
    }
    






    
    return 0;
}