class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if(color!=iniColor){
            dfs(image , sr ,sc ,iniColor , color);
        }
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int r, int c, int iniColor, int color){
        if(image[r][c] == iniColor){
            image[r][c] = color;
            if(r>=1 ){
                dfs(image , r-1 ,c , iniColor , color );
            }
            if(c>=1){
                dfs(image, r, c-1 , iniColor ,color);
            }
            if(r+1 < image.size()){
                dfs(image , r+1 , c ,iniColor ,color);
            }
            if(c+1 < image[0].size()){
                dfs(image ,r ,c+1 , iniColor , color);
            }
        } 
    }
};