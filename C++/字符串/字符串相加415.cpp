class Solution {
    public:
        string addStrings(string num1, string num2) {
    
    
            int index_1 = num1.size() -1;
            int index_2 = num2.size() -1;
    
            int carry = 0;
    
            string result = "";
    
            while(index_1 >= 0 || index_2 >= 0 || carry != 0)
            {
                int number_1 = (index_1 >= 0) ? num1[index_1] - '0' : 0;
                int number_2 = (index_2 >= 0) ? num2[index_2] - '0' : 0;
                int this_num = number_1 + number_2 + carry;
                carry = this_num /10;
                this_num %= 10;
                result += (this_num + '0');
                if(index_1 >= 0)
                {
                    index_1--;
                }
                if(index_2 >= 0)
                {
                    index_2--;
                }
    
            }
            reverse(result.begin(),result.end());
            return result;
        }
    };