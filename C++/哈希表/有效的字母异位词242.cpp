class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i = 0; i < s.size(); i ++)
        {
            record[s[i] - 'a'] ++;
        } 
        for(int i = 0; i < t.size(); i ++)
        {
            record[t[i] - 'a'] --;
        } 
        for(int i = 0; i< 26; i ++)
        {
            if(record[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 用数组实现类似哈希表的功能，记录每个字母出现的次数，最后判断是否相等