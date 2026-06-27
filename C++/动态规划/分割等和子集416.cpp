class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto num : nums)
        {
            sum += num;
        }

        if(sum % 2 == 1)
        {
            return false;
        }
        int target = sum/2;


        //转为寻找一个和为target的子序列

        //核心即在前i个数里能不能找到和为j的组合
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1,false));

        dp[0][0] = true;

        for(int i = 1 ; i <= nums.size() ; i++)
        {
            int num = nums[i-1];

            //尝试凑出每一个和
            for(int j = 0 ; j <= target ; j++)
            {
                dp[i][j] = dp[i-1][j];

                if(j >= num)
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j - num];
                }
            }
        }

        return dp[nums.size()][target];

    }
};