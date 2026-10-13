class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sqArr(n);

        for(int i =0; i<n; i++){
            long long a = (long long)nums[i] * nums[i];
            sqArr[i] = a ;
        }

        sort(sqArr.begin(), sqArr.end());

        long long ans = 0;
        int mid = (n+1)/2;
        for(int i = 0; i<n - mid; i++){
            ans -= sqArr[i];
            
        }

        for(int i = n - mid; i < n; i++) {
            ans += sqArr[i];
        }
        
        return ans;

    }
};