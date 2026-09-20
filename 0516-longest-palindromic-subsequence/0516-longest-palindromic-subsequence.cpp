class Solution {
public:
     int f(int index1, int index2, string &s1, string &s2, vector<vector<int>>&dp){
        if(index1<0 || index2 < 0) return 0;
        
        if(dp[index1][index2] != -1) return dp[index1][index2];

        if(s1[index1] == s2[index2]){
            return dp[index1][index2] = 1 + f(index1-1, index2-1, s1, s2, dp);
        }
        return dp[index1][index2] =  max(f(index1-1, index2, s1, s2, dp), f(index1, index2-1, s1, s2, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        string s2(s.rbegin(), s.rend());
        return f(n-1, n-1,s, s2, dp);
    }
};