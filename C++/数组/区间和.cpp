#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    int left,right;
    cin>>n;
    vector<int>number(n);
    for(int i = 0; i <n; i ++)
    {
        int temp=0;
        cin>>temp;
        if(i>0)
        {
            number[i]= number[i-1]+temp;
        }
        else
        {
            number[i] = temp;
        }
        
    }
    while(cin>>left>>right)
    {
        int sum= 0;
        if(left == 0)
        {
            sum = number[right];
        }
        sum = number[right]-number[left-1];
        cout<<sum<<endl;
    }
    return 0;
    

}

