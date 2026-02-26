class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL)
            {
                return 0;
            }
            int result = 0;
    
            queue<TreeNode*> myqueue;
            int count = 1;
            int new_count = 0;
            myqueue.push(root);
    
            while(!myqueue.empty())
            {
                new_count = 0;
                for(int i = 0 ; i < count ; i ++)
                {
                    TreeNode* cur = myqueue.front();
                    myqueue.pop();
                    if(cur->left)
                    {
                        myqueue.push(cur->left);
                        new_count++;
                    }
                    if(cur->right)
                    {
                        myqueue.push(cur->right);
                        new_count++;
                    }
    
                }
                count = new_count;
                result++;
            }
            return result;
        }
    };


class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (root == nullptr) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };
        
