class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        int delrow[] = {-1 ,0 ,1, 0};
        int delcol[] = {0 , 1 , 0 ,-1};
        for(int i = 0; i < 4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow>= 0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m , 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1  )&& !visited[i][j] && grid[i][j] == 0){
                    dfs(i, j, grid, visited);
                }
            }
        }

        int cnt = 0;
        for(int  i =0 ;i <n ; i++){
            for(int j = 0; j< m; j++){
                if(!visited[i][j] && grid[i][j] == 0){
                    dfs(i, j , grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;

    }
};