/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //! 自己的简单方法
 class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            vector<TreeNode*> p_path;
            vector<TreeNode*> q_path;
    
            find_way_to_target(root,p,p_path);
            find_way_to_target(root,q,q_path);
    
            int size_p = p_path.size();
            int size_q = q_path.size();
    
            int diff = size_p > size_q ? size_p - size_q : size_q - size_p;
            int index = max(size_p,size_q) - diff -1;
            for(int i = index ; i >= 0 ; i--)
            {
                if(p_path[i]->val == q_path[i]->val)
                {
                    return p_path[i];
                }
            }
            return nullptr;
    
        }
    
    
        bool find_way_to_target(TreeNode* root, TreeNode* target_node, vector<TreeNode*> &path)
        {
            if(!root)
            {
                return false;
            }
            path.push_back(root);
            if(root->val == target_node->val)
            {
                return true;
            }
            else
            {
                bool is_left = find_way_to_target(root->left,target_node,path);
                bool is_right = find_way_to_target(root->right,target_node,path);
                if(!is_left && !is_right)
                {
                    path.pop_back();
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    };

    //! 递归，
    class Solution {
        public:
            TreeNode* ans;
            bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
                if (root == nullptr) return false;
                bool lson = dfs(root->left, p, q);
                bool rson = dfs(root->right, p, q);
                if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
                    ans = root;
                } 
                return lson || rson || (root->val == p->val || root->val == q->val);
            }
            TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                dfs(root, p, q);
                return ans;
            }
        };
        
        作者：力扣官方题解
        链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solutions/238552/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。