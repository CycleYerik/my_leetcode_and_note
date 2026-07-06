class Solution {
    public:
        string decodeString(string s) {
            stack<char> st;
    
            for (char c : s) {
                if (c != ']') {
                    st.push(c);
                } else {
                    // 1. 弹出括号内的字母（直到 '['，但不包含 '['）
                    string inner = "";
                    while (st.top() != '[') {
                        inner = st.top() + inner;  // 栈是反的，这样拼才正序
                        st.pop();
                    }
                    st.pop();  // 弹出 '['
    
                    // 2. 弹出数字 k（可能多位，从栈顶往下读）
                    int k = 0;
                    int base = 1;
                    while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                        k += (st.top() - '0') * base;
                        base *= 10;
                        st.pop();
                    }
    
                    // 3. 重复后压回栈
                    string expanded = "";
                    for (int i = 0; i < k; i++) {
                        expanded += inner;
                    }
                    for (char ch : expanded) {
                        st.push(ch);
                    }
                }
            }
    
            // 4. 栈里剩下解码结果，按栈底到栈顶顺序取出
            string result = "";
            while (!st.empty()) {
                result = st.top() + result;
                st.pop();
            }
            return result;
        }
    };


    class Solution {
        public:
            string decodeString(string s) {
                string result = "";
                int times = 0;
                stack<int> numStack;
                stack<string> strStack;
        
                for (char c : s) {
                    if (c >= '0' && c <= '9') {
                        times = times * 10 + (c - '0');
                    } else if (c == '[') {
                        numStack.push(times);
                        strStack.push(result);
                        times = 0;
                        result = "";
                    } else if (c == ']') {
                        string inner = result;
                        result = strStack.top();
                        strStack.pop();
                        int k = numStack.top();
                        numStack.pop();
                        for (int i = 0; i < k; i++) {
                            result += inner;
                        }
                    } else {
                        result += c;
                    }
                }
                return result;
            }
        };