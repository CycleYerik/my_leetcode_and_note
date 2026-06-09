class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int count = 0;
            int n = nums.size();
    
            for(int i = 0 ; i < nums.size() ; i++)
            {
                count += nums[i];
            }
            return (n*(n+1) /2) - count;
        }
    };


    class Solution {
        public:
            int missingNumber(vector<int>& nums) {
                int res = 0;
                int n = nums.size();
                for (int i = 0; i < n; i++) {
                    res ^= nums[i];
                }
                for (int i = 0; i <= n; i++) {
                    res ^= i;
                }
                return res;
            }
        };
        