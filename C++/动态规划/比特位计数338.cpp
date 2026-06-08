class Solution {
    public:
        vector<int> countBits(int n) {
    
            vector<int> result;
    
            for(int i = 0 ; i <= n ; i++)
            {
                int index = i;
                int count = 0;
                while(index > 0)
                {
                    if((index & 1U) == 1 )
                    {
                        count++;
                    }
                    index >>= 1;
                }
                result.push_back(count);
            }
            return result;
        }
    };



    class Solution {
        public:
            vector<int> countBits(int n) {
                // 初始化大小为 n + 1 的数组，默认值全为 0
                vector<int> result(n + 1, 0);
                
                for (int i = 1; i <= n; i++) {
                    // 状态转移方程：
                    // i >> 1 已经计算过，直接查表获取它的 1 的个数
                    // i & 1 判断最低位是否为 1（奇数加 1，偶数加 0）
                    result[i] = result[i >> 1] + (i & 1);
                }
                
                return result;
            }
        };


        class Solution {
            public:
                vector<int> countBits(int n) {
                    vector<int> result(n + 1, 0);
                    
                    for (int i = 1; i <= n; i++) {
                        // 状态转移方程：
                        // i & (i - 1) 能够消去 i 二进制最右边的 1 并且结果一定小于 i
                        // 因此直接通过 result[i & (i - 1)] 获取消去 1 后的个数，在此基础上加 1
                        result[i] = result[i & (i - 1)] + 1;
                    }
                    
                    return result;
                }
            };