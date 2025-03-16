#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;               // 数据域
    struct Node *next;      // 指针域
} nd;



nd *head, *p, *tail;

int main() {
    // 初始化链表
    p = (nd *) malloc (sizeof(nd)); //（类型） malloc动态分配内存 （大小）
    head = p;                       //因为初始化管理指针所以要用head指向p
    tail = p;                       //因为初始化管理指针所以要用tail指向p
    head->next = NULL;

    //读入一些信息，在尾部增加
    int n;
    printf("how many number?: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        printf("No.%dnumber: ", i);
        p = (nd *) malloc (sizeof(nd));
        scanf("%d",&p->data);               //在这一步相当于是用p接住了一个新的data
        tail->next=p;                       //这一步相当于是把上一个尾巴接到新的节点上面
        tail=p;                             //必要步骤搞定之后那就有新的尾节点了，定义一下
        tail->next=NULL;                    //顺便管理一下这个指针
    }

    //读出这个链表
    nd *q;
    q = head->next;                             //因为一开始的链表表头是没有东西的，所以直接跳过
    while(q != NULL ){
        printf("numbwe:%d\n",q->data);
        q = q->next;                            //输出完就走人，直到尾节点有一个刚刚管理的NULL用来当结束标志
    }

    //万一我在中间想加一些东西捏
    //节点，来，来节点，来
    nd *r;
    r = (nd *) malloc (sizeof(nd));
    r->data = 100;  
    r->next = head->next;                       //这一步是把新的节点接到原来的第一个节点上面
    head->next = r;                             //这一步是把新的节点接到表头上面 
    //读出这个链表
    q = head->next;                             //因为一开始的链表表头是没有东西的，所以直接跳过
    while(q != NULL ){
        printf("numbwe:%d\n",q->data);
        q = q->next;                            //输出完就走人，直到尾节点有一个刚刚管理的NULL用来当结束标志
    }

    //删除一个节点（第一个节点）
    nd *s;
    s = head->next;                             //因为一开始的链表表头是没有东西的，所以直接跳过
    head->next = s->next;                       //这一步是把表头接到第二个节点上面，跳了一级
    free(s);                                    //释放内存

    //读出这个链表
    q = head->next;                             //一样的，不说了
    while(q != NULL ){
        printf("numbwe:%d\n",q->data);
        q = q->next;                            
    }
    return 0;
}

