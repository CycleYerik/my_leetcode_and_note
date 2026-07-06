class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int size1 = text1.size();
            int size2 = text2.size();
            int index_1 = 0, index_2 = 0;
            int length = 0;
            length = back_tracking(text1,text2,size1,size2,index_1,index_2,length);
            return length;
        }
    
        int back_tracking(string &text1, string &text2,int size1,int size2,int index_1,int index_2,int length)
        {   
            if(index_1 >= size1 || index_2 >= size2)
            {
                return length;
            }
            
            if(text1[index_1] == text2[index_2])
            {
                length++;
                index_1++;
                index_2++;
                length = back_tracking(text1,text2,size1,size2,index_1,index_2,length);
    
            }
            else
            {
                index_1++;
                int length1 = back_tracking(text1,text2,size1,size2,index_1,index_2,length);
                index_1--;
                index_2++;
                int length2 = back_tracking(text1,text2,size1,size2,index_1,index_2,length);
                index_2--;
                int temp = max(length1,length2);
                length = max(temp,length);
            }
            return length;
        }
    };



    class Solution {
        public:
            vector<vector<int>> memo;
        
            int dfs(const string& text1, const string& text2, int i, int j) {
                // 边界：某一串已经扫完，后面不可能再匹配
                if (i >= text1.size() || j >= text2.size()) {
                    return 0;
                }
        
                // 算过就直接用（避免 TLE）
                if (memo[i][j] != -1) {
                    return memo[i][j];
                }
        
                if (text1[i] == text2[j]) {
                    // 当前字符相等：一定配对，长度 +1，两个下标都往后
                    memo[i][j] = 1 + dfs(text1, text2, i + 1, j + 1);
                } else {
                    // 不相等：扔掉 text1[i] 或 扔掉 text2[j]，取更大
                    memo[i][j] = max(
                        dfs(text1, text2, i + 1, j),
                        dfs(text1, text2, i, j + 1)
                    );
                }
                return memo[i][j];
            }
        
            int longestCommonSubsequence(string text1, string text2) {
                memo.assign(text1.size(), vector<int>(text2.size(), -1));
                return dfs(text1, text2, 0, 0);
            }
        };