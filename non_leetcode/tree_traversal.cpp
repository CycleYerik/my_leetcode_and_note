#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
}TreeNode;
 
void pre_order(TreeNode * Node)//前序遍历递归算法
{
    if(Node == NULL)
        return;
    printf("%d ", Node->data);//显示节点数据，可以更改为其他操作。在前面
    pre_order(Node->left);
    pre_order(Node->right);
}
void middle_order(TreeNode *Node)//中序遍历递归算法
{
    if(Node == NULL)
        return;
    middle_order(Node->left);
    printf("%d ", Node->data);//在中间
    middle_order(Node->right);
}
void post_order(TreeNode *Node)//后序遍历递归算法
{
    if(Node == NULL)
        return; 
    post_order(Node->left);
    post_order(Node->right);
    printf("%d ", Node->data);//在最后
}

int main(void)
{
    TreeNode *root = new TreeNode;
    root->data = 1;
    root->left = new TreeNode;
    root->right = new TreeNode;
    root->left->data = 2;
    root->right->data = 3;
    root->left->left = new TreeNode;
    root->left->right = new TreeNode;
    root->left->left->data = 4;
    root->left->right->data = 5;
    root->right->left = new TreeNode;
    root->right->right = new TreeNode;
    root->right->left->data = 6;
    root->right->right->data = 7;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    printf("前序遍历：");
    pre_order(root);
    printf("\n");
    printf("中序遍历：");
    middle_order(root);
    printf("\n");
    printf("后序遍历：");
    post_order(root);
    printf("\n");
    return 0;
}