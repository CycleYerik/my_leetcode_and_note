class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            if (nums.empty()) return 0;
    
            // tails 数组，也就是我们的“潜力排行榜”
            // tails[i] 表示长度为 i+1 的递增子序列中，最小的末尾元素
            vector<int> tails;
    
            for (int x : nums) {
                // 情况 1：如果 x 比排行榜里最大的数（最后一个）还要大
                // 说明 x 可以接在后面，让最长递增子序列的长度直接 +1
                if (tails.empty() || x > tails.back()) {
                    tails.push_back(x);
                } 
                // 情况 2：如果 x 没那么大
                // 我们就在排行榜里找第一个“大于等于 x”的数，把它替换成 x
                // 这样做是为了缩小该长度序列的末尾值，从而“增加潜力”
                else {
                    // std::lower_bound 会在 tails 中进行二分查找 (O(log n))
                    // 返回一个指向第一个 >= x 的元素的迭代器
                    auto it = std::lower_bound(tails.begin(), tails.end(), x); 
                    *it = x; // 踢掉旧的，换成更小的 x
                }
            }
    
            // 最后，排行榜里有多少个数，最长递增子序列就有多长
            return tails.size();
        }
    };


    class Solution {
        public:
            int lengthOfLIS(vector<int>& nums) {
                vector<int> dp( nums.size(),0);
                dp[0] = 1;
        
                int max_length = 1;
        
                for(int i = 1; i < nums.size() ; i++)
                {
                    int now_length = 1;
                    for(int j = i-1 ; j >= 0 ; j--)
                    {
                        if(nums[i] > nums[j])
                        {
                            now_length = max(now_length, dp[j] + 1);
                        }
                    }
                    dp[i] = now_length;
                    if(now_length > max_length)
                    {
                        max_length = now_length;
                    }
                }
        
                return max_length;
            }
        };