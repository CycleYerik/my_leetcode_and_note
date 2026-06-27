


//错误方法，因为没有考虑到偶数和奇数的问题，这个思路不对
class Solution {
    public:
        string longestPalindrome(string s) {
            
            vector<int>dp (s.size(),0);
    
            if(s.size() == 1)
            {
                return s;
            }
    
            for(int i = 1 ; i < s.size(); i++)
            {
                if(dp[i-1] -1 >= 0 && s[dp[i-1] -1] == s[i])
                {
                    dp[i] = dp[i-1] -1;
                }
                else
                {
                    dp[i] = i;
                }
            }
            
            int max_length = 0;
            int max_index = 0;
            for(int i = 0 ; i < s.size() ; i++)
            {
                if(i - dp[i] +1 > max_length  )
                {
                    max_index = i;
                    max_length = i - dp[i] +1;
                }
            }
    
            return s.substr(max_index - max_length +1, max_length);
    
    
        }
    };



    class Solution {
        public:
            string longestPalindrome(string s) {
                
                
        
                int n = s.size();
                int max_length = 1;
                int begin_index = 0;
        
                vector<vector<bool>> dp( n, vector<bool>(n,false));
        
                if(s.size() == 1)
                {
                    return s;
                }
        
                for(int i = 0; i < n; i ++)
                {
                    dp[i][i] = true;
                }
        
                for(int i = n-1 ; i >= 0 ; i--) // 从后往前遍历，因为需要用到前面的状态
                {
                    for(int j = i+1; j < n ; j++)
                    {
                        if(s[i] == s[j])
                        {
                            if(j-i < 3) //如果就两个，且两个一样，或者就三个，且头尾一样，肯定是
                            {
                                dp[i][j] = true;
                            }
                            else
                            {
                                dp[i][j] = dp[i+1][j-1];
                            }
                        }
        
                        if(dp[i][j] == true)
                        {
                            if(j-i+1 > max_length )
                            {
                                max_length = j-i+1;
                                begin_index = i;
                            }
                        }
                    }
                }
        
                return s.substr(begin_index,max_length);
        
        
        
        
        
                
        
        
            }
        };



        class Solution {
            public:
                int left = 0;
                int right = 0;
                int maxLength = 0;
                string longestPalindrome(string s) {
                    int result = 0;
                    for (int i = 0; i < s.size(); i++) {
                        extend(s, i, i, s.size()); // 以i为中心
                        extend(s, i, i + 1, s.size()); // 以i和i+1为中心
                    }
                    return s.substr(left, maxLength);
                }
                void extend(const string& s, int i, int j, int n) {
                    while (i >= 0 && j < n && s[i] == s[j]) {
                        if (j - i + 1 > maxLength) {
                            left = i;
                            right = j;
                            maxLength = j - i + 1;
                        }
                        i--;
                        j++;
                    }
                }
            };