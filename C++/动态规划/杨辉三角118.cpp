class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> result;
            vector<int> result_1 = {1};
            result.push_back(result_1);
            for(int i = 1 ; i < numRows ; i ++)
            {
                vector<int> temp_result;
                temp_result.push_back(1);
                for(int j = 1; j <= i-1 ; j++)
                {
                    temp_result.push_back(result[i-1][j-1] + result[i-1][j]);
                }
                temp_result.push_back(1);
                result.push_back(temp_result);
            }
            return result;
        }
    };