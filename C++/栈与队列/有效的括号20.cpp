class Solution {
public:
    bool isValid(string s) {
        stack<int> my_stack;
        if(s.size() %2 != 0 )
        {
            return false;
        } 
        for(int i = 0 ; i < s.size() ; i ++)
        {
            if(s[i] == '(')
            {
                my_stack.push(')');
            }
            else if(s[i] == '[')
            {
                my_stack.push(']');
            }
            else if(s[i] == '{')
            {
                my_stack.push('}');
            }
            else if(my_stack.empty() == 1)
            {
                return false;
            }
            else if(my_stack.top() == s[i])
            {
                my_stack.pop();
            }
            else
            {
                return false;
            }
        }
        if(my_stack.empty() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};