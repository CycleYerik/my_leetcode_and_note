class Solution {
    public:
        string addBinary(string a, string b) {
            int max_size = max(a.size(), b.size()) +1; //最大的位数
    
            
            string result = "";
    
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
    
            int size_a = a.size();
            int size_b = b.size();
    
            int is_carry = 0;
            int index_a = 0, index_b = 0;
    
            while(index_a < size_a || index_b < size_b || is_carry == 1)
            {
                int temp_a = (index_a < size_a) ? (a[index_a] - '0') : 0;
                int temp_b = (index_b < size_b) ? (b[index_b] - '0') : 0;
                int sum = temp_a + temp_b + is_carry;
                switch(sum)
                {
                    case 0:
                        result += '0';
                        is_carry = 0;
                        break;
                    case 1:
                        result += '1';
                        is_carry = 0;
                        break;
                    case 2:
                        result += '0';
                        is_carry = 1;
                        break;
                    case 3:
                        result += '1';
                        is_carry = 1;
                        break;
                }
                if(index_a < size_a)
                {
                    index_a++;
                }
                if(index_b < size_b )
                {
                    index_b++;
                }
            }
            reverse(result.begin(), result.end());
            return result;
    
    
            
    
        }
    };