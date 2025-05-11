class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        int result = 0;
        
        if( n <= 2)
        {
            return 1;
        }
        dp[2] = 1;

        for(int i = 3; i <= n ; i++)
        {
            for(int j =  1 ; j < i-1 ; j ++)
            {
                dp[i] = max(dp[i],max(dp[i-j] * j , (i-j) * j )); // 为什么和dp本身比较，否则就会在遍历中可能丢弃了大值，因为dp[i]要经历多个j
            }
        }

        return dp[n];
    }
};