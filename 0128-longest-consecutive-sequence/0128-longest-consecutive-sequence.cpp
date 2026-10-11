class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans, n =nums.size();
        sort(nums.begin(), nums.end());
        int last = INT_MIN , cnt = 0;
        int len = 1;

        if(n == 0) return 0;
        
        for(int i =0; i<n; i++){
            if(nums[i] - 1 == last){
                cnt++;
                last = nums[i];

            }
            else if(nums[i] != last){
                last = nums[i];
                cnt = 1; 
            }
            
            len = max(len, cnt);
            
        }
        return len ;

    }
};