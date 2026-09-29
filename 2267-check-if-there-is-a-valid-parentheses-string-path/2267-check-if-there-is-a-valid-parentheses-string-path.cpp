class Solution {
public:
    int n, m;
    vector<vector<vector<int>>>dp;
    int f(int i, int j, int bal, vector<vector<char>>& grid){
        //base case 
        if(i>=n || j>=m) return 0;
        if(grid[i][j] == '('){
            bal++;
        }
        else{
            bal -- ;
        }
        if(bal < 0) return 0;

        if(i == n-1 && j==m-1){
            return bal == 0 ? 1 : 0;
        }
        if(dp[i][j][bal] != -1) return dp[i][j][bal];
        //check for right and down 
        int dr[] = {1,0};
        int dc[] = {0, 1};
        for(int k =0; k<2; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr<0 || nc < 0 || nr>=n || nc>=m) continue ;
            if(f(nr, nc, bal, grid)) return dp[i][j][bal] =  1;
        }
        return dp[i][j][bal] = 0;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size() ;
        dp.resize(n+1, vector<vector<int>>(m+1, vector<int>(m+n+1, -1)));
        return f(0, 0, 0, grid);
    }
};