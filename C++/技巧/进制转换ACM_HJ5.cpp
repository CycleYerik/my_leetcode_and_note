#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string input;
    cin >> input;

    int size = input.size();

    int result = 0;
    int count = 0;
    for(int i = size -1 ; i >= 2; i--)
    {
        if( input[i] >= '0' && input[i] <= '9')
        {
            result += (input[i] -'0') * pow(16,count); 
        }
        else 
        {
            result += (10 + input[i] -'A') * pow(16,count);
        }
        
        count++;
    }
    cout << result <<endl;
}
// 64 位输出请用 printf("%lld")