#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// ==========================================
// 方法一：自底向上的迭代动态规划（DP）- 你之前实现的版本
// ==========================================
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.size()+1, false);

        dp[0] = true;

        //把字典存入哈希表
        unordered_set<string> set;
        for(auto word : wordDict)
        {
            set.insert(word);
        }


        for(int i = 1 ; i <= s.size() ; i++)
        {
            for(int j = i-1 ; j >= 0 ; j--)
            {
                if(dp[j] == true)
                {
                    //寻找i-j这个字符串是否能切分
                    string temp = s.substr(j, i-j);

                    //如果能就把dp[i]标注为true,然后break
                    if(set.find(temp) != set.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        } 
        return dp[s.size()];
    }
};

// ==========================================
// 方法二：记忆化回溯（DFS + Memoization）- 递归优化的思路
// ==========================================
/*
 * 思路分析：
 * 1. 递归基（Base Case）：如果 start 索引到达了字符串的末尾（start == s.size()），
 *    说明前方的所有子串均已成功拆分，返回 true。
 * 2. 剪枝优化（记忆化）：由于普通 DFS 在面对大量重复重叠子问题时会超时，
 *    我们定义一个 memo 数组。memo[start] 用于缓存从 start 开始的后缀子串是否能被成功拆分。
 *    - memo[start] == -1：尚未计算过。
 *    - memo[start] == 0：计算过，结果为“无法拆分”。
 *    - memo[start] == 1：计算过，结果为“可以拆分”。
 * 3. 状态转移：从 start 开始，尝试每一种可能的前缀终点 end。
 *    如果前缀 s[start...end-1] 在字典中存在，且剩下的部分 dfs(s, end) 也能匹配成功，
 *    那么将 memo[start] 记录为 1 且返回 true。
 */
class SolutionDFS {
private:
    vector<int> memo; // 缓存，-1表示未计算，0表示不能拆分，1表示能拆分
    unordered_set<string> wordSet;

    bool dfs(const string& s, int start) {
        // 1. 递归出口：成功匹配到末尾
        if (start == s.size()) {
            return true;
        }

        // 2. 检查缓存：避免重复计算
        if (memo[start] != -1) {
            return memo[start] == 1;
        }

        // 3. 尝试所有可能的前缀切割
        for (int end = start + 1; end <= s.size(); ++end) {
            string prefix = s.substr(start, end - start);
            
            // 只要找到一种可行的分割方案，就直接记录并返回 true（短路求值/剪枝）
            if (wordSet.count(prefix) && dfs(s, end)) {
                memo[start] = 1; // 记录该后缀可行
                return true;
            }
        }

        memo[start] = 0; // 所有前缀都不行，记录该后缀不可行
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo = vector<int>(s.size(), -1); // 初始化缓存为 -1
        return dfs(s, 0);
    }
};

// ==========================================
// 方法三：广度优先搜索（BFS）- 图的层序遍历思路
// ==========================================
/*
 * 思路分析：
 * 1. 节点抽象：将字符串的每个索引 [0, s.size()] 看作图的顶点。
 * 2. 边抽象：若子串 s[start...end-1] 在字典中，说明存在一条有向边 start -> end。
 * 3. 遍历目标：寻找一条能从起点 0 沿着有向边走到终点 s.size() 的路径。
 * 4. 优化机制（visited 数组）：
 *    在 BFS 中，若一个节点已经被访问（入过队列），它代表的后缀是否能拆分已经被或将被穷尽探索。
 *    无需重复将该节点入队。这能将时间复杂度控制在 O(N^2) 级别。
 */
class SolutionBFS {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(s.size() + 1, false);

        // 初始化起点 0 入队
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            // 如果已经拓展到了终点位置，说明当前路径可以将整个字符串拆分成功
            if (start == s.size()) {
                return true;
            }

            // 从当前的 start 出发，尝试所有可能的终点 end
            for (int end = start + 1; end <= s.size(); ++end) {
                // 如果 end 已经被访问过，不需要再次入队计算，直接剪枝
                if (visited[end]) {
                    continue;
                }

                string prefix = s.substr(start, end - start);
                // 如果前缀是字典中的有效单词，则说明存在通路，end 可达，将其入队
                if (wordSet.count(prefix)) {
                    q.push(end);
                    visited[end] = true; // 标记防止重复遍历
                }
            }
        }

        return false;
    }
};