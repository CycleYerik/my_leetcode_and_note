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
        void flatten(TreeNode* root) {
            stack<TreeNode*> mystack;
            if(!root)
            {
                return;
            }
            mystack.push(root);
    
            while(!mystack.empty())
            {
                TreeNode* temp = mystack.top();
                mystack.pop();
                if(temp->right)
                {
                    mystack.push(temp->right);
                }
                if(temp->left)
                {
                    mystack.push(temp->left);
                }
                temp->left = NULL;
                temp->right = mystack.empty() ? nullptr : mystack.top();
    
            }
    
            
        }
    };


    class Solution {
        public:
            void flatten(TreeNode* root) {
                TreeNode *curr = root;
                while (curr != nullptr) {
                    if (curr->left != nullptr) {
                        auto next = curr->left;
                        auto predecessor = next;
                        while (predecessor->right != nullptr) {
                            predecessor = predecessor->right;
                        }
                        predecessor->right = curr->right;
                        curr->left = nullptr;
                        curr->right = next;
                    }
                    curr = curr->right;
                }
            }
        };
        
