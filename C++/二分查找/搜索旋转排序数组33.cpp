#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() -1;
            int mid = 0;
    
            while(left <= right)
            {
                mid = left + (right - left)/2;
    
                if(nums[mid] == target)
                {
                    return mid;
                }
    
                //左边有序
                if(nums[mid] >= nums[left])
                {
                    if(nums[mid] > target && target >= nums[left])
                    {
                        right = mid-1;
                    }
                    else 
                    {
                        left = mid +1;
                    }
                }
                //右边有序
                else 
                {
                    if(nums[mid] < target && target <= nums[right])
                    {
                        left = mid + 1;
                    }
                    else 
                    {
                        right = mid -1;
                    }
                }
            }
            return -1;
        }
    };



// ACM 模式手撕（本地 F5 调试用；力扣提交只交上面的 Solution 即可）

int search_rotated(vector<int>& nums, int target);

int main(void)
{
    int size = 0;
    vector<int> nums;
    int target = 0;

    cin >> size;
    int temp = 0;
    while (size--) {
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> target;
    cout << search_rotated(nums, target) << endl;
    return 0;
}

int search_rotated(vector<int>& nums, int target)
{
    int left = 0, right = nums.size()-1;
    int mid = 0;

    while(left <= right)
    {
        mid = left + (right - left)/2;

        if(nums[mid] == target)
        {
            return mid;
        }

        // 左边是升序的
        if(nums[left] < nums[mid]) 
        {
            if(nums[mid] > target && target >= nums[left])
            {
                right = mid -1;
            }
            else 
            {
                left = mid +1;
            }
        }
        else //右边是升序的
        {
            if(nums[mid] < target && target <= nums[right])
            {
                left = mid +1;
            }
            else
            {
                right = mid -1;
            }
        }
        

    }
    return -1;
}