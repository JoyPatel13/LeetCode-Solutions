class Solution {
private:
    void dfs(int row , int col , vector<vector<int>>&vis ,vector<vector<int>>& mat , int delrow[] , int delcol[] ){
        int n = mat.size() ;
        int m = mat[0].size();
        vis[row][col] = 1 ;

        //check for 4 sides 
        for(int i= 0; i<4;i++ ){
            int nrow = row + delrow[i] ;
            int ncol = col + delcol[i] ;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                dfs(nrow , ncol ,vis , mat ,delrow ,delcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size() ;
        int cnt = 0;
        int delrow[] = {-1 ,0 ,1, 0};
        int delcol[] = {0 , 1 , 0 ,-1};
        vector<vector<int>> vis(n , vector<int>(m,0));
        
        //check for first and last row ;
        for(int j =0 ;j< m;j++){
            if(!vis[0][j] && mat[0][j] == 1){
                dfs( 0 ,j ,vis ,mat , delrow ,delcol);
            }

            if(!vis[n-1][j] && mat[n-1][j] == 1){
                dfs( n-1 , j ,vis ,mat ,delrow ,delcol);

            }
        }

        for(int i =0 ;i< n ;i++){
            if(!vis[i][0] && mat[i][0] == 1 ){
                dfs(i ,0,vis,mat,delrow ,delcol);
            }

            if(!vis[i][m-1] && mat[i][m-1] == 1){
                dfs( i , m-1 , vis ,mat ,delrow ,delcol);
            }
        }

        for(int i= 0;i< n;i++){
            for(int j= 0 ;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 1){
                    cnt++ ;
                }
            }
        }
        return cnt;
    }
};