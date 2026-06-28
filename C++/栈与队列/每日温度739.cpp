class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> my_stack;
    
            vector<int> result(temperatures.size(),0);
    
    
            for(int i = 0 ; i < temperatures.size() ; i++)
            {
                while(!my_stack.empty())
                {
                    int last_num = my_stack.top();
                    if(temperatures[i] > temperatures[last_num])
                    {
                        my_stack.pop();
                        result[last_num] = i - last_num;
                    }
                    else
                    {
                        break;
                    }  
                }
                my_stack.push(i);
    
            }
    
            return result;
        }
    };