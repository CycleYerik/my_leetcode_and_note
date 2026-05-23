class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
    
            if(matrix.empty() || matrix[0].empty())
            {
                return result;
            }
    
            int m = matrix.size();
            int n = matrix[0].size();
    
            int sum = m*n;
    
            int i = 0 , j = 0;
    
    
            vector<pair<int,int>> dir = {
            {0, 1},  // 第一个方向向量 (0, 1)
            {1, 0},  // 第二个方向向量 (1, 0)
            {0, -1}, // 第三个方向向量 (0, -1)
            {-1, 0}  // 第四个方向向量 (-1, 0)
            };
    
            int step_to_go = n;
    
            int now_dir = 0;
            int remaining_m = m; // 剩余行
            int remaining_n = n; // 剩余列
    
    
    
            for(int count = 0; count < sum ; count ++)
            {
                result.push_back(matrix[i][j]);
    
                step_to_go--;
                if(step_to_go == 0)
                {
                    now_dir++;
                    now_dir %= 4;
    
                    if(now_dir == 0 || now_dir == 2)
                    {
                        remaining_n--;
                        step_to_go = remaining_n;
                    }
                    else
                    {
                        remaining_m--;
                        step_to_go = remaining_m;
                    }
                }
                i += dir[now_dir].first;
                j += dir[now_dir].second;
    
            }
    
    
    
    
    
            return result;
        }
    };



    #include <vector> // 引入 vector 容器

    class Solution {
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
            std::vector<int> result; // 存储螺旋遍历结果的 vector
    
            // 检查输入矩阵是否为空
            if (matrix.empty() || matrix[0].empty()) {
                return result; // 如果矩阵为空，直接返回空结果
            }
    
            int m = matrix.size();    // 矩阵的行数
            int n = matrix[0].size(); // 矩阵的列数
    
            // 定义四个边界：上、下、左、右
            int left = 0, right = n - 1;    // 初始左边界和右边界
            int top = 0, bottom = m - 1; // 初始上边界和下边界
    
            // 循环直到左右边界交叉或上下边界交叉
            while (left <= right && top <= bottom) {
                // 1. 从左到右遍历上边界
                for (int j = left; j <= right; ++j) {
                    result.push_back(matrix[top][j]); // 将上边界的元素添加到结果中
                }
                top++; // 上边界向下移动一行
    
                // 2. 从上到下遍历右边界
                for (int i = top; i <= bottom; ++i) {
                    result.push_back(matrix[i][right]); // 将右边界的元素添加到结果中
                }
                right--; // 右边界向左移动一列
    
                // 3. 从右到左遍历下边界 (仅当 top <= bottom 时)
                //    - 如果是单行或单列的矩阵，避免重复遍历
                if (top <= bottom) {
                    for (int j = right; j >= left; --j) {
                        result.push_back(matrix[bottom][j]); // 将下边界的元素添加到结果中
                    }
                    bottom--; // 下边界向上移动一行
                }
    
                // 4. 从下到上遍历左边界 (仅当 left <= right 时)
                //    - 如果是单行或单列的矩阵，避免重复遍历
                if (left <= right) {
                    for (int i = bottom; i >= top; --i) {
                        result.push_back(matrix[i][left]); // 将左边界的元素添加到结果中
                    }
                    left++; // 左边界向右移动一列
                }
            }
    
            return result; // 返回螺旋遍历的结果
        }
    };