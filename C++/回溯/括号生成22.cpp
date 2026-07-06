class Solution {
    public:
        vector<string> result;
        string path;
        stack<char> st;
    
        void backtracking(int n, int left, int right) {
            if (path.size() == 2 * n) {
                if (st.empty()) result.push_back(path);
                return;
            }
    
            if (left < n) {
                path.push_back('(');
                st.push('(');
                backtracking(n, left + 1, right);
                st.pop();
                path.pop_back();
            }
    
            if (right < left && !st.empty() && st.top() == '(') {
                path.push_back(')');
                st.pop();           // 匹配掉一个 '('
                backtracking(n, left, right + 1);
                st.push('(');       // 回溯：恢复栈状态
                path.pop_back();
            }
        }
    
        vector<string> generateParenthesis(int n) {
            result.clear();
            path.clear();
            while (!st.empty()) st.pop();
            backtracking(n, 0, 0);
            return result;
        }
    };

    class Solution {
        public:
            vector<string> result;
            string path;
        
            void backtracking(int n, int left, int right) {
                // 终止：用了 2n 个括号
                if (path.size() == 2 * n) {
                    result.push_back(path);
                    return;
                }
        
                // 还能放左括号
                if (left < n) {
                    path.push_back('(');
                    backtracking(n, left + 1, right);
                    path.pop_back();
                }
        
                // 还能放右括号：右括号数量必须小于左括号
                if (right < left) {
                    path.push_back(')');
                    backtracking(n, left, right + 1);
                    path.pop_back();
                }
            }
        
            vector<string> generateParenthesis(int n) {
                result.clear();  // 防止 LeetCode 复用对象时累积
                path.clear();
                backtracking(n, 0, 0);
                return result;
            }
        };