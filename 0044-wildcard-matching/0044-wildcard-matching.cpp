class Solution {
public:
    int f(int i, int j, string &pattern, string &text,vector<vector<int>> &dp){
        if(i == 0 && j==0) return true;
        if(i==0 && j> 0) return false;
        if(j==0 && i>0){
            for(int ii =1; ii<=i; ii++){
                if(pattern[ii - 1]!= '*') return false; 
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(pattern[i -1 ] == text[j -1] || pattern[i-1] == '?'){
            return dp[i][j] = f(i-1, j-1, pattern, text, dp);
        }

        if(pattern[i -1] == '*'){
            return dp[i][j] = f(i-1, j, pattern, text, dp) | f(i, j-1, pattern, text, dp);

        }
        return dp[i][j] =false;

    }
    bool isMatch(string text, string pattern) {
        int n = text.size();
        int m = pattern.size() ;

        vector<vector<bool >> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for(int j = 1 ; j<=n; j++){
            dp[0][j] = false;
        }

        for(int i = 1; i<=m; i++){
            bool flag = true;
            for(int ii =1; ii<=i; ii++){
                if(pattern[ii - 1]!= '*'){
                    flag = false;
                    break;
                } 
            }
            dp[i][0] = flag;
        }

        for(int i =1; i<=m; i++){
            for(int j =1; j<=n; j++){
                if(pattern[i -1 ] == text[j -1] || pattern[i-1] == '?'){
                     dp[i][j] = dp[i-1][j-1];
                }

                else if(pattern[i -1] == '*'){
                     dp[i][j] = dp[i-1][j] | dp[i][j-1];

                }
                else  dp[i][j] =false;
            }
        }

        return dp[m][n];
    }
};