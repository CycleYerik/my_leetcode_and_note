// 给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其总和大于等于 target 的长度最小的 子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。


// 暴力 O(n^2)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;
        for(int i = 0; i < nums.size(); i ++)
        {
            int sum = 0;
            for(int j = i ; j <nums.size(); j ++)
            {
                sum += nums[j];
                if(sum >= target)
                {
                    if(j-i+1 < length)
                    {
                        length = j-i+1;
                    }
                    break;
                }
            }
        }

        return length== INT_MAX ? 0: length;
    }
};

// 双指针
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;
        for(; right <nums.size(); right++)
        {
            sum += nums[right];
            while(sum >= target)
            {
                sum -= nums[left];
                length = (right - left+1) < length?(right - left+1):length ;
                left ++;
            }
        }
        return length== INT_MAX ? 0: length;
    }
};
