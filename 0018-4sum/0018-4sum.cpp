class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> unique_quads;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> seen;
                for (int k = j + 1; k < n; k++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long fourth = (long long)target - sum;
                    
                    if (seen.count(fourth)) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        unique_quads.insert(temp);
                    }
                    seen.insert(nums[k]);
                }
            }
        }
        
        return vector<vector<int>>(unique_quads.begin(), unique_quads.end());
    }
};