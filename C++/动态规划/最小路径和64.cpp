class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            
            vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),INT_MAX));
    
            int m = grid.size();
            int n = grid[0].size();
    
            dp[0][0] = grid[0][0];
            for(int i = 1 ; i < m ; i++)
            {
                dp[i][0] = dp[i-1][0] + grid[i][0];
            }
            for(int i = 1 ; i < n ; i++)
            {
                dp[0][i] = dp[0][i-1] + grid[0][i];
            }
    
            for(int i = 1 ; i < m ; i++)
            {
                for(int j = 1 ; j < n ; j++)
                {
                    dp[i][j] = (grid[i][j] + min(dp[i-1][j],dp[i][j-1]));
                }
            }
            return dp[m-1][n-1];
        }
    };

    class Solution {
        public:
            int minPathSum(vector<vector<int>>& grid) {
                int m = grid.size();
                int n = grid[0].size();
                vector<int> dp(n);
        
                dp[0] = grid[0][0];
                for (int j = 1; j < n; ++j) {
                    dp[j] = dp[j - 1] + grid[0][j];
                }
        
                for (int i = 1; i < m; ++i) {
                    dp[0] += grid[i][0];
                    for (int j = 1; j < n; ++j) {
                        // dp[j] 仍是上一行同列；dp[j-1] 已是当前行左侧
                        dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
                    }
                }
        
                return dp[n - 1];
            }
        };
        