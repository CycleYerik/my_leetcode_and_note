
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * @param root  树根
 * @param returnSize  输出：结果数组长度
 * @return  int*  后序遍历结果（调用方 free）
 */
 vector<int> postorderTraversal(struct TreeNode* root, int* returnSize)
 {
    stack<TreeNode*> my_stack;
    vector<int>result;

    if (root == nullptr) {
        *returnSize = 0;
        return result;
    }


    my_stack.push(root);
    while(!my_stack.empty())
    {
        TreeNode* temp = my_stack.top();
        my_stack.pop();
        result.push_back(temp->val);
        if(temp->left)
        {
            my_stack.push(temp->left);
        }
        if(temp->right)
        {
            my_stack.push(temp->right);
        }
    }

    reverse(result.begin(),result.end());
    *returnSize = result.size();

    return result;


 }




 void Traversal(struct TreeNode* root, vector<int> &result)
 {
    if(root == nullptr)
    {
        return;
    }
    Traversal(root->left,result);
    Traversal(root->right,result);
    result.push_back(root->val);
    
    
 }


 vector<int> postorderTraversal(struct TreeNode* root, int* returnSize)
 {
    vector<int>result;
    Traversal(root,result);
    reverse(result.begin(),result.end());
    *returnSize = result.size();
    return result;
 }


