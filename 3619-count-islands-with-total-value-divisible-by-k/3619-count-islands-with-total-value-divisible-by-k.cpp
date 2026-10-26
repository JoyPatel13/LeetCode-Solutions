class Solution {
public:
    long long dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i , int j, int delrow[], int delcol[] ){
        int n = grid.size();
        int m = grid[0].size();

        long long sum = 0;
        if(i >= n || j >= m || i<0 || j<0 ) return 0;
        
        sum+= grid[i][j];
        visited[i][j] = 1;

        for(int k = 0; k<4; k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];

            if(nrow>=0 && nrow < n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol] > 0){
                sum += dfs(grid, visited, nrow, ncol, delrow, delcol);
            }
        }
        return sum;
        
        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        int delrow[] = {-1 ,0 ,1, 0};
        int delcol[] = {0 , 1 , 0 ,-1};

        vector<vector<int>>visited(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] != 0){
                    long long sum = dfs(grid, visited, i, j, delrow, delcol);
                    if(sum % k == 0) ans+= 1;

                }
            }
        }
        return (int)ans;
    }
};