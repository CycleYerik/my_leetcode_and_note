class Solution {
    public:
        int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            if ((n & 1) != 0) { // 每次只判断最低位是否为 1
                count++;
            }
            n >>= 1; // 目标数右移一位，相当于除以 2
        }
        return count;
    }
    };