

//优化后的代码
class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    int top(){
        int size = que.size();
        size--;
        while (size--){
            // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时获得的元素就是栈顶的元素了
        que.push(que.front());    // 将获取完的元素也重新添加到队列尾部，保证数据结构没有变化
        que.pop();
        return result;
    }

    bool empty() {
        return que.empty();
    }
};

//原始的代码

class MyStack {
public:

    queue<int> my_queue_1,my_queue_2;

    MyStack() {
        
    }
    
    void push(int x) {
        if(my_queue_1.empty() != 1)
        {
            my_queue_1.push(x);
        }
        else
        {
            my_queue_2.push(x);
        }        
    }
    
    int pop() {
        if(my_queue_1.empty() == 0)
        {
            while(my_queue_1.size() > 1)
            {
                my_queue_2.push(my_queue_1.front());
                my_queue_1.pop();
            } 
            int result = my_queue_1.front();
            my_queue_1.pop();
            return result;
        }
        else 
        {
            
                while(my_queue_2.size() > 1)
                {
                    my_queue_1.push(my_queue_2.front());
                    my_queue_2.pop();
                } 
                int result = my_queue_2.front();
                my_queue_2.pop();
                return result;
        }
       
    }
    
    int top() {
        if (!my_queue_1.empty()) return my_queue_1.back();
        return my_queue_2.back();
    }
    
    bool empty() {
        if(my_queue_1.empty() == 1 && my_queue_2.empty() == 1)
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
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */