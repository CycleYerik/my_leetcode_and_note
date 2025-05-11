class Solution {
public:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件单一结果

    void backtracking(int n, int k, int startIndex)
    {
        //判断中止的条件
        if(path.size() == k)
        {
            result.push_back(path);
            return;
        }

        //递归进行输出
        for(int i = startIndex; i <= n ; i++)
        {
            path.push_back(i); // 存进去
            backtracking(n,k,i+1);
            path.pop_back();  //撤销处理的节点
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;
    }
};