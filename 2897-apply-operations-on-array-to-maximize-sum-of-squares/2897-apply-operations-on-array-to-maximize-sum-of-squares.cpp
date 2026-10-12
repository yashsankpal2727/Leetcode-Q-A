
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int bits[30] = {};

        for (int x : nums) {
            for (int b = 0; b < 30; b++) {
                if (x & (1 << b)) bits[b]++;
            }
        }

        while (k--) {
            long long x = 0;

            for (int b = 29; b >= 0; b--) {
                if (bits[b] > 0) {
                    x |= (1LL << b);
                    bits[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};
