//! 推论：先排序，剩下的只能是和最后一个区间有重叠，否则直接加入结果集
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if(intervals.size() == 0)
            {
                return {};
            }
            sort(intervals.begin(),intervals.end());

            vector<vector<int>> result;

            result.push_back(intervals[0]);
            for(int i  = 1; i < intervals.size(); i++)
            {
                int temp = result.back()[1];
                if(intervals[i][0] <= temp)
                {
                    result.back()[1] = max(intervals[i][1],result.back()[1]);
                }
                else
                {
                    result.push_back({intervals[i][0],intervals[i][1]});
                }
            }
            return result;
        }
    };

//! 错误思路， 开闭区间的问题没理清楚
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            // 特判：空数组
            if (intervals.empty()) return {};

            // 先按左端点排序
            sort(intervals.begin(), intervals.end(),
                 [](const vector<int> &a, const vector<int> &b) {
                     return a[0] < b[0];
                 });

            vector<vector<int>> ans;
            // 当前正在合并的区间
            int curL = intervals[0][0];
            int curR = intervals[0][1];

            for (size_t i = 1; i < intervals.size(); ++i) {
                int L = intervals[i][0];
                int R = intervals[i][1];

                if (L <= curR) {
                    // 有重叠，更新右端点
                    curR = max(curR, R);
                } else {
                    // 没重叠，先把前一个区间放进答案，然后开启新区间
                    ans.push_back({curL, curR});
                    curL = L;
                    curR = R;
                }
            }

            // 把最后一个正在合并的区间放进去
            ans.push_back({curL, curR});
            return ans;
        }
    };