//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        int middle = 0;
        while(left <= right)
        {
            middle = left + (right - left)/2;
            if(nums[middle] > target)
            {
                right = middle -1;
            }
            else if (nums[middle] < target)
            {
                left = middle +1;
            }
            else if (nums[middle] == target)
            {
                return middle;
            }
        }
        return -1;
    }
};

// 二分查找