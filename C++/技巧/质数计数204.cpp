class Solution {
    public:
        int countPrimes(int n) {
            
            if(n <= 2)
            {
                return 0;
            }
            
            vector<int> nums(n+1,1);
            nums[1] = 0;
            nums[2] = 1;
            for(int i = 2; i * i <= n ;i++)
            {
                if(nums[i] == 1)
                {
                    for(int j = i; j*i <= n ;j++)
                    {
                        nums[i*j] = 0;
                    }
                }
            } 
    
            int count = 0;
            for(int k = 1; k < n ; k++)
            {
                if(nums[k] == 1)
                {
                    count++;
                }
            }
            return count;
        }
    };