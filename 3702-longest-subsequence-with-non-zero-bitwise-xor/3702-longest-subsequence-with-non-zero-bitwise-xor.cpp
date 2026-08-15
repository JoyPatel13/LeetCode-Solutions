class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long sum = 0;
        int xor_all= 0;
        int n = nums.size();
        for(int i =0 ;i< n;i++){
            xor_all ^= nums[i];
            sum+=nums[i];
        }
        if(xor_all == 0 && sum == 0) return 0 ;
        else if(xor_all == 0 && sum>0 ) return n-1;
        return n;
    }
};