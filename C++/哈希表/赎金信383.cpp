// 自己用的map
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int>num_exist;
        for (auto a :magazine)
        {
            num_exist[a - 'a']++;
        }
        for( auto b : ransomNote)
        {
            num_exist[b - 'a']--; //! 这里的键值对可能出现问题
        }
        for(int i = 0; i < 26; i ++)
        {
            if(num_exist[i] < 0  )
            {
                return false;
            }
        }
        

        return true;
    }
};

//直接数组实现就行
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};