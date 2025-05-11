class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> number;
        stack<char> mark;
        long long result = 0;
        long long temp1 = 0, temp2 = 0;
        long long store = 0;
        for(int i = 0; i < tokens.size(); i ++)
        {
            
            if(tokens[i] == "*")
            {
                temp1 = number.top();
                number.pop();
                temp2 = number.top();
                number.pop();
                store = temp1 * temp2;
                number.push(store);
            }
            else if(tokens[i] == "/")
            {
                temp1 = number.top();
                number.pop();
                temp2 = number.top();
                number.pop();
                store = temp2 / temp1;
                number.push(store);
            }
            else if(tokens[i] == "+")
            {
                temp1 = number.top();
                number.pop();
                temp2 = number.top();
                number.pop();
                store = temp1 + temp2;
                number.push(store);
            }
            else if(tokens[i] == "-")
            {
                temp1 = number.top();
                number.pop();
                temp2 = number.top();
                number.pop();
                store = temp2 - temp1;
                number.push(store);
            }
            else
            {
                number.push(stoll(tokens[i]));
            }
        }
        result = number.top();
        return result;
    }
};