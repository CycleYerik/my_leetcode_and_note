class Solution {
    public:
        vector<string> result;
        string path = "";
        vector<int> number;
        vector<string> letters_set = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> letterCombinations(string digits) {
            
            int count = digits.size();
    
            for(auto digit : digits)
            {   
                number.push_back(digit - '0');
            }
    
            //一层层遍历
            back_tracking(path,0,count);
            return result;
    
    
    
    
        }
    
        void back_tracking(string &path,int index,int count)
        {
            if(path.size() == count)
            {
                result.push_back(path);
                return;
            }
            string letters = letters_set[number[index]];
    
            for(auto letter: letters)
            {
                path.push_back(letter);
                back_tracking(path,index+1,count);
                path.pop_back();
            }
    
        }
    
    
    };




    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
    
        string path;
        vector<string> letters_set = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        // 不需要 number 向量
        back_tracking(result, path, digits, letters_set, 0);
        return result;
    }
    
    void back_tracking(vector<string>& result, string& path,
                       const string& digits, vector<string> letters_set,int index) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }
        const string& letters = letters_set[digits[index] - '0'];  // 引用，不拷贝
        for (char letter : letters) {
            path.push_back(letter);
            back_tracking(result, path, digits, letters_set, index + 1);
            path.pop_back();
        }
    }