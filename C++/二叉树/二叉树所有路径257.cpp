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
    vector<string> result;
    vector<int> path;
    void backtracking(TreeNode* node,vector<int>&path, vector<string>&result)
    {
        path.push_back(node->val);
        
        //到达叶节点
        if(node ->left == NULL && node->right == NULL)
        {
            string string_temp;
            for(int i = 0 ; i < path.size()-1; i++)
            {
                string_temp += to_string(path[i]);
                string_temp += "->";
            }
            string_temp += to_string(path[path.size() -1]);
            result.push_back(string_temp);
            return ;
        }

        if(node->left)
        {
            backtracking(node->left,path,result);
            path.pop_back();
        }

        if(node->right)
        {
            backtracking(node->right,path,result);
            path.pop_back();
        }

    }


    vector<string> binaryTreePaths(TreeNode* root) {
        backtracking(root,path,result);
        return result;
    }
};