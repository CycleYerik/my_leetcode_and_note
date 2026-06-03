class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            
            int row_size = grid.size();
            int col_size = grid[0].size();
    
            int fresh = 0;
    
            int direction[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
            int time = 0;
    
            queue<pair<int,int>> myqueue;
            //记录新鲜的总数
            for(int i = 0 ; i < row_size ; i++)
            {
                for(int j = 0 ; j < col_size ; j++)
                {
                    if(grid[i][j] == 2)
                    {
                        myqueue.push({i,j});
                    }
                    else if(grid[i][j] == 1)
                    {
                        fresh++;
                    }
                }
            }
    
        
            //记录当前队列的腐烂总数
            while(!myqueue.empty())
            {
                int queue_size = myqueue.size();
                int is_continue = 0;
                while(queue_size > 0)
                {
                    
                    pair<int,int> temp = myqueue.front();
                    myqueue.pop();
                    //对每个腐烂的，遍历其四个方向，把接下来腐烂的都加入队列，新鲜-1
                    for(int i = 0 ; i < 4 ; i++)
                    {
                        
                        int temp_i = temp.first + direction[i][0];
                        int temp_j = temp.second + direction[i][1];
                        if(temp_i >= 0 && temp_i < row_size && temp_j >= 0 && temp_j < col_size)
                        {
                            if(grid[temp_i][temp_j] == 1)
                            {
                                grid[temp_i][temp_j] = 2;
                                myqueue.push({temp_i,temp_j});
                                fresh--;
                                is_continue = 1;
                            }
                        }
                    }
    
                    queue_size--;
                    
    
                }
                if(is_continue == 1) //如果还有感染的，就继续
                {
                    time++;
                }
            }
            if(fresh != 0)
            {
                return -1;
            }
            else
            {
                return time;
            }
            
            
    
    
    
    
        }
    };