class Solution {
public:
    int fib(int n) {

        if(n <= 1)
        {
            return n;
        }
        vector<int> dp(n+1); //dp数组

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];


    }
};


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1); // 爬到第i层楼梯有多少个方法
        if(n <= 1)
        {
            return n;
        }
        dp[1] = 1 ;
        dp[2] = 2;
        for(int i = 3; i <= n ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        } 
        return dp[n];

    }
};