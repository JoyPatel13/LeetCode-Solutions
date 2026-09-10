class Solution {
public :
    int f(int index, int amount , vector<int>&coins, vector<vector<int>>&dp){
        if(amount == 0)return 1;
        if(index<0)return 0;
        int take= 0;
        int notTake =0 ;

        if(dp[index][amount] != -1) return dp[index][amount];

        if(coins[index]<= amount){
            take = f(index, amount - coins[index], coins, dp);
        }

        notTake = f(index-1, amount, coins, dp);
        
        return dp[index][amount] =  take + notTake; 
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<vector<int>> dp(n, vector<int>(amount+ 1, -1));
        return f(n-1, amount , coins, dp);
    }
};