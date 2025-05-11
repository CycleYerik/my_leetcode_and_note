/**
 * @brief 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 * 
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i <nums.size()-1; i++ )
        {
            if(nums[i] == 0)
            {
                int is_all_zero = 1;
                for(int j = i+1 ; j <nums.size(); j ++)
                {
                    if(nums[j] != 0)
                    {
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        is_all_zero = 0;
                        break;
                    }
                }
                if(is_all_zero == 1)
                {
                    return;
                }
            }
        }
    }
};