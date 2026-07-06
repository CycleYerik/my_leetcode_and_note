class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            int current_sum = 0;
            vector<int> path;
            vector<vector<int>> result;
            int index = 0;
            back_tracking(candidates,target,current_sum,path,result,0);
            return result;
        }
    
    
        void back_tracking(vector<int>& candidates, int target, int current_sum, vector<int> &path,vector<vector<int>> & result,int index)
        {
            if(current_sum == target )
            {
                result.push_back(path);
                return;
            }
            else if(current_sum > target)
            {
                return;
            }
    
    
    
            //进行遍历尝试
            for(int i = index ; i < candidates.size(); i++)
            {
                current_sum += candidates[i];
                path.push_back(candidates[i]);
                back_tracking(candidates,target,current_sum,path,result,i);
                path.pop_back();
                current_sum -= candidates[i];
    
            }
        }
    };
    


class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            int current_sum = 0;
            vector<int> path;
            vector<vector<int>> result;
            int index = 0;
            back_tracking(candidates,target,current_sum,path,result,0);
            return result;
        }
    
    
        void back_tracking(vector<int>& candidates, int target, int current_sum, vector<int> &path,vector<vector<int>> & result,int index)
        {
            if(current_sum == target )
            {
                result.push_back(path);
                return;
            }
            else if(current_sum > target || index >= candidates.size())
            {
                return;
            }
    
            back_tracking(candidates,target,current_sum,path,result,index+1);
    
            current_sum += candidates[index];
            path.push_back(candidates[index]);
            back_tracking(candidates,target,current_sum,path,result,index);
            path.pop_back();
            current_sum -= candidates[index];
    
        }
    };