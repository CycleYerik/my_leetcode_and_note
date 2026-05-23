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
        int kthSmallest(TreeNode* root, int k) {
            vector<int> value;
    
            stack<TreeNode*> mystack;
            TreeNode* cur = root;
            while(!mystack.empty() || cur != NULL)
            {
                if(cur == NULL)
                {
                    cur = mystack.top();
                    mystack.pop();
                    value.push_back(cur->val);
                    cur = cur->right;
                }
                else
                {
                    mystack.push(cur);
                    cur = cur->left;
                }
            }
            return value[k-1];
        }
    
    
    };
    

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
        int kthSmallest(TreeNode* root, int k) {
            int count = 0;
            stack<TreeNode*> mystack;
            TreeNode* cur = root;
            while(!mystack.empty() || cur != NULL)
            {
                if(cur == NULL)
                {
                    cur = mystack.top();
                    mystack.pop();
                    count ++;
                    if(count == k)
                    {
                        return cur->val;
                    }
                    cur = cur->right;
                }
                else
                {
                    mystack.push(cur);
                    cur = cur->left;
                }
            }
            return root->val;
        }
    
    
    };

    class Solution {
        public:
            int kthSmallest(TreeNode* root, int k) {
                stack<TreeNode *> stack;
                while (root != nullptr || stack.size() > 0) {
                    while (root != nullptr) {
                        stack.push(root);
                        root = root->left;
                    }
                    root = stack.top();
                    stack.pop();
                    --k;
                    if (k == 0) {
                        break;
                    }
                    root = root->right;
                }
                return root->val;
            }
        };
