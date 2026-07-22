class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0, right = nums.size()-1;
    
            while(left <= right)
            {
                int mid = (right - left) /2 + left;
                if(nums[mid] < target)
                {
                    left = mid +1;
                }
                else if(nums[mid] > target)
                {
                    right = mid -1;
                }
                else
                {
                    return mid;
                }
            }
            return left;
    
        }
    };




int main(void)
{
    int n,target;
    cin >> n >> target;
    vector<int> input;

    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        input.push_back(x);
    }

    int left = 0 , right = n-1;
    int mid = 0;
    int result = 0;
    int is_find = 0;

    while(left <= right)
    {
        mid = left + (right - left)/2;
        if(input[mid] < target)
        {
            left = mid +1;
        }
        else if(input[mid] > target)
        {
            right = mid -1;
        }
        else
        {
            result = mid;
            is_find = 1;
            break;
        }
    }
    cout << (is_find ? result : left) <<endl;

    






    return 0;
}