#include <iostream>
#include <vector>
using namespace std;

int h,w;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<vector<int>> result;
vector<vector<int>> temp_result;

void dfs(int x,int y)
{
    // 找未访问且为0的点,存入result
    if( x < h && x >= 0 && y < w && y >=0 && map[x][y] != 1 && visited[x][y] != 1)
    {
        visited[x][y] = 1;
        temp_result.push_back({x,y});

        if(x == h-1 && y == w-1)
        {
            result = temp_result;
            return;
        }
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
        temp_result.pop_back(); //回溯
        visited[x][y] = 0;
    }
    else 
    {
        return;
    }

    //如果找不到了就判断当下的result最后一个是不是目标点，

    
}

int main() {
    cin >> h >> w;
    map.resize(h, vector<int>(w));
    visited.resize(h, vector<int>(w));

    for(int i = 0 ; i < h ; i++)
    {
        for(int j = 0 ; j < w ; j++)
        {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    dfs(0,0);

    int size = result.size();
    for(int i = 0 ; i < size ; i ++)
    {
        cout << "(" << result[i][0] <<","<< result[i][1] <<")" <<endl;
    }

    
    return 0;
}