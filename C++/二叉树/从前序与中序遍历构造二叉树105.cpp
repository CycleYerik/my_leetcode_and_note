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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return my_build_tree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        }
    
        TreeNode* my_build_tree(vector<int>& preorder, vector<int>& inorder, int pr_left,int pr_right,int in_left,int in_right)
        {
            //边界条件
            if(pr_left > pr_right || in_left > in_right)
            {
                return nullptr;
            }
    
    
            //创建一个节点，root
            TreeNode* root = new TreeNode(preorder[pr_left]);
    
            //找到根节点对应的位置
            auto it = find(inorder.begin() + in_left,
                           inorder.begin() + in_right + 1, //find是左闭右开的
                           preorder[pr_left]);
            int mid = it - inorder.begin();
            int left_size = mid - in_left;
    
            //递归构建左的preorder里的树
            TreeNode* left_node = my_build_tree(preorder,inorder,pr_left+1,pr_left+left_size,in_left,mid-1);
    
            //递归构建右的preorder里的树
            TreeNode* right_node = my_build_tree(preorder,inorder,pr_left+1+left_size,pr_right,mid+1,in_right);
    
            //root 的left和right连上。
            root->left = left_node;
            root->right = right_node;
    
            //返回root节点
            return root;
    
    
        }
    };


    //! 使用哈希表优化
    class Solution {
        unordered_map<int, int> in_map;
    
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for (int i = 0; i < (int)inorder.size(); ++i) {
                in_map[inorder[i]] = i;
            }
            return my_build_tree(preorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
        }
    
        TreeNode* my_build_tree(vector<int>& preorder, int pr_left, int pr_right,
                                int in_left, int in_right) {
            if (pr_left > pr_right) return nullptr;
    
            int root_val = preorder[pr_left];
            TreeNode* root = new TreeNode(root_val);
    
            int mid = in_map[root_val];
            int left_size = mid - in_left;
    
            root->left = my_build_tree(preorder, pr_left + 1, pr_left + left_size,
                                       in_left, mid - 1);
            root->right = my_build_tree(preorder, pr_left + left_size + 1, pr_right,
                                        mid + 1, in_right);
            return root;
        }
    };