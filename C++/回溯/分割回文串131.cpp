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