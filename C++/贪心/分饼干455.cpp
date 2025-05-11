#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{



    return 0;
}


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int result = 0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int children_position = s.size()-1;
        for(int i = g.size()-1; i >= 0 ; i--)
        {
            
                if(children_position >= 0 && s[children_position] >= g[i]  )
                {
                    result++;
                    children_position --;
                }
        }
        return result;
    }
};