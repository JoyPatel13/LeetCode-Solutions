class Solution {
public:
    bool f(string s, int i, int sum, vector<vector<int>>&dp){
        if(sum < 0) return false;
        if(i == s.size()){
            if(sum == 0) return dp[i][sum] =   true;
            return dp[i][sum] =  false;
        }

        if(dp[i][sum]!= -1) return dp[i][sum];

        if(s[i] == ')') { 
            return dp[i][sum] =  f(s, i +1, sum - 1, dp);
        }

        if(s[i] == '('){
            return dp[i][sum] =  f(s, i +1, sum + 1, dp);
        }

        if(s[i] == '*'){
            return dp[i][sum] =  f(s, i +1, sum+1, dp) || f(s, i+1, sum -1, dp) || f(s, i+1, sum, dp);
        }
        return  dp[i][sum] =  false;

    }
    bool checkValidString(string s) {
        int n = s.size(); 
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return f(s, 0, 0, dp);

    }
};