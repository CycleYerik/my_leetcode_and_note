class Solution {
    public:
        int mySqrt(int x) {
            int left = 0, right = x;
            int mid = 0;
            int result = -1;
    
    
            while(left <= right)
            {
                mid = left + (right - left)/2;
                long long mid_dot = (long long)mid * mid;
                if( mid_dot> (long long)x)
                {
                    right = mid-1;
                }
                else
                {
                    result = mid;
                    left = mid +1 ;
                }
            }
            return result;
    
        }
    };