class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        for(int i = 0; i<nums.size(); i++){
            int incLen = 1;
            for(int j = i; j<nums.size() -1; j++){
                if(nums[j+1] > nums[j]) incLen++;
                else break;
            }

            int decLen = 1;
            for(int j = i; j<nums.size() -1; j++){
                if(nums[j+1] < nums[j]){
                    decLen++;
                }
                else break;
            }
            ans = max({ans, incLen, decLen});
        }
        return ans;
    }
};