class Solution {
private:
    void dfs(int row ,int col ,vector<vector<int>>& vis , vector<vector<char>>& mat , int delrow[] ,int delcol[]){
        int n = mat.size() ;
        int m = mat[0].size();
        vis[row][col]= 1;
        for(int i =0 ;i<4 ;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow< n  && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == '1'){
                dfs(nrow ,ncol,vis,mat,delrow, delcol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        int delrow[] = {-1 ,0 ,1, 0};
        int delcol[] = {0 , 1 , 0 ,-1};
        vector<vector<int>>vis(n,vector<int>(m,0) );
        for(int i=0;i<n ;i++){
            for(int j= 0;j< m;j++){
                if(!vis[i][j] && mat[i][j] == '1'){
                    dfs(i,j, vis ,mat ,delrow ,delcol);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};