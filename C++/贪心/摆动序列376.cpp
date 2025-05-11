
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 0;
        int now_diff = 0, last_diff = 0;

        if(nums.size() <= 1)
        {
            return 1;
        }
        result = 1;
        last_diff = nums[1] - nums[0];
        if(last_diff != 0)
        {
            result ++;
        }
        for(int i = 1; i < nums.size() -1 ; i ++) //从1 到 size -2
        {
            now_diff = nums[i+1] - nums[i];
            if((now_diff > 0 && last_diff <= 0 ) || (now_diff < 0 && last_diff >= 0)) //这里注意=的使用，也就是平坡的情况
            {
                result++;
                last_diff = now_diff;
            }
        }
        return result;
    }
};