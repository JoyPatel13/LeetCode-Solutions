class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int winner = 0;
        for(int i =0;i<grid.size() ;i++){
            if(i == winner){
                continue;
            }
            if(grid[winner][i] == 0){
                winner = i;
            }
        }
        return winner;
    }
};