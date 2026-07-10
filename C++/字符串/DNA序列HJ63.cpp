#include <iostream>
using namespace std;

int main() {
    
    string DNA_sequence;
    int N = 0;

    cin >> DNA_sequence;
    cin >> N;

    if(DNA_sequence.size() < N)
    {
        cout << "";
    }
    else
    {
        int left = 0, right = N-1;
        int count = 0;
        int max_length = 0;
        int max_index = 0;

        for(int i = 0; i < N ; i++)
        {
            if(DNA_sequence[i] == 'C' || DNA_sequence[i] == 'G')
            {
                count++;
            }
        }
        max_length = count;
        
        right ++;
        

        for(; right < DNA_sequence.size() ; right++)
        {
            if(DNA_sequence[left] == 'C' || DNA_sequence[left] == 'G')
            {
                count--;
            }
            if(DNA_sequence[right] == 'C' || DNA_sequence[right] == 'G')
            {
                count++;
            }
            left++;
            if(count > max_length)
            {
                max_length = count;
                max_index = left;
            }
        }
        for(int i = max_index ; i < max_index + N ; i++)
        {
            cout << DNA_sequence[i];
        }
        cout <<endl;

    }





}
// 64 位输出请用 printf("%lld")