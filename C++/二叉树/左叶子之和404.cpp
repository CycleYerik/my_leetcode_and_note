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
    int result = 0;
    void get_sum_left(TreeNode* node)
    {
        
        if(node->left)
        {
            get_sum_left(node->left);
        }
        
        if(node->left && !node->left->left && !node->left->right)
        {
            result += node->left->val;
        }

        if(node->right)
        {
            get_sum_left(node->right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        get_sum_left(root);
        return result;
    }
};