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
    int maxDepth(TreeNode* root) {
        
        int maxdepth = 0;

        queue<TreeNode*> my_queue;
        if(root == NULL)
        {
            return maxdepth;
        }
        my_queue.push(root);
        while(my_queue.empty() != 1)
        {
            maxdepth++;
            int size = my_queue.size();
            for(int i = 0; i < size ; i++)
            {
                TreeNode* temp = my_queue.front();
                my_queue.pop();
                if(temp->left)
                {
                    my_queue.push(temp->left);
                }
                if(temp->right)
                {
                    my_queue.push(temp->right);
                }
                
            }
        }
        return maxdepth;
    }
};