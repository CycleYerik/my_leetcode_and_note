#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 辅助函数：线性数组中非相邻元素最大和
int robLinear(const vector<int>& nums, int start, int end) {
    if (start > end) return 0;
    int prev2 = 0, prev1 = 0;
    for (int i = start; i <= end; ++i) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int robCircular(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // 两种情况：不选第一个 或 不选最后一个
    return max(
        robLinear(nums, 0, n - 2),  // 不选最后一个
        robLinear(nums, 1, n - 1)   // 不选第一个
    );
}

int main() {
    vector<int> nums = {2, 3, 2, 8, 5, 1};
    cout << "最大非相邻元素和（环形）为: " << robCircular(nums) << endl;
    return 0;
}
