
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


//dfs写法 26.07.06
class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            
            vector<vector<bool>> is_visited(grid.size(), vector<bool>(grid[0].size() , false));
    
            vector<pair<int,int>> direction = {{1,0} , {-1,0} , {0,1} , {0,-1}};
    
            int count = 0;
    
            for(int i = 0; i < grid.size() ; i++)
            {
                for(int j = 0 ; j < grid[0].size() ; j++)
                {
                    if(grid[i][j] == '1' && is_visited[i][j] == false)
                    {
                        dfs(grid,is_visited,direction,i,j);
                        count ++;
                    }
                }
            }
            return count;
    
    
    
        }
    
        void dfs(vector<vector<char>>& grid, vector<vector<bool>> &is_visited, vector<pair<int,int>> &direction, int row, int col )
        {
            is_visited[row][col] = true;
            for(int i = 0 ; i < 4 ; i++)
            {
                auto temp = direction[i];
                int temp_row = row + temp.first;   
                int temp_col = col + temp.second;
                if(temp_row >= 0 && temp_row < grid.size() && temp_col >= 0 && temp_col < grid[0].size() && grid[temp_row][temp_col] == '1' && is_visited[temp_row][temp_col] == false)
                {
                    dfs(grid,is_visited,direction,temp_row,temp_col);
                }
            }
        }
    };


// 迭代 DFS 写法（stack）26.07.06
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !is_visited[i][j]) {
                    dfs_iter(grid, is_visited, direction, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs_iter(vector<vector<char>>& grid,
                  vector<vector<bool>>& is_visited,
                  vector<pair<int, int>>& direction,
                  int start_row,
                  int start_col) {
        stack<pair<int, int>> stk;
        stk.push({start_row, start_col});
        is_visited[start_row][start_col] = true;

        while (!stk.empty()) {
            auto [row, col] = stk.top();
            stk.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + direction[i].first;
                int nc = col + direction[i].second;
                if (nr >= 0 && nr < (int)grid.size() &&
                    nc >= 0 && nc < (int)grid[0].size() &&
                    grid[nr][nc] == '1' && !is_visited[nr][nc]) {
                    is_visited[nr][nc] = true;
                    stk.push({nr, nc});
                }
            }
        }
    }
};