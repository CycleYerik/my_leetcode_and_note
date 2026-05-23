class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> my_hash;
            int result = 0;
            int left = 0;
            for(int i = 0 ; i < s.size(); i++)
            {   
                if(my_hash.find(s[i]) != my_hash.end())
                {
                    int last_position = my_hash[s[i]];
                    if(last_position >= left)
                    {
                        left = last_position +1;
                    }
                }
                my_hash[s[i]] = i;
                result = max(result, i - left +1);
            }
            return result;
        }
    };