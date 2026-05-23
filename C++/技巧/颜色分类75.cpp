#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

// 两次双指针
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int size = nums.size();
    
            int p0 = 0;

            for(int i = 0 ; i < size; i ++)
            {
                if(nums[i] == 0)
                {
                    swap(nums[i], nums[p0]);
                    p0++;
                }
            }

            int p1 = p0;
            for(int i = p0 ;  i< size ; i++)
            {
                if(nums[i] == 1)
                {
                    swap(nums[i],nums[p1]);
                    p1++;
                }
            }
    
            
        }
    };

// 同上「两遍双指针」，但第二遍显式把 2 换到右端（与上面「把 1 换到左端」等价；LeetCode 提交需改类名为 Solution）
class Solution_TwoPass_Push2 {
    public:
        void sortColors(vector<int>& nums) {
            int size = nums.size();

            int p0 = 0;

            for(int i = 0 ; i < size; i ++)
            {
                if(nums[i] == 0)
                {
                    swap(nums[i], nums[p0]);
                    p0++;
                }
            }

            int p2 = size - 1;
            for(int i = p0 ;  i <= p2 ; )
            {
                if(nums[i] == 2)
                {
                    swap(nums[i],nums[p2]);
                    p2--;
                }
                else // 否则容易使得2被换上来，就没有了
                {
                    i++;
                }
            }
        }
    };


// 一次三指针（荷兰国旗）：单趟、O(n)、O(1) 额外空间。提交时改类名为 Solution。
// 不变量：[0, p0) 全是 0；(p2, n-1] 全是 2；[p0, i) 全是 1；[i, p2] 待查看。
class Solution_OnePass_ThreePointers {
    public:
        void sortColors(vector<int>& nums) {
            int size = nums.size();
            int p0 = 0;
            int i = 0;
            int p2 = size - 1;

            while (i <= p2) {
                if (nums[i] == 0) {
                    swap(nums[i], nums[p0]);
                    p0++;
                    i++;
                } else if (nums[i] == 1) {
                    i++;
                } else {
                    swap(nums[i], nums[p2]);
                    p2--;
                }
            }
        }
    };