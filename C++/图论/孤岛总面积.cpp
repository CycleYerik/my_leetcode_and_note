#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <queue>
using namespace std;

int dir[][2] = {0,-1,0,1,-1,0,1,0};

int bsp(int x, int y,int N,int M,vector<vector<int>> &graph,vector<vector<int>> &visited)
{
    queue<pair<int,int>> queue;
    queue.push({x,y});
    visited[x][y] = 1;
    int area = 1;
    int is_isolated = 1;
    
    while(queue.empty() != 1)
    {
        pair<int,int> temp = queue.front();
        int x_now = temp.first;
        int y_now = temp.second;
        if(x_now == 0 || x_now == N-1 || y_now == 0 || y_now == M-1)
        {
            is_isolated = 0;
        }
        queue.pop();
        for(int i = 0; i < 4; i++)
        {
            
            if(x_now + dir[i][0] >= 0 && x_now + dir[i][0] < N && y_now + dir[i][1] >= 0 && y_now + dir[i][1] < M && graph[x_now + dir[i][0]][y_now + dir[i][1]] == 1 && visited[x_now + dir[i][0]][y_now + dir[i][1]] == 0)
            {
                
                queue.push({x_now + dir[i][0],y_now + dir[i][1]});
                visited[x_now + dir[i][0]][y_now + dir[i][1]] = 1;

                area ++;
            }
        }
    }
    if(is_isolated == 0)
    {
        area = 0;
    }
    return area;

}


int main()
{
    int n,m;
    cin >> n >>m;


    
    int area_all = 0;

    // 初始化图和visited数组
    vector<vector<int>> graph(n,vector<int>(m,0));
    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            cin >> graph[i][j];
        }
    }

    for(int i = 0 ; i < n ; i ++ )
    {
        for(int j = 0 ; j < m ; j ++)
        {
            if(graph[i][j] == 1 && visited[i][j] == 0)
            {
                int area = bsp(i,j,n,m,graph,visited);
                area_all += area;
            }
        }
    }
    cout << area_all <<endl;



    return 0;
}