class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>is_repeat;
        int now_number = 0;
        int temp_number = 0;
        now_number = n;
        while(now_number != 1 && (is_repeat.find(now_number) == is_repeat.end())) // 用set来判断是否重复
        {
            int temp_store = 0;
            is_repeat.insert(now_number);
            while(now_number > 0) // 计算平方和
            {
                temp_number = now_number % 10;
                temp_store += temp_number*temp_number;
                now_number = now_number / 10;
            }
            now_number = temp_store;
        }
        if(now_number == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    
    }
};