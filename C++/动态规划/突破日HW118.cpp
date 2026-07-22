#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    

    int N;

    cin >> N;

    if(N < 2)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int>steps(N,0);
    vector<int>min_days(N,INT_MAX/2);

    int result = 0;

    for(int i = 0; i < N ; i++)
    {
        cin >> steps[i];
    }
    min_days[N-1] = steps[N-1];

    for(int i = N-2 ; i >= 0 ; i--)
    {
        if(steps[i] > 2 * min_days[i+1])
        {
            result++;
        }
        if(steps[i] < min_days[i+1])
        {
            min_days[i] = steps[i];
        }
        else 
        {
            min_days[i] = min_days[i+1];
        }
    }
    cout << result <<endl;
    return 0;


}
// 64 位输出请用 printf("%lld")


//! ========== 标准写法（后缀最小值 · O(N) 时间 O(1) 额外空间） ==========
// 题意：第 i 天是突破日 ⟺ 存在 j>i 使 S[i] > 2*S[j]
//       ⟺ S[i] > 2 * min(S[i+1..N-1])
// 注意：同一文件只能有一个 main。使用本段时请注释掉上方 main。

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    if (N <= 1) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::vector<int> steps(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> steps[i];
    }

    int ans = 0;
    int suffixMin = steps[N - 1];  // 后缀 [i+1..N-1] 的最小步数

    for (int i = N - 2; i >= 0; --i) {
        if (steps[i] > 2 * suffixMin) {
            ++ans;
        }
        suffixMin = std::min(suffixMin, steps[i]);
    }

    std::cout << ans << '\n';
    return 0;
}

// 暴力对照版（O(N^2)，仅帮助理解题意，N<=1000 也能过）：
// for (int i = 0; i < N; ++i) {
//     for (int j = i + 1; j < N; ++j) {
//         if (steps[i] > 2 * steps[j]) { ans++; break; }
//     }
// }
