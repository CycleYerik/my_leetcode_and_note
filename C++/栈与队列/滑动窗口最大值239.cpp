
// 暴力法
class Solution {
public:
    vector<int> result;
    queue<int> my_queue;
    // 得到队列的最大值
    int get_queue_max(queue<int> input_queue,int size)
    {
        int temp = input_queue.front();
        input_queue.pop();
        input_queue.push(temp );
        for(int i = 1; i < size; i ++)
        {
            int front_value = input_queue.front();
            if(front_value > temp)
            {
                temp = front_value;
            }
            input_queue.pop();
            input_queue.push(front_value);
        }
        return temp;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(nums.size() == 1) // 边界情况
        {
            result.push_back(nums[0]);
        }
        else
        {
            for(int i = 0; i < k ; i ++) // 先进行队列的初始化
            {
                my_queue.push(nums[i]);
            }
            int temp_max_num = get_queue_max(my_queue,k);
            result.push_back(temp_max_num);
            for(int i = k; i < nums.size();i ++)
            {   
                my_queue.push(nums[i]);
                my_queue.pop();
                temp_max_num = get_queue_max(my_queue,k);
                result.push_back(temp_max_num);
            }
        }
        return result;
    }
};

// 本质上是单调队列（一旦超出范围，则舍弃头部，一旦新的比尾部旧的大，则舍弃尾部直到满足条件）
class My_queue_with_order{
    deque <int> my_queue;
    public:
    void pop(int value)
    {
        if(my_queue.empty() != 1 && my_queue.front() == value) //如果移动后去掉的是最大值，则直接弹出，否则不管
        {
            my_queue.pop_front();
        }
    }

    void push(int value)
    {
        while (!my_queue.empty() && value > my_queue.back())  // 将新的数添加进队列里
        {
            my_queue.pop_back();
        }
        my_queue.push_back(value);

    }

    int front() // 按照前后由大到小，故前面的即为最大值

    {
        return my_queue.front();
    }
};


class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        My_queue_with_order my_queue_order;
        for(int i = 0; i < k; i ++)
        {
            my_queue_order.push(nums[i]);
        }
        result.push_back(my_queue_order.front()); //先将前面的值计入
        for (int i = k; i < nums.size(); i++) 
        {
            my_queue_order.pop(nums[i - k]); 
            my_queue_order.push(nums[i]); 
            result.push_back(my_queue_order.front()); 
        }
        return result;
    }
};