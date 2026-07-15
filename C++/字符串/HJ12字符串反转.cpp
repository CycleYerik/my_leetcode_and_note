#include <iostream>
using namespace std;

int main() {
    
    string input;
    cin >> input;

    int right = input.size()-1;
    int left = 0;

    while(left <= right)
    {
        char temp = input[right];
        input[right] = input[left];
        input[left] = temp; 
        left++;
        right--;
    }
    cout << input <<endl;



}
// 64 位输出请用 printf("%lld")