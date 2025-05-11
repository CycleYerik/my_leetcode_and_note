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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> my_node_stack;
        TreeNode *store_node = root;
        TreeNode* temp_node = root;
        if(root == NULL)
        {
            return NULL;
        }
        my_node_stack.push(root);
        while(my_node_stack.empty() != 1)
        {
            temp_node = my_node_stack.top();
            my_node_stack.pop();
            if(temp_node->left != NULL || temp_node->right != NULL)
            {
                swap(temp_node->left,temp_node->right);
            }
            if(temp_node->left != NULL)
            {
                my_node_stack.push(temp_node->left);
            }
            if(temp_node->right != NULL)
            {
                my_node_stack.push(temp_node->right);
            }
        }
        return store_node;
    }
};