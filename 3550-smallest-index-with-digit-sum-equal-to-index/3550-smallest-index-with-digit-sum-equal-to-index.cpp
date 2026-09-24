class Solution {
public:
    int digitSum(int n){
        int total = 0;
        while(n >0 ){
            total += n % 10;
            n = n/10;
        }
        return total;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i =0 ;i<n ;i++){
            if(i == digitSum(nums[i])){
                return i ;
            }
        }
        return -1;
    }
};