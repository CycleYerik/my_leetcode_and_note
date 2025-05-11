#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int m,n;

    cin >> m>>n;

    vector<int> weight(m,0);
    vector<int> value(m,0);

    //初始化容量与价值
    for(int i = 0 ; i < m ; i++ )
    {
        cin >> weight[i];
    } 
    for(int i = 0 ; i < m ; i++ )
    {
        cin >> value[i];
    } 

    vector<vector<int>> dp(weight.size(),vector<int>(n+1,0)); //!dp数组，每行为只从前i个物品中选择，每列为背包容量为j下的最大价值

    //初始化dp
    for(int i = weight[0]; i <= n; i++) //只装第一个时的价值
    {
        dp[0][i] = value[0];
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(j < weight[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-weight[i]] +value[i],dp[i-1][j]); 
            }
        }
    }

    cout << dp[m-1][n] <<endl;


    return 0;
}