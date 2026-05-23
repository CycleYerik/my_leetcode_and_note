class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int final = nums.size()-1;
    
            int max_position = 0;
    
            for (int i = 0 ; i < nums.size() ; i++)
            {
                if(i > max_position)
                {
                    return false;
                }
                else
                {
                    max_position = max(max_position, i+nums[i]);
                }
                if(max_position >= final)
                {
                    return true;
                }
            }
            return false;
    
        }

        bool canJumpReverse(vector<int>& nums) {
            int goal = nums.size() - 1;

            for (int i = nums.size() - 2 ; i >= 0 ; i--)
            {
                if (i + nums[i] >= goal)
                {
                    goal = i;
                }
            }
            return goal == 0;
        }
    };