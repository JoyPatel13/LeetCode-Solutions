class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int n = nums.size();
        bool isOdd = false;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 0) isOdd = false;
            else isOdd = true;  
            for(int j = i+1; j<n; j++){
               if( nums[i]% 2 == 0){
                    if(nums[j]%2 != 0){
                        ans[i] ++;
                    }
               }
               else{
                if(nums[j]%2 ==0){
                    ans[i] ++;
                }
               }
            }
        }
        return ans;
    }
};