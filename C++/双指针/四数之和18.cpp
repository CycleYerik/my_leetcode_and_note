
// 自己手写，注释部分为可以优化的剪枝部分
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size(); i ++)
        {
            // if (nums[i] > target && nums[i] >= 0) {
            // 	break; // 这里使用break，统一通过最后的return返回
            // }
            if(i > 0 && nums[i] == nums[i -1])
            {
                continue;
            }
            for(int j = i+1; j < nums.size(); j ++)
            {
                // if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                //     break;
                // }
                if(j > i+1   && nums[j] == nums[j -1])
                {
                    continue;
                }
                int left = j + 1;
                int right = nums.size()-1;
                while(left < right) // 终止条件
                {
                    if((long) nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right --;
                    }
                    else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left ++;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(right > left && nums[left] == nums[left+1])
                        {
                            left ++;
                        }
                        while(right > left && nums[right] == nums[right-1])
                        {
                            right --;
                        }
                        left ++;
                        right --;
                    }
                }
                

            }
        } 
        return result;
    }
};

