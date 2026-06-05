

//dp做法
class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n+1,n+1);
    
            dp[0] = 0;
    
    
    
            for(int i = 1 ; i <= n ; i++)
            {
                for(int j = 1 ; j*j <= i ; j++)
                {
                    dp[i] = min(dp[i],dp[i-j*j] + 1);
                }
            }
            return dp[n];
    
        }
    };


    #include <vector>
    #include <queue>
    #include <iostream>
    
    using namespace std;
    
    class Solution {
    public:
        int numSquares(int n) {
            // 队列中存放的是：pair<当前数字, 当前已经走过的步数/层数>
            queue<pair<int, int>> q;
            q.push({n, 0});
    
            // 记录哪些数字已经被访问过
            vector<bool> visited(n + 1, false);
            visited[n] = true;
    
            while (!q.empty()) {
                auto [curr, step] = q.front();
                q.pop();
    
                // 尝试减去所有可能的完全平方数
                for (int i = 1; i * i <= curr; i++) {
                    int next_num = curr - i * i;
    
                    // 如果减完直接到了 0，说明找到了最短路径
                    if (next_num == 0) {
                        return step + 1;
                    }
    
                    // 如果这个数字没被访问过，放入队列继续向下搜索
                    if (!visited[next_num]) {
                        visited[next_num] = true;
                        q.push({next_num, step + 1});
                    }
                }
            }
            return n; // 兜底返回
        }
    };