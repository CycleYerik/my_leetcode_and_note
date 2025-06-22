class Solution {
public:



    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size() <= 1)
        {
            return 0;
        }
        vector<int> dp(prices.size(),0);
        dp[0] = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i] = min(dp[i-1],prices[i]);
            if(prices[i] -dp[i]  > profit)
            {
                profit = prices[i] -dp[i];
            }
        }
        return profit;


    }
};


//官方

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};
