class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) 
    {
        vector<int> sum_array;

        for( int i = l; i <= r; ++i)
        {
            int sum = subarray(i,nums.size(), nums);

            if (sum != INT_MAX)
            {
                sum_array.push_back(sum);
            }        
        }

        if (sum_array.empty())
        {
            return -1;
        }

        auto it = min_element( sum_array.begin(), sum_array.end());

        return *it;
    }

    int subarray(int n, int size, vector<int>& nums)
    {
        int sum = INT_MAX;

        for (int i = 0; i <= size - n; ++i)
        {
            int curr_sum = 0;

            for (int j = i; j < i + n; ++j)
            {
                curr_sum += nums[j];
            }

            if (curr_sum > 0)
            {
                sum = min( sum, curr_sum);
            }
        }
        
        return sum;
    }
};