#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int num : nums) {
            minheap.push(num);
            if (minheap.size() > k) {
                minheap.pop();
            }
        }
        return minheap.top();
    }
};

//! 快排
class Solution {
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            return nums[k];
        }
        int  i = l - 1, j = r + 1;
        int partition = nums[(l + r) >> 1]; 
        while (i < j) {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        if (k <= j) return quickSelect(nums, l, j, k);
        else return quickSelect(nums, j + 1, r, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};


//! 快排模板

// 快速排序函数（Hoare 分区方案实现）
void quickSort1(vector<int>& nums, int l, int r) {
    // 1. 递归终止条件：当子数组长度为1或空时，无需排序
    if (l >= r) return;

    // 2. 初始化分区参数：
    // - i 初始在左边界左侧（l-1）
    // - j 初始在右边界右侧（r+1）
    // - 基准值 x 选中间元素（避免极端情况如全排序数组导致最坏时间复杂度）
    int i = l - 1, j = r + 1;
    int x = nums[(l + r) >> 1]; // 位运算代替 (l + r) / 2，等价且更高效

    // 3. Hoare 分区循环：双指针从两端向中间移动
    while (i < j) {
        // 3.1 移动左指针 i：跳过所有小于 x 的元素，直到找到 >=x 的元素
        do i++; while (nums[i] < x);

        // 3.2 移动右指针 j：跳过所有大于 x 的元素，直到找到 <=x 的元素
        do j--; while (nums[j] > x);

        // 3.3 如果指针未交错，交换左右指针的元素（确保左边 <=x，右边 >=x）
        if (i < j) swap(nums[i], nums[j]);
    }

    // 4. 递归排序左右子数组：
    // - 分区点为 j（因为当 i >= j 时，j 是左半部分的最右端）
    // - 左子数组：[l, j]（所有元素 <=x）
    // - 右子数组：[j+1, r]（所有元素 >=x）
    quickSort1(nums, l, j);
    quickSort1(nums, j + 1, r);
}

//! 计数排序
class Solution {
    public:
    int findKthLargest(int nums[], int k) {
        int buckets[20001];
        for (int i = 0; i < nums.length(); i++) {
            buckets[nums[i] + 10000]++;
        }
        for (int i = 20000; i >= 0; i--) {
            k = k - buckets[i];
            if (k <= 0) {
                return i - 10000;
            }
        }
        return 0;
    }
}