class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> combination;
            result.push_back(combination);
            back_tracking(nums,result,combination,0);
            return result;
            
    
    
        }
    
        void back_tracking(vector<int>& nums,vector<vector<int>> &result,vector<int> &combination,int index)
        {
            // 终止条件
            if(index >= nums.size())
            {
                return;
            }
            
    
    
            for(int i = index ; i < nums.size(); i++)
            {
                combination.push_back(nums[i]);
                result.push_back(combination);
                back_tracking(nums,result,combination,i+1); //从下一个开始，就不会重复了
                combination.pop_back();
            }
        }
    };

    class Solution {
        public:
            vector<int> t;
            vector<vector<int>> ans;
        
            void dfs(int cur, vector<int>& nums) {
                if (cur == nums.size()) {
                    ans.push_back(t);
                    return;
                }
                t.push_back(nums[cur]); //本质上是针对每一个元素选或者不选
                dfs(cur + 1, nums);
                t.pop_back();
                dfs(cur + 1, nums);
            }
        
            vector<vector<int>> subsets(vector<int>& nums) {
                dfs(0, nums);
                return ans;
            }
        };
        
