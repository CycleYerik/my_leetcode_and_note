class Solution {
    public:
        string multiply(string num1, string num2) {
            
            int m = num1.size();
            int n = num2.size();
    
            vector<int> result(m+n,0);
    
            for(int i = m -1 ; i >= 0 ; i--)
            {
                
                for(int j = n - 1 ; j >= 0; j--)
                {   
                    int temp = (num1[i] - '0') * (num2[j] - '0');
                    int pose_high = i + j ;
                    int pose_low = i + j + 1;
    
                    int sum = temp + result[pose_low]; //result 对应位置 low本身有的值，和乘法得到的值
                    result[pose_high] += sum / 10; //这个位置可能本身有值了
                    result[pose_low] = sum % 10; //这个位置原先的值已经参与计算了，所以直接赋值即可
                }
            }
    
            string answer = "";
    
            int index = 0;
            while(index < result.size() && result[index] == 0)
            {
                index++;
            }
    
            if (index == result.size()) return "0";
    
    
    
            for(int i = index ; i < result.size() ; i++)
            {
                answer.push_back(result[i] + '0');
            }
            return answer;
        }
    };