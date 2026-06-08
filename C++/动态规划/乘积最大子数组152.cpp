class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int max_result = nums[0];
    
            vector<int> dp_min(nums.size(), 0);
            vector<int> dp_max(nums.size(), 0);
    
            dp_min[0] = nums[0];
            dp_max[0] = nums[0];
    
            for(int i = 1 ; i < nums.size() ; i++)
            {
                dp_max[i] = max({nums[i], dp_max[i-1] * nums[i], dp_min[i-1] * nums[i]});
                dp_min[i] = min({nums[i], dp_max[i-1] * nums[i], dp_min[i-1] * nums[i]});
                if(dp_max[i] > max_result)
                {
                    max_result = dp_max[i];
                }
            }
            return max_result;
    
        }
    };