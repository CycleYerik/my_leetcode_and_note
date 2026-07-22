#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string input;

    cin >> input;

    unordered_map<char,int>map;
    int min_times = INT_MAX;

    for(int i = 0 ; i < input.size() ; i++)
    {
        if(map.find(input[i]) == map.end())
        {   
            map[input[i]] = 1;
        }
        else {
            map[input[i]]++;
        }
    }

    unordered_set<char> least_alpha;
    for(auto temp :map)
    {
        if(temp.second < min_times)
        {
            min_times = temp.second;
        }
    }
    for(auto temp :map)
    {
        if(temp.second == min_times)
        {
            least_alpha.insert(temp.first);
        }
    }

    string result = "";
    for(int i = 0 ; i < input.size() ; i++)
    {
        if(least_alpha.find(input[i]) == least_alpha.end())
        {
            result += input[i];
        }
    }
    cout << result <<endl;







}
// 64 位输出请用 printf("%lld")


//! ========== 标准写法（哈希/数组计数 · O(n)） ==========
// 1. 统计每个字符频次
// 2. 找出现次数的最小值 minFreq（只在出现过的字符里找）
// 3. 原序输出所有 cnt[c] > minFreq 的字符
// 注意：同一文件只能有一个 main。使用本段时请注释掉上方 main。

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int cnt[26] = {0};
    for (char c : s) {
        ++cnt[c - 'a'];
    }

    int minFreq = INT_MAX;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > 0) {
            minFreq = std::min(minFreq, cnt[i]);
        }
    }

    std::string result;
    for (char c : s) {
        if (cnt[c - 'a'] > minFreq) {
            result += c;
        }
    }

    std::cout << result << '\n';
    return 0;
}

// 也可 cnt[c-'a']++ 后：minFreq = *min_element(cnt, cnt+26);
// 但 min_element 会把未出现的 0 算进去，必须只在出现过的字符上取 min（如上）。
