class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
    
            // 按照行查找
            int left = 0, right = m-1;
            while(left <= right)
            {
                int mid = (right - left)/2 + left;
    
                if(target > matrix[mid][0])
                {
                    left = mid +1;
                }
                else if(target < matrix[mid][0])
                {
                    right = mid -1;
                }
                else
                {
                    return true;
                }
            }
            if(right < 0)
            {
                return false;
            }
    
            int col = left -1 ;
    
            left = 0, right = n-1;
            while(left <= right)
            {
                int mid = (right - left)/2 + left;
    
                if(target > matrix[col][mid])
                {
                    left = mid +1;
                }
                else if(target < matrix[col][mid])
                {
                    right = mid -1;
                }
                else
                {
                    return true;
                }
            }
            return false;
    
            // 按照列查找
    
    
        }
    };