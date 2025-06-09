#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


//排序，但是时间复杂度为O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return nums.size();
        }
        
        //先排序
        sort(nums.begin(),nums.end());

        int result = 1;  // 初始化为1，因为至少有一个元素
        
        int right = 1;   // 直接从第二个元素开始
        int last = nums[0];
        int temp_result = 1;
        
        while(right < nums.size())
        {
            if(nums[right] == last + 1)
            {
                last = nums[right];
                right++;
                temp_result++;
                result = max(result, temp_result);
            }
            else if(nums[right] == last)
            {
                right++;
            }
            else
            {
                last = nums[right];
                result = max(result, temp_result);
                temp_result = 1;
                right++;
            }
        }
        
        return result;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;  // 使用unordered_set来存储nums的元素，且元素不重复
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {  // 如果num-1不在num_set中，说明num是连续序列的起点，才进入循环进行计算
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) { //使用hash表查找，时间复杂度为O(1),这样时间复杂度为O(n)
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};


int main()
{
    Solution s;
    vector<int> nums = {100,4,200,1,3,2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}
