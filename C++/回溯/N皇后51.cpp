class Solution {
public:
    vector<vector<string>> result;
    // 判断能否放置
    int is_valid(vector<string> & chessboard,int row,int col, int n)
    {
        if(chessboard[row][col] == 'Q')
        {
            return 0;
        }
        //检查列
        for(int i = 0 ; i <= row ; i++ )
        {
            if(chessboard[row-i][col] == 'Q')
            {
                return 0;
            }
        }

        //检查斜45 (只用往上检查即可，因为是按行来递归的)
        for(int i = row-1 , j = col-1; i >=0 && j >= 0 ; i--, j--)
        {
            if(chessboard[i][j] == 'Q')
            {
                return 0;
            }
        }

        //检查斜135
        for(int i = row-1 , j = col +1; i >= 0 && j <= n ; i --, j++)
        {
            if(chessboard[i][j] == 'Q')
            {
                return 0;
            }
        }
        return 1;
    }

    // 判断放置（递归）
    void find_place(int n, int row, vector<string>& chessboard)
    {
        if(row == n)
        {
            result.push_back(chessboard);
            return;
        }

        for(int i = 0 ; i < n ; i ++)
        {
            if(is_valid(chessboard,row,i,n))
            {
                chessboard[row][i] = 'Q';
                find_place(n,row+1,chessboard);
                chessboard[row][i] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n,string(n,'.'));
        find_place(n,0,chessboard);
        return result;
    }
};