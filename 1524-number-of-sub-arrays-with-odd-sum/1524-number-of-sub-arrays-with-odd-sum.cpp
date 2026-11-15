class Solution {
public:
    int M = 1e9 +7;
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int cnt = 0 ;
        int odd = 0;
        int even = 1;

        for(int i = 0; i<n ; i++){
            if(prefix[i] % 2 == 0 ){//odd + even == odd
                cnt = (cnt + odd)%M;
                even++;
            }
            else{   //even + odd = odd
                cnt =( cnt+even)%M;
                odd++;
            }
        }
        return cnt;
    }
};