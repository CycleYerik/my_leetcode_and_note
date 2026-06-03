
// BFS 写法
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; 
    int result = 0;
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        queue<pair<int,int>> my_queue;
        my_queue.push({x,y});
        visited[x][y] =1;
        while(my_queue.empty() != 1)
        {
            pair<int,int> now_position = my_queue.front();
            my_queue.pop();
            int now_x = now_position.first;
            int now_y = now_position.second;
            for(int i = 0 ; i < 4 ; i++ )
            {
                now_x = now_position.first + dir[i][0];
                now_y = now_position.second + dir[i][1];
                if(now_x < grid.size() && now_x >= 0 && now_y < grid[0].size()  && now_y >= 0 && visited[now_x][now_y] != 1 && grid[now_x][now_y] == '1')
                {
                    visited[now_x][now_y] = 1;
                    my_queue.push({now_x,now_y});
                }
                else
                {
                    continue;
                }
            }
        }
        result++;
    }

    int numIslands(vector<vector<char>>& grid) {
        result = 0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),0));
        for(int i = 0 ; i < grid.size(); i ++)
        {
            for(int j = 0 ; j < grid[0].size(); j++)
            {
                if(visited[i][j] != 1 && grid[i][j] == '1')
                {
                    bfs(grid,visited,i,j);
                }
            }
        }
        return result;
    }
};

//dfs写法

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; 
    int result = 0;
    queue<pair<int,int>> my_queue;

    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int x,int y)
    {
        visited[x][y] = 1;
        for(int i = 0 ;i < 4 ; i++)
        {
            int x_now = x+dir[i][0];
            int y_now = y + dir[i][1];
            if(x_now >= 0 && x_now < grid.size() && y_now >= 0 && y_now < grid[0].size() && grid[x_now][y_now] == '1' && visited[x_now][y_now] != 1 )
            {
                dfs(grid,visited,x_now,y_now);

            }
        }
        return ;
        
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),0));

        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ;  j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && visited[i][j] != 1)
                {
                    dfs(grid,visited,i,j);
                    result++;
                }
            }
        }
        return result;
    }
};