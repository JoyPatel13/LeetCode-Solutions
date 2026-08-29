class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ;
       
        vector<vector<int>>seen(n ,vector<int>(n, 0));
        //{time ,{row,col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;        int delrow[] = {-1 ,0 ,1, 0};
        int delcol[] = {0 , 1 , 0 ,-1};
        pq.push({grid[0][0] ,{ 0,0}});
        seen[0][0] = 1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row== n-1 && col == n-1)return time;

            for(int i =0 ;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow< n&& ncol>=0 && ncol < n && !seen[nrow][ncol]){
                    seen[nrow][ncol] = 1;
                    int newDistance = max(time , grid[nrow][ncol]);
                    pq.push({newDistance , {nrow,ncol}});
                }
            }
        }
        return -1;
    }
};