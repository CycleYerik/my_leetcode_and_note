class Solution {
private:
    vector<vector<string>> result;
    vector<string> temp_result;
public:
    
    int is_loop(string&s, int start,int end)
    {
        for(int i = start, j = end; i < j ; i ++ , j--)
        {
            if(s[i] != s[j])
            {
                return 0;
            }
        }
        return 1;
    }

    void backtracking(int start,string &s)
    {
        if(start >= s.size())
        {
            result.push_back(temp_result);
            return;
        }
        for(int i = start; i < s.size(); i++)
        {
            if(is_loop(s,start,i) == 1)
            {
                string temp = s.substr(start,i-start+1);
                temp_result.push_back(temp);
            }
            else
            {
                continue;
            }
            backtracking(i+1,s);
            temp_result.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        backtracking(0,s);
        return result;
        
    }
};

class Solution {
    public:
        vector<vector<string>> partition(string s) {
            
            vector<string> path;
            vector<vector<string>> result;
    
            vector<vector<int>> memory_partition(s.size(), vector<int>(s.size(),-1));
    
            dfs(s,memory_partition,0,path,result);
            return result;
    
    
        }
    
        void dfs(string &s, vector<vector<int>> &memory_partition,int start,vector<string> &path , vector<vector<string>> &result)
        {
            if(start == s.size())
            {
                result.push_back(path);
                return;
            }
            
            for(int i = start ; i < s.size() ; i++)
            {
                if(is_partition(s,memory_partition,start,i) == true)
                {
                    path.push_back(s.substr(start, i-start+1));
                    dfs(s,memory_partition,i+1,path,result);
                    path.pop_back();
                }
            }
        }
    
    
        bool is_partition(string &s,vector<vector<int>> &memory_partition, int start,int end)
        {
            if(memory_partition[start][end] == 1)
            {
                return true;
            }
            else if(memory_partition[start][end] == 0)
            {
                return false;
            }
            else 
            {
                int left = start, right = end;
                while(left <= right)
                {
                    if(s[left] != s[right])
                    {
                        memory_partition[start][end] = 0;
                        return false;
                    }
                    left++;
                    right--;
                }
                memory_partition[start][end] = 1;
                return true;
            }
        }
    };


    class Solution {
        public:
            vector<vector<string>> partition(string s) {
                int n = s.size();
                vector<string> path;
                vector<vector<string>> result;
        
                // 预处理：dp[i][j] 表示 s[i..j] 是否为回文
                vector<vector<bool>> dp(n, vector<bool>(n, false));
        
                // 按长度从小到大填表
                for (int len = 1; len <= n; len++) {
                    for (int i = 0; i + len - 1 < n; i++) {
                        int j = i + len - 1;
        
                        if (len == 1) {
                            dp[i][j] = true;
                        } else if (len == 2) {
                            dp[i][j] = (s[i] == s[j]);
                        } else {
                            dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                        }
                    }
                }
        
                dfs(s, dp, 0, path, result);
                return result;
            }
        
            void dfs(string &s,
                     vector<vector<bool>> &dp,
                     int start,
                     vector<string> &path,
                     vector<vector<string>> &result)
            {
                if (start == s.size()) {
                    result.push_back(path);
                    return;
                }
        
                for (int i = start; i < s.size(); i++) {
                    if (dp[start][i]) {  // O(1) 查表，不再双指针
                        path.push_back(s.substr(start, i - start + 1));
                        dfs(s, dp, i + 1, path, result);
                        path.pop_back();
                    }
                }
            }
        };