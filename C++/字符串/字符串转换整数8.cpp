class Solution {
    public:
        int myAtoi(string s) {
            int status =0; //0 为刚开始等待读取前导空格， 1 为等待读取符号， 2为等待跳过前导零， 3为跳过了前导零，开始读取数字， 4 为读取完数字
    
    
            vector<int> valid_number;
    
            int index = 0;
            int direction = 1; //符号位
            int is_finished = 0;
            while(index < s.size() && is_finished == 0)
            {
                switch(status)
                {
                    case 0:
                        if(s[index] == ' ')
                        {
                            index++;
                            
                        }
                        else 
                        {
                            status = 1;
                            
                        }
                        continue;
                        break;
    
    
                    case 1: 
                        if(s[index] == '+')
                        {
                            direction = 1;
                            index++;
                        }
                        else if(s[index] == '-')
                        {
                            direction = -1;
                            index++;
                        }
                        
                        status = 2;
                        break;
    
                    case 2:
                        if(s[index] == '0')
                        {
                            index++;
                        }
                        else
                        {
                            status = 3;
                        }
                        break;
                    
                    case 3:
                        if(s[index] >= '0' && s[index] <= '9')
                        {
                            valid_number.push_back(s[index] - '0');
                            index++;
                        }
                        else
                        {
                            is_finished = 1;
                        }
                        break;
    
                    default:
                        break;
    
                }
            }
    
    
            // 从左到右累加，乘 10 之前判断是否会溢出 int 范围 太恶心了
            long long result = 0;
            for (int digit : valid_number) {
                if (result > INT_MAX / 10
                    || (result == INT_MAX / 10 && digit > (direction == 1 ? 7 : 8))) {
                    return direction == 1 ? INT_MAX : INT_MIN;
                }
                result = result * 10 + digit;
            }
            result *= direction;
            return (int)result;
    
        }
    };



    class Solution {
        public:
            int myAtoi(string s) {
                int i = 0, n = s.size();
                int sign = 1;
                long long result = 0;
        
                // 1. 跳过前导空格
                while (i < n && s[i] == ' ') {
                    i++;
                }
        
                // 2. 读符号
                if (i < n && (s[i] == '+' || s[i] == '-')) {
                    sign = (s[i] == '-') ? -1 : 1;
                    i++;
                }
        
                // 3. 读数字（前导零在这里自然被跳过）
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    int digit = s[i] - '0';
        
                    // 4. 乘 10 之前判断溢出
                    if (result > INT_MAX / 10
                        || (result == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) {
                        return sign == 1 ? INT_MAX : INT_MIN;
                    }
        
                    result = result * 10 + digit;
                    i++;
                }
        
                return (int)(sign * result);
            }
        };