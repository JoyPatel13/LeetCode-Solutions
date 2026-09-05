bool f(int ind, int target, vector<int>& grid, vector<vector<int>>&dp){
    if(target == 0) return true;
    if(ind == 0) return (grid[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind -1 , target, grid, dp);
    bool take = false;
    if(target >= grid[ind]){
        take = f(ind - 1, target - grid[ind], grid, dp);
    }
    return dp[ind][target] = take | notTake;

}

bool SubsetSumToK(int n, int k ,vector<int>&arr){
    vector<vector<int>>dp(n , vector<int>(k+1 , -1));
    return f(n-1, k, arr, dp);

}
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size() ;i++){
            sum += nums[i];
        }
        if(sum%2) return false;
        return SubsetSumToK(nums.size(), sum/2 , nums);
    }
};