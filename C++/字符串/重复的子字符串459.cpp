class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            
            bool is_able = false;
            for(int i = 1 ;i*2 <= s.size(); i++)
            {
                if(s.size() % i == 0)
                {
                    is_able = true;
                    for(int j = i ; j < s.size(); j++)
                    {
                        if(s[j] != s[j-i])
                        {
                            is_able = false;
                            break;
                        }
                    }
                    if(is_able == true)
                    {
                        return is_able;
                    }
                }
            }
            return false;
        }
    };
    