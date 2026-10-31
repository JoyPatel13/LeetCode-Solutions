class Solution {
public:
    long long MOD = 1e9 + 7;
    //0->right
    //1 -> down
    int f(vector<vector<int>>&grid,int i, int j, int dir, vector<vector<vector<int>>>&dp){
        int n = grid.size(), m = grid[0].size(), ans = 0;
        if(i >= n || j>= m) return 0;
        if(i == n-1 && j == m-1) return 1;

        if(dp[i][j][dir] != -1) return dp[i][j][dir];

        if(grid[i][j] == 0){
            int right =  f(grid, i, j+1, 0, dp);
            int down  =  f(grid, i+1, j, 1, dp);

            ans = (down + right)% MOD;
        }

        if(grid[i][j] == 1){
            long long down = 0 ;
            long long right = 0;
            if(dir == 0){
                 down =  f(grid, i+1, j, 1,dp);

            }
            else{
                 right  =  f(grid, i, j+1, 0, dp);

            }
            ans = (down + right) % MOD;
        }

        return dp[i][j][dir] = ans;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return f(grid, 0, 0, 0 , dp);
    }
};