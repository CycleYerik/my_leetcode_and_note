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
        bool isSymmetric(TreeNode* root) {
            return check(root->left,root->right);
    
        }
    
        bool check(TreeNode* L, TreeNode* R)
        {
            if(!L && !R)
            {
                return true;
            }
            if(!L || !R)
            {
                return false;
            }
            return (L->val == R->val) && (check(L->right,R->left)) && (check(L->left, R->right));
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
        bool isSymmetric(TreeNode* root) {
            return check(root);
    
        }
    
        bool check(TreeNode* root)
        {
            queue<TreeNode*> myqueue;
    
            myqueue.push(root->left);
            myqueue.push(root->right);
    
            while(!myqueue.empty())
            {
                TreeNode* L = myqueue.front();
                myqueue.pop();
                TreeNode* R = myqueue.front();
                myqueue.pop();
    
                if(!L && !R)
                {
                    continue;
                }
                if(!L || !R || L->val != R->val)
                {
                    return false;
                }
    
                myqueue.push(L->right);
                myqueue.push(R->left);
                myqueue.push(L->left);
                myqueue.push(R->right);
            }
            return true;
        }
    };