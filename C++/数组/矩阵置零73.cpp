// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

// 用两个bool储存
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
    
            int row_size = matrix.size();
            int col_size = matrix[0].size();
    
            // 先用首行首列作为记录
    
            int is_row_zero = 0, is_col_zero = 0;
            for(int i = 0 ; i < row_size; i++)
            {
                if(matrix[i][0] == 0)
                {
                    is_col_zero = 1;
                    break;
                }
            }
            for(int i = 0 ; i < col_size; i++)
            {
                if(matrix[0][i] == 0)
                {
                    is_row_zero = 1;
                    break;
                }
            }
    
            //用首行首列标记
            for(int i = 1 ; i < row_size ; i++)
            {
                for(int j = 1; j < col_size; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
    
            for(int i = 1 ; i < row_size ; i++)
            {
                for(int j = 1; j < col_size; j++)
                {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            if(is_row_zero == 1)
            {
                for(int i = 0 ; i < col_size ; i++)
                {
                    matrix[0][i] = 0;
                }
            }
            if(is_col_zero == 1)
            {
                for(int i = 0 ; i < row_size ; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
     };


// 原始：m+n的空间复杂度
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> hang, lie;
        for(int i = 0; i < matrix.size(); i ++)
        {
            for(int j = 0 ; j < matrix[i].size(); j ++)
            {
                if(matrix[i][j] == 0)
                {
                    hang.push_back(i);
                    lie.push_back(j);
                }
            }
        }
        for(int i = 0; i < matrix.size(); i ++)
        {
            for(int j = 0 ; j < matrix[i].size(); j ++)
            {
                if(find(hang.begin(),hang.end(),i) != hang.end() || find(lie.begin(),lie.end(),j) != lie.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// 优化： o(1),直接用两个bool变量来储存首行和首列是否置零，然后遍历除首行和首列外的数组，用首行和首列是否为零来表示对应的列和行是否要置零。
class Solution {
    public void setZeroes(int[][] matrix) {
        int rowLen=matrix.length;//数组的行数
        int columnLen=matrix[0].length;//数组的列
        List<Integer> rowList = new ArrayList<>();
        List<Integer> columList = new ArrayList<>();
        for(int i=0;i<rowLen;i++){
            for(int j=0;j<columnLen;j++){
                if(matrix[i][j]==0){
                   if(!rowList.contains(i)){
                       rowList.add(i);
                   }
                   if(!columList.contains(j)){
                       columList.add(j);
                   }
                }
            }
        }
        //对行进行置0
        for(int i=0;i<rowList.size();i++){
            for(int j=0;j<columnLen;j++){
                matrix[rowList.get(i).intValue()][j]=0;
            }
        }
        //对列进行置0
        for(int i=0;i<rowLen;i++){
            for(int j=0;j<columList.size();j++){
                matrix[i][columList.get(j).intValue()]=0;
            }
        }
    }
}