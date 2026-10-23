class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();

        for(int i = 0; i<spells.size(); i++){
            long long spell = spells[i];
            int l = 0, r = m-1;
            int idx = m;

            while(l <= r){
                int mid = l + (r - l)/2;

                if((long long) spell * potions[mid] >= success){
                    idx = mid;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            ans.push_back(m - idx);

        }
        return ans;
    }
};