
// ========== 标准版：两次二分，O(log n) ==========
class SolutionStandard {
public:
    // 找左边界：第一个 >= target 的下标
    int findLeftBound(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // 找右边界：最后一个 <= target 的下标
    int findRightBound(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;  // 向上取整，配合 left = mid
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int leftBound = findLeftBound(nums, target);
        if (leftBound == (int)nums.size() || nums[leftBound] != target) {
            return {-1, -1};
        }

        int rightBound = findRightBound(nums, target);
        return {leftBound, rightBound};
    }
};
