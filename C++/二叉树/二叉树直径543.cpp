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
        int result;
        
        int diameterOfBinaryTree(TreeNode* root) {
            result = 1;
            length_of_son(root);
            return result -1;
    
        }
    
        int length_of_son(TreeNode* root)
        {
            if(!root)
            {
                return 0;
            }
    
            int length_L = length_of_son(root->left);
            int length_R = length_of_son(root->right);
    
            int length = max(length_L,length_R) +1;
    
            result = max(result,length_R+length_L+1);
    
            return length;
    
        }
    };