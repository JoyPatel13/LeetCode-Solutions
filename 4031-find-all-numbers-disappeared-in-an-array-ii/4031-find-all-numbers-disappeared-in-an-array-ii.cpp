class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin() ,nums.end());
        vector<vector<int>> ans;
        int prev = lower - 1;
        for(int x : nums){
            if(x > upper ) break;
            if(x<lower) continue;
            if( prev + 1 <= x -1 ){
                ans.push_back({prev+1 , x-1});
            }
            prev = x ;
        }
        if(prev+1 <= upper){
            ans.push_back({prev+1 , upper});
        }
        return ans;
    }
};