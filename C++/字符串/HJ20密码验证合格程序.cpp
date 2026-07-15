#include <iostream>
using namespace std;

bool is_valid(string input);

int main() {
    
    string input;
    while(cin >>input)
    {
        if(is_valid(input))
        {
            cout << "OK" <<endl;
        }
        else {
            cout << "NG" <<endl;
        }
    }

    return 0;


}

bool is_valid(string input)
{
    if(input.size() < 8)
    {
        return false;
    }
    int abc = 0;
    int ABC = 0;
    int number = 0;
    int mark = 0;
    for(int i = 0; i < input.size() ; i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            number = 1;
        }
        else if(input[i] >= 'A' && input[i] <= 'Z')
        {
            ABC = 1;
        }
        else if(input[i] >= 'a' && input[i] <= 'z')
        {
            abc = 1;
        }
        else
        {
            mark = 1;
        }
    }
    if(abc + ABC + number + mark < 3 )
    {
        return false;
    }

    int win_size = 3; //核心就是，由于不重叠，所以只需要找3的窗口，因为如果窗口为4且不重叠，那肯定有窗口为3且不重叠的部分。

    for(int i = 0; i <= input.size() - win_size - win_size; i++ )
    {
        for(int j = i+3 ; j <= input.size() - win_size; j++)
        {
            int is_same = 1;
            for(int k = 0; k < win_size ; k++)
            {
                if(input[i+k] != input[j+k])
                {
                    is_same = 0;
                    break;
                }
            }
            if(is_same == 1)
            {
                return false;
            }
        }   
    }

    return true;





}



#include <iostream>
#include <string>
using namespace std;

bool isValid(const string& s) {
    if (s.size() < 8) return false;

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSymbol = false;
    for (char c : s) {
        if (c >= '0' && c <= '9') hasDigit = true;
        else if (c >= 'A' && c <= 'Z') hasUpper = true;
        else if (c >= 'a' && c <= 'z') hasLower = true;
        else hasSymbol = true;
    }
    int types = hasLower + hasUpper + hasDigit + hasSymbol;
    if (types < 3) return false;

    const int len = 3;
    for (int i = 0; i + len <= (int)s.size(); ++i) {
        string sub = s.substr(i, len);
        // 从 i+len 起找，保证两段不重叠
        if (s.find(sub, i + len) != string::npos)
            return false;
    }
    return true;
}

int main() {
    string s;
    while (cin >> s) {
        cout << (isValid(s) ? "OK" : "NG") << '\n';
    }
    return 0;
}





