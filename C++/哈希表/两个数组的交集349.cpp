class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
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
