#include <stdio.h>
#include <stdlib.h>

//先用结构体来实现节点
typedef struct treenode
{
    int data;
    struct treenode*left ;
    struct treenode*right ;
}treenode ;

//还有一个二叉排序树
typedef struct sorttree
{
    treenode root;
};
 
//下面还要实现几个基本的函数来便利操作:
//1.插入操作，把一个数插入树内
treenode* insert(treenode *root ,int data)
{
    if(root == NULL){
        treenode *newnode = (treenode*)malloc(sizeof(treenode));//相当于c++的new，但是写起来很不顺手
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (data <= root->data)
    {
        root->left = insert(root->left,data);//用递归保证放在最后面而不是取代已有节点
    }
    else if (data > root->data)
    {
        root->right = insert(root->right,data);
    }
}

//2.查找
//我的理解是找到一个数，然后返回这个root（可能是方便更改还是什么）
treenode *searchnode(treenode *root,int data)
{
    if (root == NULL)
    {
        printf("false\n");
        return root;
    }
    if (data < root->data)
    {
        return searchnode(root->left,data);
    }
    else if (data > root->data)
    {
        return searchnode(root->right,data);
    }
    else if (data == root->data)
    {
        printf("true\n");
        return root;
    }
    //这里的else if 其实是多余的，因为上面已经判断过了
    
}

//3.删除
treenode *deletenode(treenode *root,int data)
{
    if (root==NULL)
    {
        printf("false\n");
        return root;
    }
    if(data < root->data){
        return deletenode(root->left,data);
    }
    else if (data >root->data)
    {
        return deletenode(root->right,data);
    }
    else if (data == root->data)
    {
        //叶节点
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        //只有一个子节点
        if(root->left == NULL)
        {
            treenode *temp = root->left;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            treenode *temp = root->right;
            free(root);
            return temp;
        }
        //有两个子节点
        //这里最重要的是找到代替这个结点的数，很明显因为这个数一定要大于左边的又要小于右边的，只能找右边最小的或者左边最大的
        if (root->left != NULL&&root->right !=NULL)
        {
            //找到右边最小的
            treenode *minnode = root->right;
            while(minnode->left != NULL)
            {
                minnode = minnode->left;
            }
            //把节点数字换掉之后删掉右边最小这个节点
            root->data = minnode->data;
            deletenode(minnode,minnode->data);
            free(minnode);
        }
        return root;
    }
    
    
}

//4.遍历
//对于二叉排序树用的是中序排列，这样子输出之后就是一个有序序列了
void sortree(treenode *root)
{
    if (root->left != NULL)
    {
        sortree(root->left);
        printf("%d",root->data);
        sortree(root->right);
        //这里挺妙的，因为递归会一直找到最左边，然后找完一旦是null那就返回到上一级（这里刚好方便了可以用来输出这个实际上最左边的节点!)，然后找右边（一开始是因为要理论上遍历完所有节点，但是更好的地方是还可以完成再上一个结点的时候可以访问到上一个节点的右端点！）

    }
    //这里输出来之后就是一个有序系列了
}

//主函数
int main()
{
    // 创建一个空的二叉排序树
    treenode *root = NULL;

    // 插入一些测试数据
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // 中序遍历，输出有序序列
    printf("中序遍历结果: ");
    sortree(root);
    printf("\n");

    // 查找节点
    printf("查找节点 40: ");
    searchnode(root, 40);

    printf("查找节点 90: ");
    searchnode(root, 90);

    // 删除节点
    printf("删除节点 20\n");
    root = deletenode(root, 20);

    printf("删除节点 30\n");
    root = deletenode(root, 30);

    printf("删除节点 50\n");
    root = deletenode(root, 50);

    // 再次中序遍历，验证删除效果
    printf("中序遍历结果: ");
    sortree(root);
    printf("\n");

    return 0;
}
