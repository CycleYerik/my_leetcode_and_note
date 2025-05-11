class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> result_AB;
        int count = 0;
        for(int i = 0; i < nums1.size() ; i ++) // 将AB的结果都储存
        {
            for(int j = 0; j <nums2.size()  ; j ++)
            {
                result_AB[nums1[i]+nums2[j]]++;
            }
        }
        for(int i = 0; i < nums3.size() ; i ++)
        {
            for(int j = 0; j < nums4.size()  ; j ++)
            {
                if(result_AB.find(-nums3[i] - nums4[j]) != result_AB.end())
                {
                    count += result_AB[-(nums3[i] + nums4[j])];
                }
            }
        }
        return count;


    }
};