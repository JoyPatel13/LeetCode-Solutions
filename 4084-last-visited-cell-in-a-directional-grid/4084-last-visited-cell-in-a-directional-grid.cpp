class Solution {
public:

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int r = 0, c =0;
        visited[r][c] = 1;

        while(true){
            int next_r = r;
            int next_c = c ;
            char dir = grid[r][c];

            if(dir == 'L') next_c--;
            else if (dir == 'R') next_c ++;
            else if (dir == 'U') next_r--;
            else if (dir == 'D') next_r ++;

            if(next_c < 0 || next_r >=n || next_c >= m || next_r < 0|| visited[next_r][next_c] == 1){
                return {r, c};
            }

            r= next_r; 
            c = next_c;
            visited[r][c] = 1;
        }
    }
};