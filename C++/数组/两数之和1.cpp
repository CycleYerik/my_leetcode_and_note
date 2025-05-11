//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sequence;
        for(int i = 0; i < nums.size(); i ++)
        {
            for(int j = i+1; j < nums.size(); j ++)
            {
                if(nums[i]+nums[j] == target)
                {
                    sequence.push_back(i);
                    sequence.push_back(j);
                    
                }
            }
        }
        return sequence;
    }
};

// 使用一个哈希表（HashMap）来存储数组元素及其对应的索引。 遍历数组，对于每个元素 nums[i]，计算 complement = target - nums[i]。 检查哈希表中是否存在 complement： 如果存在，说明找到了两个元素的和等于 target，返回它们的索引。 如果不存在，将 nums[i] 及其索引 i 存储到哈希表中
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); i ++)
        {
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};