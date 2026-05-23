class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int size = nums.size();
            vector<int> result(size);
            vector<int> left_sum(size);
            vector<int> right_sum(size);
            left_sum[0] = 1;
            right_sum[size-1] = 1;
            for(int i = 1 ; i < size ; i++)
            {
                left_sum[i] = left_sum[i-1] * nums[i-1];
            }
            for(int i = size -2 ; i >= 0 ; i--)
            {
                right_sum[i] = right_sum[i+1] * nums[i+1];
            }
            for(int i = 0 ; i < size ; i++)
            {
                result[i] = left_sum[i] * right_sum[i];
            }
            return result;
        }
    };