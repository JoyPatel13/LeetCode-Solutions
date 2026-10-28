class Solution {
public:

    int solve(vector<vector<int>>& grid, int i , int j, int xorr, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(dp[i][j][xorr] != -1) return dp[i][j][xorr];

        if(i == n-1 && j == m- 1 ) return dp[i][j][xorr] = xorr;


        int minXor = INT_MAX;

        int right = 0 ;
        if(j<m-1 ){
            int nextXor = xorr ^ grid[i][j+1];
            minXor = min(minXor, solve(grid, i, j+1, nextXor, dp));
        }

        int left = 0;
        if(i <n-1 ){
            int nextXor = xorr ^ grid[i+1][j];
            minXor = min(minXor, solve(grid, i+1, j, nextXor, dp));
        }
        return dp[i][j][xorr] =  minXor;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return solve(grid, 0, 0, grid[0][0], dp);
    }
};