class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int inf = INT_MAX/2;
        vector<vector<int>> grid(n,vector<int>(n,inf));

        // 初始化图距离
        for (int i = 0; i < n; ++i) {
            grid[i][i] = 0;
        }
        for(int i = 0 ; i < times.size(); i++)
        {
            grid[times[i][0]-1][times[i][1]-1] = times[i][2];
        }

        vector<int> min_dist(n,inf); // 最小距离数组
        min_dist[k-1] = 0; // 目标点距离自己为零

        vector<int> visited(n,0);

        while (true) 
        {
            // x 用于存储当前循环中，未确定最短路径且距离源点最近的节点索引。
            int x = -1;
            // 遍历所有节点，寻找下一个要处理的节点 x(距离源点最近的)
            for (int i = 0; i < n; i++) 
            {
                if (!visited[i] && (x < 0 || min_dist[i] < min_dist[x])) 
                {
                    x = i;
                }
            }

            // 如果 x 仍然是 -1，说明所有节点的最短路径都已确定，或者所有剩余节点都不可到
            if (x < 0) 
            {
                return ranges::max(min_dist);
            }

            // 如果找到的节点 x 的最短延迟仍然是 "无穷大" (INT_MAX / 2)（防止相加溢出）
            if (min_dist[x] == INT_MAX / 2) {
                return -1; // 返回 -1 表示并非所有节点都能收到信号
            }

            //找到了满足要求的点，开始更新
            visited[x] = true;

            
            for (int y = 0; y < n; y++) {

                min_dist[y] = min(min_dist[y], min_dist[x] + grid[x][y]);
            }
        }


    }
};


// 但是
class Solution
{
    
}