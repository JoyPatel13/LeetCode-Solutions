class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int MinInd = 0 , n = nums.size();
        int MaxInd = 0 ;
        int mx =INT_MIN;
        int minn = INT_MAX;
        if(n == 1) return 1;
        for(int i =0 ;i<n ;i++){
            if(nums[i] < minn){
                minn = nums[i];
                MinInd = i ;
            }
            if(nums[i] > mx){
                mx = nums[i];
                MaxInd = i ;
            }
        }

        int bothFront = max(MinInd , MaxInd) + 1;
        int bothLast = n - min(MinInd , MaxInd) ;
        int split = (min(MinInd,MaxInd) + 1) + (n- max(MaxInd , MinInd));

        return min({bothFront , bothLast , split});
        
    }
};