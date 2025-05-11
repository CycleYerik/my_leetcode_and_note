void bfsTraversal(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0); // 初始化访问数组
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // 如果当前节点未被访问
            q.push(i); // 将当前节点加入队列
            visited[i] = 1; // 标记当前节点已经被访问
            while (!q.empty()) { // 循环遍历队列中的节点
                int cur = q.front();
                q.pop();
                // 处理当前节点cur
                for (int j = 0; j < graph[cur].size(); j++) {
                    int next = graph[cur][j];
                    if (!visited[next]) { // 如果下一个节点未被访问
                        q.push(next); // 将下一个节点加入队列
                        visited[next] = 1; // 标记下一个节点已经被访问
                    }
                }
            }
        }
    }
}