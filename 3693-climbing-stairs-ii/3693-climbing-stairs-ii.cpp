class Solution {
public:
    int f(int i , vector<int>&cost, vector<int>& dp){
        int n = cost.size();
        if(i > n) return INT_MAX;
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int one = i>=n ? INT_MAX : (cost[i] + 1) + f(i+1, cost, dp);
        int two = i+1 >=n ? INT_MAX :  (cost[i+1] + 4) + f(i+2 , cost, dp);
        int three = i+2 >= n ? INT_MAX :  (cost[i+2] + 9 ) + f(i+3 , cost, dp);
        return dp[i] = min({one, two, three});
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1, 0);
        dp[0] = 0;

        for(int j = 1; j<=n; j++){
            dp[j] = INT_MAX;
            if(j-1 >= 0) dp[j] =  min(dp[j], costs[j-1] + 1+ dp[j-1]);
            if(j-2 >= 0) dp[j] =  min(dp[j], (costs[j-1] + 4) + dp[j-2]);
            if(j-3 >= 0) dp[j] =  min(dp[j], (costs[j-1] + 9) + dp[j-3]);
        }

        return dp[n];
    }
};