class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char spart : s) {
            if (st.empty() || spart != st.top()) {
                st.push(spart);
            } else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";
        while(st.empty() != 1)
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};