class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int cost_sum = 0;
        int result = 0;
        vector<int> dp_cost(size+1);
        dp_cost[1] = 0;
        dp_cost[0] = 0;

        for(int i = 2  ; i <= size; i++)
        {
            dp_cost[i] = ((dp_cost[i-1]+ cost[i-1])> (dp_cost[i-2]+cost[i-2]))?(dp_cost[i-2]+ cost[i-2]): (dp_cost[i-1]+cost[i-1]);
        }
        return dp_cost[size];

    }
};