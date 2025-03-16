#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;      //指向后面的
    struct Node *front;     //指向前面的
} nd;

//双向链表实现
int main() {
    //初始化链表
    nd *head, *p, *tail;
    p = (nd *) malloc (sizeof(nd));
    head = p;
    tail = p;
    head->next = NULL;          //初始化管理指针
    head->front = NULL;
    

    int n;
    printf("how many number?: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        printf("No.%dnumber: ", i);
        p = (nd *) malloc (sizeof(nd));
        scanf("%d",&p->data);
        tail->next=p;                   //尾插法
        p->front = tail;            //相应的基本只多了一步往回指
        tail=p;
        tail->next=NULL;
    }

    //读出这个链表
    nd *q;
    q = head->next;
    while(q != NULL ){
        printf("numbwe:%d\n",q->data);
        q = q->next;
    }

    //那当然还要倒着读出来对不对
    q = tail;                           //因为尾节点不是空的了，不能像之前那样写
    while(q != head){                   //因为head是空的，就拿这个来当作结束标志了
        printf("numbwe:%d\n",q->data);
        q = q->front;
    }


    return 0;
}