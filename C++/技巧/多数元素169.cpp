class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int,int> count_map;
            int n = nums.size();
    
            for(int i = 0 ; i < n ; i++)
            {
                if(count_map.find(nums[i]) != count_map.end())
                {
                    count_map[nums[i]] = 1;
                } 
                else
                {
                    count_map[nums[i]]++;
                    if(count_map[nums[i]] > n/2)
                    {
                        return nums[i];
                    }
                }
            }
    
            return 0;
        }
    };