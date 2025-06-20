#include <vector>
#include <iostream>

using namespace std;

// 本质上是暴力遍历，切割问题


class Solution {
public:

    vector<string> result;
    int point_number = 0;

    int is_valid_ip(string s,int start,int end)
    {
        if(start > end)  //最后一段字串为空时
        {
            return 0;
        }
        if(s[start] == '0' && start != end )
        {
            return 0;
        }

        int num = 0;
        for(int i = start; i <= end; i++)
        {
            if(s[i] > '9' || s[i] < '0')
            {
                return 0;
            }
            num = 10*num + (s[i] - '0');
            if(num > 255)
            {
                return 0;
            }
        }

        return 1;
    }

    void back_tracking(int times,  string s,int start_index)
    {
        if(times == 3)
        {
            if(is_valid_ip(s,start_index,s.size()-1) == 1)
            {
                result.push_back(s);
            }
            return;
        }

        for(int i = start_index ; i < s.size(); i++)
        {
            if(is_valid_ip(s,start_index,i) == 1)
            {
                s.insert(s.begin()+i+1,'.');
                point_number++;
                back_tracking(times+1,s,i+2);
                point_number--;
                s.erase(s.begin()+i+1);
            }
            else
            {
                break;
                //如果当前子串（s[start_index] 到 s[i]) 不是有效的 IP 地址段，那么更长的以相同起始位置开始的子串（例如 s[start_index] 到 s[i+1], s[start_index] 到 s[i+2], 等等）也不可能是有效的 IP 地址段
            }
        }

    }

    vector<string> restoreIpAddresses(string s) 
    {
        back_tracking(0,s,0);
        return result;
    }
};