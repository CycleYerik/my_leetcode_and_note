
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

    int get_height(TreeNode* node)
    {
        if(node == NULL)
        {
            return 0;
        }

        int leftheight = get_height(node->left);
        if(leftheight == -1)
        {
            return -1;
        }
        int rightheight = get_height(node->right);
        if(rightheight == -1)
        {
            return -1;
        }

        if(abs(rightheight - leftheight ) >1)
        {
            return -1;
        }
        else 
        {
            return max(rightheight,leftheight) +1;
        }


    }


    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        int height = get_height(root);
        if(height == -1)
        {
            return false;
        }
        else
        {
            return height;
        }
    }
};