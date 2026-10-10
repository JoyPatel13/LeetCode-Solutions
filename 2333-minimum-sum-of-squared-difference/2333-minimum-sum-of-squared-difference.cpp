class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(100001, 0);
        long long  k = (long long )k1 + k2 ;
        long long sum =0 ;
        int mx = 0;

        for(int i = 0; i<nums1.size(); i++){
            int sub = abs(nums1[i] - nums2[i]) ; 
            diff[sub] ++ ;
            sum += sub;
            mx = max(mx, sub );

        }
        
        if(sum<= k) return 0 ;

        for(int i = mx; i>0 && k>0 ; i--){
            long long move = min(k, (long long)diff[i]);
            diff[i] -= move;
            diff[i-1 ] += move ;
            k-= move ;
        }
       
        long long ans = 0;
        for(int i =0; i<=mx; i++){
            ans += (long long) i*i* diff[i];
        }
        return ans;
        
    }
};