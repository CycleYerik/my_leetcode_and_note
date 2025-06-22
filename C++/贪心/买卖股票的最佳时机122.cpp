
// 动规做法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        // dp数组初始化
        if(prices.size() <= 1)
        {
            return 0;
        }
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        //递推
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]- prices[i]);  
        }
        return dp[prices.size()-1][0];
    }
};