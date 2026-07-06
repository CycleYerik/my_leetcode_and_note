


float ntc_lookup(float table[][2], int n, float r_t)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(table[mid][0] == r_t)
        {
            return table[mid][1];
        }
        else if(table[mid][0] < r_t)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return table[left][1];
}