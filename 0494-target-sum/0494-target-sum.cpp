class Solution {
public:
    int f(vector<int>&nums, int target, int index, int curr_sum, vector<vector<int>>&dp, int sum){
        if(index < 0 && curr_sum == target) return 1;
        if(index< 0) return 0 ;

        if(dp[index][curr_sum+ sum]!= -1) return dp[index][curr_sum + sum];

        int positive = f(nums, target, index-1, curr_sum + nums[index], dp, sum);
        int negative = f(nums, target, index-1, curr_sum - nums[index], dp, sum);
        return dp[index][curr_sum + sum] = positive + negative;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
         int sum = accumulate(nums.begin(), nums.end(), 0);
         if(abs(target) > sum) return 0;
        vector<vector<int>>dp(n , vector<int>(2*sum+1, -1));
        return f(nums, target, n-1, 0, dp, sum);
    }
};