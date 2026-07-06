class MinStack {
    public:
        
        stack<pair<int,int>> my_stack; 
    
        MinStack() {
            
        }
        
        void push(int value) {
    
            if(my_stack.empty())
            {
                my_stack.push({value,value});
                return;
            }
    
            auto node = my_stack.top();
            
            int min_value = 0;
    
            if(value < node.second)
            {
                min_value = value;
            }
            else
            {
                min_value = node.second;
            }
            my_stack.push({value,min_value});
        }
        
        void pop() {
            my_stack.pop();
        }
        
        int top() {
            return my_stack.top().first;
        }
        
        int getMin() {
            return my_stack.top().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(value);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */