class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return buildtree(0,nums.size() -1, nums);
        }
    
    
        TreeNode* buildtree(int left, int right,vector<int>&nums)
        {
            if(left > right)
            {
                return nullptr;
            }
            int mid = (left + right) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = buildtree(left, mid-1,nums);
            node->right = buildtree(mid+1, right,nums);
            return node;
        }
    };