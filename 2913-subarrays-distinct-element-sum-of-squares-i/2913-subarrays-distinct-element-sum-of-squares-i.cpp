class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            unordered_set<int> st ;
            int cnt = 0 ;
            
            for(int j = i ; j<n ; j++){
                if(st.find(nums[j]) == st.end()){
                    cnt++;
                    st.insert(nums[j]);
                }
                ans += cnt*cnt;
            }
        }
        return ans;
        
    }
};