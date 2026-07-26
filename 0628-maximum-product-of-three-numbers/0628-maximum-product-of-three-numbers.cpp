class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end()); 
        int max1 = nums[n-1]*nums[n-2]*nums[n-3];
        int max2 = nums[0]*nums[1];
        if(max2>0) max2*=nums[n-1];
        return max1>max2 ? max1 : max2;

    }
};