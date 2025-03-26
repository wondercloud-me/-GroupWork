#include <stdio.h>
#include <stdlib.h>
//用链栈实现四则运算表达式的计算
typedef struct node
{
    char data;
    struct node *next;
} Node;

void push(Node *head, char ch)//入栈
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = ch;
    p->next = head->next;
    head->next = p;
}

char pop(Node *head)//出栈
{
    Node *p = head->next;
    head->next = p->next;
    char ch = p->data;
    free(p);
    return ch;
}

char get_top(Node *head)//取栈顶元素
{
    return head->next->data;
}

int priority(char ch)//判断运算符优先级
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void counting_number()//计算表达式
{
    //先转化成后缀表达式
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    char ch;
    printf("中缀表达式为：");
    while ((ch = getchar()) != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            printf("%c", ch);
        }
        else if (ch == '(')
        {
            push(head, ch);
        }
        else if (ch == ')')
        {
            while (get_top(head) != '(')
            {
                printf("%c", pop(head));
            }
            pop(head);//弹出'('
        }
        else
        {
            while (head->next != NULL && priority(ch) <= priority(get_top(head)))
            {
                printf("%c", pop(head));
            }
            push(head, ch);
        }
    }
    while (head->next != NULL)
    {
        printf("%c", pop(head));
    }
    //计算后缀表达式
    Node *head2 = (Node *)malloc(sizeof(Node));//用于计算的栈
    head2->next = NULL;
    while ((ch = getchar()) != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            push(head2, ch);
        }
        else
        {
            int num2 = pop(head2) - '0';
            int num1 = pop(head2) - '0';
            switch (ch)
            {
            case '+':
                push(head2, num1 + num2 + '0');
                break;
            case '-':
                push(head2, num1 - num2 + '0');
                break;
            case '*':
                push(head2, num1 * num2 + '0');
                break;
            case '/':
                push(head2, num1 / num2 + '0');
                break;
            }
        }
    }
    printf("\n计算结果为：%d\n", pop(head2) - '0');
    free(head);
    free(head2);
    
}




int main()
{
    //例子
    // (1+2)*3-4/2

    counting_number();
    return 0;
}