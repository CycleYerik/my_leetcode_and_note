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