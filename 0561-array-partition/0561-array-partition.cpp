class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=std::min(nums[i],nums[++i]);
        }
        return sum;
    }
};