

//BFS 入度表法
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
            //构建邻接表
            vector<vector<int>> adjlist(numCourses);
    
            //构建每门课程的入度
            vector<int> indeg(numCourses,0);
    
            //计算有多少门课修完了
            int count = 0;
    
            int n = prerequisites.size();
            for(int i = 0 ; i < n ; i++)
            {
                adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]); //这门课依赖什么
                indeg[prerequisites[i][0]]++;
            }
    
            //把每一个入度为零的放入队列
            queue<int> myqueue;
            for(int i = 0 ; i < numCourses ; i++)
            {
                if(indeg[i] == 0)
                {
                    myqueue.push(i);
                }
            }
    
            while(!myqueue.empty())
            {
                int temp_num = myqueue.front();
                myqueue.pop();
                count++;
                int num_size = adjlist[temp_num].size();
                for(int i = 0 ; i < num_size ; i++)
                {
                    indeg[adjlist[temp_num][i]]--;
                    if(indeg[adjlist[temp_num][i]] == 0)
                    {
                        myqueue.push(adjlist[temp_num][i]);
                    }
                }
            }
    
            if(count != numCourses)
            {
                return false;
            }
            else
            {
                return true;
            }
    
    
    
    
        }
    
        
    };




//DFS 三态标记法
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
            //构建邻接表
            vector<vector<int>> adjlist(numCourses);
            int n = prerequisites.size();
            for(int i = 0 ; i < n ; i++)
            {
                adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]); //这门课依赖什么
            }
    
            //构建visited
            vector<int> visited(numCourses,0);
    
            for(int i = 0 ; i < numCourses ; i++)
            {
                if(dfs(i,adjlist,visited) == false)
                {
                    return false;
                }
            }
            return true;
    
    
    
        }
    
        bool dfs(int node, vector<vector<int>> &adjlist, vector<int> &visited)
        {
            if(visited[node] == 1)
            {
                return false;
            }
            else if(visited[node] == 2)
            {
                return true;
            }
            else if(visited[node] == 0)
            {
                int require_size = adjlist[node].size();
                visited[node] = 1;
                for(int i = 0 ; i < require_size ; i++)
                {
                    int temp = adjlist[node][i];
                    if(dfs(temp,adjlist,visited) == false)
                    {
                        
                        return false;
                    }
                }
                visited[node] = 2;
                return true;
            }
            return true;
        }
    };