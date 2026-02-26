class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size() == 0)
            {
                return 0;
            }
            sort(nums.begin(),nums.end());
            int result = 1;
            int size = nums.size();
    
            int is_continue = 1;
            int last = nums[0];
            int temp_max = 1;
    
            for(int i = 1 ; i < size ; i++)
            {
                
                if(nums[i] == last +1)
                {
                    temp_max++;
                    if(result < temp_max)
                    {
                        result = temp_max;
                    }
                }
                else if(nums[i] == last)
                {
    
                }
                else
                {
                    temp_max = 1;
                    is_continue = 1;
                }
                last = nums[i];
            }
            return result;
    
        }
    };


    class Solution {
        public:
            int longestConsecutive(vector<int>& nums) {
                if(nums.size() == 0)
                {
                    return 0;
                }
                int result = 1;
                unordered_set<int> hashset(nums.begin(), nums.end());  // 使用set自动去重
                
                // 遍历每个数字，只从序列起点开始查找
                for(int num : hashset)
                {
                    // 如果前一个数字存在，说明当前数字不是序列起点，跳过
                    if(hashset.find(num - 1) != hashset.end())  
                    {
                        continue;
                    }
                    
                    // 从起点开始向右查找连续序列
                    int index = num + 1;
                    int temp_result = 1;
                    while(hashset.find(index) != hashset.end())
                    {
                        temp_result++;
                        index++;
                    }
                    if(temp_result > result)
                    {
                        result = temp_result;
                    }
                } 
                return result;
        
            }
        };