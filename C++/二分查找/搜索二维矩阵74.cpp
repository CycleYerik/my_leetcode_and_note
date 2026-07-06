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

    class Solution {
        public:
            bool searchMatrix(vector<vector<int>>& matrix, int target) {
                
        
        
                //先进行行的二分
                int up = 0, down = matrix.size()-1;
                int mid = 0;
        
                while(up <= down)
                {
                    mid = up + (down - up)/2;
                    if(matrix[mid][0] > target)
                    {
                        down = mid -1;
                    }
                    else if(matrix[mid][0] < target)
                    {
                        up = mid +1;
                    }
                    else
                    {
                        return true;
                    }
        
                }
                int start = up -1;
                if(start < 0)
                {
                    return false;
                }
        
                int left = 0 , right = matrix[0].size()-1;
        
                while(left <= right)
                {
                    mid = left + (right - left)/2;
                    if(matrix[start][mid] < target)
                    {
                        left = mid +1;
                    }
                    else if(matrix[start][mid] > target)
                    {
                        right = mid -1;
                    }
                    else
                    {
                        return true;
                    }
                }
        
                return false;
        
        
        
        
        
                //再进行列的二分
            }
        };