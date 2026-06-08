class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount+1,amount+1);
    
            dp[0] = 0;
            for(int i = 1 ; i <= amount ; i++)
            {
                for(int j = 0 ; j < coins.size() ; j++)
                {
                    if(coins[j] <= i)
                    {
                        dp[i] = min(dp[i],dp[i - coins[j]] + 1);
                    }
                }
            }
            if(dp[amount] == amount+1)
            {
                return -1;
            }
            else
            {
                return dp[amount];
            }
        }
    };


    class Solution {
        public:
            int coinChange(vector<int>& coins, int amount) {
                
                vector<int> memory(amount+1, -2);
                return count(coins,memory,amount);
        
        
            }
        
            int count(vector<int>&coins, vector<int> &memory,int amount)
            {
                //递归终止条件
                if(amount == 0)
                {
                    return 0;
                }
                else if(amount < 0)
                {
                    return -1;
                }
        
                //如果计算过这个组合
                if(memory[amount] != -2)
                {
                    return memory[amount];
                }
        
                int min_num = INT_MAX;
                
                for(int i = 0 ; i < coins.size() ; i++)
                {
                    if(coins[i] > amount)
                    {
                        continue;
                    }
                    int now_num = amount - coins[i];
                    
                    int temp_result = count(coins,memory,now_num);
        
                    if(temp_result != -1)
                    {
                        min_num = min(min_num, temp_result + 1);
                    }
        
                }
        
                if(min_num == INT_MAX)
                {
                    memory[amount] = -1;
                }
                else
                {
                    memory[amount] = min_num;
                }
        
                return memory[amount];
            }
        };



//ACM模式
// 输入格式：
// 第一行：目标金额 amount
// 第二行：硬币种类数 n
// 第三行：n 个硬币面值（空格分隔）
// 输出：凑成 amount 所需的最少硬币数，无法凑成则输出 -1
// 示例输入：
// 11
// 3
// 1 2 5
// 示例输出：3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};

int main() {
    int amount, n;
    cin >> amount;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    Solution s;
    cout << s.coinChange(coins, amount) << endl;

    return 0;
}





