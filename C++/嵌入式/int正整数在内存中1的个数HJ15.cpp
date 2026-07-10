#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    long long times = 1;

    while(times <= n)
    {
        times *= 2;
    }
    times /= 2;

    int count = 0;
    int number = n;
    while(times >= 1)
    {
        if(number / times == 1)
        {
            count++;
        }
        number %= times;
        times /= 2;
    }
    cout << count <<endl;

}
// 64 位输出请用 printf("%lld")


//或者直接一点 n & 1 ; n >>1;

//又或者 n & (n-1)