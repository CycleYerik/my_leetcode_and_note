#include <iostream>
#include<algorithm>
using namespace std;



int main(void)
{
    int num =0;
    string s;
    cin>> num>> s;

    int length = s.size();

    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin() +num);
    reverse(s.begin()+num,s.end());
    cout<<s<<endl;
    return 0;
}