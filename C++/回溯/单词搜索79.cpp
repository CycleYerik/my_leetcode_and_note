class Solution {
    public:
        
    
        bool exist(vector<vector<char>>& board, string word) {
            vector<pair<int,int>> direction = {{1,0}, {0,1}, {-1,0} , {0,-1}};
    
            vector<pair<int,int>> possible_start;
    
            vector<vector<bool>> is_visited(board.size(), vector<bool>(board[0].size(), false));
    
            for(int i = 0 ; i < board.size() ; i++)
            {
                for(int j = 0 ; j < board[0].size() ; j++)
                {
                    if(board[i][j] == word[0])
                    {
                        bool temp_result = back_tracking(board,word,direction,is_visited,0,i,j);
                        if(temp_result)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
    
        }
    
    
        bool back_tracking(vector<vector<char>>& board, string &word, vector<pair<int,int>> &direction,vector<vector<bool>> &is_visited,int index,int row, int col)
        {
            if(board[row][col] == word[index] && is_visited[row][col] == false)
            {
                if(index == word.size() -1 ) //搜索到位了
                {
                    return true;
                }
                else
                {
                    is_visited[row][col] = true;
                    //朝四个方向继续搜索
                    for(int i = 0 ; i < 4 ; i++)
                    {
                        auto temp = direction[i];
                        if(row + temp.first >= 0 && row + temp.first < board.size() && col + temp.second >= 0 && col + temp.second < board[0].size())
                        {
                            row += temp.first;
                            col += temp.second;
                            bool temp_result = back_tracking(board,word,direction,is_visited,index+1,row,col);
                            if(temp_result)
                            {
                                return true;
                            }
                            row -= temp.first;
                            col -= temp.second;
                            
                        }
                    }
                    is_visited[row][col] = false;
                }
                return false;
            }
            else
            {
                return false;
            }
        }
    };