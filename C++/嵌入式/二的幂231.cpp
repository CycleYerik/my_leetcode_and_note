class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if(n == 1)
            {
                return true;
            }
            else if(n == 0)
            {
                return false;
            }
            else if(n < 0)
            {
                return false;
            }
            while(n > 1)
            {
                if(n % 2 != 0)
                {
                    return false;
                }
                else 
                {
                    n /= 2;
                }
            }
            return true;
        }
    };


    class Solution {
        public:
            bool isPowerOfTwo(int n) {
                if(n > 0 &&( (n & -n) == n)) //这个操作是取出n的二进制表示中最低位的1
                {
                    return true;
                }
                else 
                {
                    return false;
                }
            }
        };