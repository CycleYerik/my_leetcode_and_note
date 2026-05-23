class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            //先取长度，然后移动窗口，每个窗口内对字符串排序，然后和目标对比，
    
            vector<int> result;
    
            int windows_size = p.size();
            int string_size = s.size();
    
            int pointer = 0;
            string target = p;
            sort(target.begin(),target.end());
    
            for(; pointer + windows_size <= string_size; pointer++)
            {
                string temp = s.substr(pointer,windows_size);
                sort(temp.begin(),temp.end());
                if (temp == target)
                {
                    result.push_back(pointer);
                }
            }
            return result;
    
        }
    };


    class Solution {
        public:
            vector<int> findAnagrams(string s, string p) {
                //先取长度，
                int windows_size = p.size();
                int string_size = s.size();
        
                if(string_size < windows_size)
                {
                    return vector<int>();
                }
        
                vector<int> result;
        
                vector<int>pcount(26);
                vector<int>scount(26);
        
                for(const auto c : p)
                {
                    pcount[c-'a']++;
                }
                for(int i = 0 ; i < windows_size ;i ++)
                {
                    scount[s[i] -'a']++;
                }
                if(scount == pcount)
                {
                    result.push_back(0);
                }
        
        
                int pointer = 0;
                for(; pointer + windows_size < string_size; pointer++)
                {
                    scount[s[pointer] -'a']--;
                    pcount[s[pointer+ windows_size] -'a']++;
                    if(scount == pcount)
                    {
                        result.push_back(pointer+1);
                    } 
                }
                return result;
        
            }
        };


    

    // 基于 diff 变量的优化版本（LeetCode 实际使用的版本）
    class Solution {
        public:
            vector<int> findAnagrams(string s, string p) {
                int windows_size = p.size();
                int string_size = s.size();

                if (string_size < windows_size) {
                    return vector<int>();
                }

                vector<int> result;
                vector<int> pcount(26);
                vector<int> scount(26);

                // 统计 p 的字符频率
                for (char c : p) {
                    pcount[c - 'a']++;
                }
                // 初始化第一个窗口的字符频率
                for (int i = 0; i < windows_size; i++) {
                    scount[s[i] - 'a']++;
                }

                // 计算初始 diff：有多少个字符频率不同
                int diff = 0;
                for (int i = 0; i < 26; i++) {
                    if (scount[i] != pcount[i]) {
                        diff++;
                    }
                }
                if (diff == 0) {
                    result.push_back(0);
                }

                // 滑动窗口
                for (int left = 0; left + windows_size < string_size; left++) {
                    int right = left + windows_size;

                    // 移除左边界字符
                    int idxLeft = s[left] - 'a';
                    if (scount[idxLeft] == pcount[idxLeft]) {
                        diff++;
                    }
                    scount[idxLeft]--;
                    if (scount[idxLeft] == pcount[idxLeft]) {
                        diff--;
                    }

                    // 添加右边界字符
                    int idxRight = s[right] - 'a';
                    if (scount[idxRight] == pcount[idxRight]) {
                        diff++;
                    }
                    scount[idxRight]++;
                    if (scount[idxRight] == pcount[idxRight]) {
                        diff--;
                    }

                    if (diff == 0) {
                        result.push_back(left + 1);
                    }
                }

                return result;
            }
        };