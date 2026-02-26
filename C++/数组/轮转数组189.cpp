class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int size = nums.size();
            vector<int> new_nums(size);
            for(int i = 0 ; i < size ; i++)
            {
                new_nums[(i+k) % size] = nums[i]; 
            }
            nums.assign(new_nums.begin(),new_nums.end());
        }
    };