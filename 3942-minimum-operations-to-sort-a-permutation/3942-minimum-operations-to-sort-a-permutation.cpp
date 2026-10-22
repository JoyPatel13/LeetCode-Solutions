class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc_cnt = 0, dsc_cnt = 0;

        for(int i = 1; i<n; i++){
            if(nums[i] == (nums[i-1] + 1) % n) asc_cnt ++ ;

            if((nums[i] + 1 ) % n == nums[i-1]) dsc_cnt++;
            
        }

        if(asc_cnt == n-1 && nums[0] == 0) return 0 ;

        if(asc_cnt == n-1){
            int leftRot = n - nums[0];
            int rightRot = 1 + (nums.back() + 1 ) + 1;
            return min(leftRot, rightRot);
        }

        if(dsc_cnt == n-1){
            //mandatory 1 reverse to convert into asc case
            int leftRot = n - nums.back() + 1 ;

            //(nums.front() + 1) % n = xLeft Rot
            //1 reverse
            int rightRot = (nums[0] + 1) % n + 1;

            return min(leftRot, rightRot);
        }

        return -1;

    }
};