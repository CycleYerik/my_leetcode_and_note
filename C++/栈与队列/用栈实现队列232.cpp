class MyQueue {
public:
    stack<int> stack_in,stack_out; // 双栈模拟即可
    MyQueue() {
        
    }
    
    void push(int x) {  
        stack_in.push(x);
    }
    
    int pop() {
        if( stack_out.empty() == 1)
        {
            while(stack_in.empty() != 1)
            {
                int temp = stack_in.top();
                stack_out.push(temp);
                stack_in.pop();
            }
        }
        int result = stack_out.top();
        stack_out.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        stack_out.push(result);
        return result;
    }
    
    bool empty() {
        if(stack_in.empty() &&stack_out.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */