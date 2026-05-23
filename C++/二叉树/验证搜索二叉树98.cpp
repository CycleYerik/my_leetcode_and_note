class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return is_valid(root,LONG_MIN,LONG_MAX);
    
        }
    
        bool is_valid(TreeNode* root, long low, long up)
        {
            if(!root)
            {
                return true;
            }
            if(root->val <= low || root->val >= up)
            {
                return false;
            }
            
            return is_valid(root->left,low,root->val) && is_valid(root->right,root->val,up);
            
        }
    
    
    };



    class Solution {
        public:
            bool isValidBST(TreeNode* root) {
                stack<TreeNode*> stack;
                long long inorder = (long long)INT_MIN - 1;
        
                while (!stack.empty() || root != nullptr) {
                    while (root != nullptr) {
                        stack.push(root);
                        root = root -> left;
                    }
                    root = stack.top();
                    stack.pop();
                    // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
                    if (root -> val <= inorder) {
                        return false;
                    }
                    inorder = root -> val;
                    root = root -> right;
                }
                return true;
            }
        };
        
