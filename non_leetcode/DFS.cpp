#include <iostream>
#include <vector>
using namespace std;

// 递归实现DFS
void dfs(int cur, vector<int>& visited, vector<vector<int>>& graph) {
    visited[cur] = 1; // 标记当前节点已经被访问
    // 处理当前节点cur
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (!visited[next]) { // 如果下一个节点未被访问
            dfs(next, visited, graph); // 继续访问下一个节点
        }
    }
}
void dfsTraversal(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0); // 初始化访问数组
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // 如果当前节点未被访问
            dfs(i, visited, graph); // 从当前节点开始进行深度优先遍历
        }
    }
}

// 队列实现DFS
void dfsTraversal(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0); // 初始化访问数组
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // 如果当前节点未被访问
            s.push(i); // 将当前节点加入栈
            visited[i] = 1; // 标记当前节点已经被访问
            while (!s.empty()) { // 循环遍历栈中的节点
                int cur = s.top();
                s.pop();
                // 处理当前节点cur
                for (int j = 0; j < graph[cur].size(); j++) {
                    int next = graph[cur][j];
                    if (!visited[next]) { // 如果下一个节点未被访问
                        s.push(next); // 将下一个节点加入栈
                        visited[next] = 1; // 标记下一个节点已经被访问
                    }
                }
            }
        }
    }
}