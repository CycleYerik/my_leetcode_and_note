class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
            unordered_set<int> nums_set(nums1.begin(), nums1.end());
            for (int num : nums2) {
                // 发现nums2的元素 在nums_set里又出现过
                if (nums_set.find(num) != nums_set.end()) {
                    result_set.insert(num);
                }
            }
            return vector<int>(result_set.begin(), result_set.end());
        }
    };

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_map< int,int> my_hash;
            vector<int> result;
            for(const auto number1 : nums1)
            {
                my_hash[number1]++;
            }
            for(const auto number2 : nums2)
            {
                if(my_hash[number2] >0)
                {
                    result.push_back(number2);
                    my_hash[number2]--; //直接这样去重
                }
            }
            
            return result;
        }
    };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_map<int ,int>hash;
        for(const auto &c:nums1)
        {
            hash[c]=1;
        }
        for(const auto &c:nums2)
        {
            --hash[c];
            if(hash[c]==0)
            result.push_back(c);
        }
        return result;
    }
};


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for (auto& num : nums1) {
            set1.insert(num);
        }
        for (auto& num : nums2) {
            set2.insert(num);
        }
        return getIntersection(set1, set2);
    }

    vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
        if (set1.size() > set2.size()) {
            return getIntersection(set2, set1);
        }
        vector<int> intersection;
        for (auto& num : set1) {
            if (set2.count(num)) {
                intersection.push_back(num);
                
            }
        }
        return intersection;
    }
};
