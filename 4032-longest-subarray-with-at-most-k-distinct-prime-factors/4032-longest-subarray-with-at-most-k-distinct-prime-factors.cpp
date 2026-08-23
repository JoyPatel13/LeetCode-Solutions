class Solution {
public:
    vector<int> getPrime(int x){
        vector<int> factors ; 
        for(int i = 2 ; i*i <=x ;i++){
            if(x % i == 0){
                factors.push_back(i);
                while(x%i ==0 )x/= i;
            }
        }
        if(x >1) factors.push_back(x);
        return factors;
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<vector<int>> primeFactors(n);
        for(int i= 0; i<n ; i++){
            primeFactors[i] = getPrime(nums[i]);
        }

        unordered_map<int , int> count ;
        int left = 0, distinct =0 , ans =0 ;
        for(int right =0 ;right < n;right++){
            for(int p :primeFactors[right]){
                if(count[p]++ == 0) distinct++;
            }
            while(distinct > k){
                for(int p : primeFactors[left]){
                    if(--count[p] == 0 ) distinct -- ;
                }
                left++;
            }
            ans = max(ans , right- left+1);
        }

        return ans;
    }
};