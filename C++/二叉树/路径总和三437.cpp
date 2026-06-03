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
        int pathSum(TreeNode* root, int targetSum) {
            long long sum = 0;
            unordered_map<long long,int>map;
            map[0] = 1;
            int result = 0;
            dfs(root,map,targetSum,sum,result);
            return result;
        }
    
        void dfs(TreeNode* root, unordered_map<long long,int>&map , int target, long long &sum, int &result)
        {
            if(!root)
            {
                return ;
            }
    
            sum += root->val;
            result += map[sum - target];
    
            map[sum]++;
    
            dfs(root->left,map,target,sum,result);
            dfs(root->right,map,target,sum,result);
    
            map[sum]--;
            sum -= root->val;
            
    
        }
    };