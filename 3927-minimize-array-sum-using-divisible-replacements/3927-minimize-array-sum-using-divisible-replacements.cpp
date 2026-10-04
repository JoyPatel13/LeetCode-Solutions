class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        vector<int>present(M+1, 0);
        vector<int> best(M+1 , 0);

        for(int x : nums) present[x] = 1 ;

        for(int d = 1; d<=M; d++){
            if(!present[d]) continue;
            for(int m = d; m<=M; m+=d ){
                if(!best[m]) best[m] = d ;
            }
        }

        long long sum =0 ;
        for(int x : nums) sum+= best[x];
        return sum;
    }
};