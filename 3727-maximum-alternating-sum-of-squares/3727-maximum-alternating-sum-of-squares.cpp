class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> arr;

        for(int x : nums) {
            arr.push_back(1LL * x * x);
        }

        sort(arr.begin(), arr.end());

        long long ans = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            if(i < (n + 1) / 2)
                ans += arr[n - 1 - i];
            else
                ans -= arr[n - 1 - i];
        }

        return ans;
    }
};