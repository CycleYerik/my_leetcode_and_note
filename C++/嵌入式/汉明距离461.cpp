class Solution {
    public:
        int hammingDistance(int x, int y) {
            int x_count = x;
            int y_count = y;
    
            int result = 0;
            for(int i = 0 ; i < 32 ;i++)
            {
                bool is_count = (x_count & 1U) ^ (y_count & 1U);
                if(is_count)
                {
                    result++;
                }
                x_count = x_count>>1;
                y_count = y_count>>1;
    
            }
            return result;
        }
    };

    class Solution {
        public:
            int hammingDistance(int x, int y) {
                int s = x ^ y, ret = 0;
                while (s) {
                    ret += s & 1;
                    s >>= 1;
                }
                return ret;
            }
        };


    class Solution {
        public:
            int hammingDistance(int x, int y) {
                unsigned int n = x ^ y; // 使用 unsigned 避免负数位移的未定义行为
                int count = 0;
                while (n > 0) {
                    n &= (n - 1); // 核心：这行代码会消去二进制中最右边的那个 1
                    count++;
                }
                return count;
            }
        };