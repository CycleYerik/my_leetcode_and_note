#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirction[4][2] = {0,1,1,0,-1,0,0,-1};
int area_count = 0;
int max_area_square = 0;

void bsp(vector<vector<bool>> &visited_in,const vector<vector<int>> &map_in,int x, int y)
{
    queue<pair<int,int>> my_que;
    my_que.push({x,y});
    visited_in[x][y] = true;
    int now_x = 0, now_y = 0;
    area_count = 1;
    while(my_que.empty() != 1)
    {   
        pair<int,int>temp = my_que.front();
        my_que.pop();
        for(int i = 0; i < 4 ; i++)
        {
            now_x = temp.first + dirction[i][0];
            now_y = temp.second + dirction[i][1];

            //边界判断
            if(now_x <0 || now_x >= map_in.size() || now_y < 0 || now_y >=  map_in[0].size())
            {
                continue;
            }
            else
            {
                if(visited_in[now_x][now_y] == false && map_in[now_x][now_y] == 1)
                {
                    my_que.push({now_x,now_y});
                    visited_in[now_x][now_y] = true;
                    area_count ++;
                }
            }
        }
    }
    if(area_count > max_area_square)
    {
        max_area_square = area_count;
    }

}

int main(void)
{

    int N,M;
    cin >>N >> M ;

    vector<vector<int>> map(N,vector<int>(M,0));

    //初始化
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j ++)
        {
            cin >> map[i][j];
        }
    }

    vector<vector<bool>> visited(N,vector<bool>(M,0));

    for(int i = 0 ; i < N; i ++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            if(visited[i][j] == false && map[i][j] == 1)
            {
                bsp(visited,map,i,j);
            }
        }
    }

    cout << max_area_square<< endl;


    return 0;
}