class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int ans = 0;

        if(n < m) return "";

        vector<int> hash(128, 0);

        for(char c : t){
            hash[c]++;
        }

        int l = 0, r = 0, cnt = m, minLen = INT_MAX, startIdx  = 0; 
        while(r < n){
            if(hash[s[r]] > 0) {
                cnt -- ;
            }
            hash[s[r]]--;

            while(cnt == 0){
                if(r - l +1 < minLen){
                    minLen = r - l + 1;
                    startIdx = l;
                }
                
                hash[s[l]]++;

                if(hash[s[l]] > 0){
                    cnt++;
                }
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
        

    }
};