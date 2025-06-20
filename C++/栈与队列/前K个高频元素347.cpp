#include <vector>
#include <unordered_map>
#include <queue>
#include <utility> // for std::pair
using namespace std;


//! 自己实现最小堆的方法
class my_comparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
};
// 自定义比较函数，实现小顶堆


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>result(k);
        unordered_map<int,int> my_result_map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, my_comparison> my_priority_queue;// 通过自定义运算实现了小顶堆
        for(int i = 0 ; i <nums.size(); i ++) // 先将元素都存进map里，
        {
            my_result_map[nums[i]]++;
        }

        // 进行频率的统计
        for(unordered_map<int,int>::iterator it = my_result_map.begin(); it != my_result_map.end(); it ++)
        {
            my_priority_queue.push(*it);
            if(my_priority_queue.size() >k)
            {
                my_priority_queue.pop();
            }
        }

        // 将优先级队列中的值返回
        for(int i = k-1; i >=0 ; i--)
        {
            result[i] = my_priority_queue.top().first;
            my_priority_queue.pop();
        }

        return result;
    }
};


////! 自己实现快速排序的方法
class Solution
{
public:
    void qsort(vector<pair<int, int>> &v, int start, int end, vector<int> &result, int k)
    {
        if (start >= end)
        {
            // 递归基础 case，只有一个元素时，直接补进 result（如果还没填够）
            if (start < k)
            {
                for (int i = 0; i <= start && i < k; i++)
                { // 防止 result 越界
                    result[i] = v[i].first;
                }
            }
            return;
        }

        int i = start - 1, j = end + 1, mid = v[(start + end) / 2].second;

        while (i < j)
        {
            do
            {
                i++;
            } while (v[i].second > mid); // 从大到小排序

            do
            {
                j--;
            } while (v[j].second < mid); // 从大到小排序

            if (i < j)
            {
                swap(v[i], v[j]);
            }
        }

        qsort(v, start, j, result, k);
        if (j < k - 1)
        {
            qsort(v, j + 1, end, result, k);
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                result[i] = v[i].first;
            }
        }
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result(k);
        unordered_map<int, int> my_result_map;
        vector<pair<int, int>> my_vector;

        for (int i = 0; i < nums.size(); i++)
        {
            my_result_map[nums[i]]++;
        }

        for (auto it = my_result_map.begin(); it != my_result_map.end(); it++)
        {
            my_vector.push_back(make_pair(it->first, it->second));
        }

        qsort(my_vector, 0, my_vector.size() - 1, result, k);

        return result;
    }
};
