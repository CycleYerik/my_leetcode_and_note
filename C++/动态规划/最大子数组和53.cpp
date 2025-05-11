/**
 * @brief 
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 */



class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max_sum = -10000;        
        for(int i = 0; i < nums.size(); i++) 
        {
            int temp_sum = 0;
            for(int j =i; j < nums.size(); j++) 
            {
                temp_sum += nums[j];
                if(temp_sum > max_sum) 
                {
                    max_sum = temp_sum;
                }
            }
        }
        return max_sum;
    }
};

//! 分析：考虑将连续子数组转变为以nums[i]结尾的最大子序和，这样可以减少一层循环，时间复杂度为O(n)，有类似于动态规划的思想
// 核心的问题是将子序和与当前元素结合
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移方程，在前一个元素结尾的最小子序和加上当前元素和当前元素的大小中取最大值，
            result = max(result, dp[i]);
        }

        return result;
    }
};
