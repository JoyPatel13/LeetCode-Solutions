int f(string &s, string &t, int n , int m, vector<vector<int>>&dp){
    if(m< 0  ) return 1 ;
    if(n< 0) return 0 ;

    if(dp[n][m]!= -1){
        return dp[n][m];
    }
    int take =0 ;
    int notTake = 0;
    if(s[n] == t[m]){
        take = f(s, t, n-1, m-1, dp);
    }

    notTake = f(s, t, n-1, m, dp);
    
    return dp[n][m] = take + notTake;

}
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size() ;
        int m = t.size();
        vector<vector<int>>dp(n , vector<int>(m+1 , -1));
        return f(s, t, n-1, m-1, dp);
    }
};