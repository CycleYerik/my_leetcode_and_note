class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int size = nums.size();
            int result = 0;
            int sum = 0;
            unordered_map<int ,int> mymap;
    
            mymap[0] = 1;
            for(int i = 0 ; i < size ; i++)
            {
                sum += nums[i];
    
                if(mymap.count(sum -k))
                {
                    result += mymap[sum -k];
                }
    
                mymap[sum]++;
            }
    
            return result;
            
        }
    };