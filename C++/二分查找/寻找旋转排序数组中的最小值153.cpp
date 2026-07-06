class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0 , right = nums.size()-1;
            int mid = 0;
    
            int result = 6000;
    
            while(left <= right)
            {
                mid = left + (right - left)/2;
                if(nums[mid] <= nums[right]) //右边有序
                {
                    right = mid -1;
                    if(nums[mid] < result)
                    {
                        result = nums[mid];
                    }
                }
                else
                {
                    left = mid +1;
                    if(nums[left] < result)
                    {
                        result = nums[left];
                    }
                }
            }   
            return result;
        }
    };



    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                // 最小值在 [left, mid]
                right = mid;
            } else {
                // 最小值在 [mid+1, right]
                left = mid + 1;
            }
        }
        return nums[left];
    }