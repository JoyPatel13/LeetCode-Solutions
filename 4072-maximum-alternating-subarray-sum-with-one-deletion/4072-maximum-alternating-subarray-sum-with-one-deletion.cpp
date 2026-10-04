class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = LLONG_MIN/4;

        //a0/a1 : subarray ends at an even/odd index and d=no deletion
        //b0/b1 = same, deletion is already used
        long long a0 =NEG, a1 =NEG, b0 =NEG, b1 =NEG, ans = NEG;

        for(int v : nums){
            long long x = v ;
            //even postiton and deletion is not used 
            long long na0 = max(x, a1 == NEG ? NEG : a1 + x);
            //odd postion and deletion is not  used ;
            long long na1 = a0 ==  NEG ? NEG : a0 - x ;

            //deletion
            long long nb0 = max(b1 == NEG ? NEG : b1 + x, a0);
            long long nb1 = max(b0 == NEG ? NEG : b0 - x, a1);

            a0 = na0; a1 = na1; b0 = nb0; b1 = nb1;
            ans = max({ans, a0, a1, b0, b1});
            
        }
        return ans;
    }
};