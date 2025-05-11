class Solution {
public:
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }
};


class Solution {
public:
    string reverseWords(string s) {
        //先去除多余的空格
        remove_space(s);
        
        //将整个字符串翻转
        reverseString(s);

        //将翻转后的字符串里的单词进行翻转
        
    }

    void remove_space(string &s)
    {
        int slow = 0, fast = 0;
        //去掉前面的空格
        while(s.size() > 0 && fast < s.size() && s[fast] == ' ')
        {
            fast++;
        }
        for(; fast < s.size(); fast ++)
        {
            if(fast - 1 > 0 && s[fast -1 ] == s[fast] && s[fast] == ' ') //去掉多余的空格
            {
                continue;
            }
            else
            {
                s[slow] = s[fast];
                slow++;
            }
        }
        if(slow - 1 > 0 && s[slow -1] == ' ') //去掉末尾的空格
        {
            s.resize(slow-1);
        }
        else
        {
            s.resize(slow);
        }
    }

    void reverseString(string& s) {
        int left = 0, right = s.size()-1;
        while(left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};