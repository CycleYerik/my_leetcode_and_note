/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool is_symmetery(TreeNode* left,TreeNode*right)
    {
        if((left == NULL && right != NULL) || (left != NULL && right == NULL))
        {
            return false;
        }
        else if(left == NULL && right == NULL)
        {
            return true;
        }
        else if(left->val != right-> val)
        {
            return false;
        }
        
        bool is_out = is_symmetery(left->left,right->right);
        bool is_in = is_symmetery(left->right,right->left);
        bool result = is_in && is_out;

        return result;

    }


    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return false;
        }
        bool result = is_symmetery(root->left,root->right);
        return result;
    }

    //! 用迭代写的
    bool isSymmetric(TreeNode* root) {
        // if(root == NULL)
        // {
        //     return false;
        // }
        // bool result = is_symmetery(root->left,root->right);
        // return result;
        queue<pair<TreeNode*,TreeNode*>> my_queue;
        bool is_symmetery = true;

        if(root == NULL)
        {
            return false;
        }
        my_queue.push({root->left,root->right});
        
        
        while(my_queue.empty() != 1)
        {
            pair<TreeNode*,TreeNode*> temp = my_queue.front();
            my_queue.pop();
            if(temp.first == NULL && temp.second != NULL)
            {
                is_symmetery = false;
                break;
            }
            else if(temp.first != NULL && temp.second == NULL)
            {
                is_symmetery = false;
                break;
            }
            else if(temp.first == NULL && temp.second == NULL)
            {
                continue;
            }
            else if(temp.first->val != temp.second->val)
            {
                is_symmetery = false;
                break;
            }
            else if(temp.first->val == temp.second->val)
            {
                pair<TreeNode*,TreeNode*> temp1 = {temp.first->left,temp.second->right};
                pair<TreeNode*,TreeNode*> temp2 = {temp.first->right,temp.second->left};
                my_queue.push(temp1);
                my_queue.push(temp2);
            }
        }
        return is_symmetery;
        

    }
};
