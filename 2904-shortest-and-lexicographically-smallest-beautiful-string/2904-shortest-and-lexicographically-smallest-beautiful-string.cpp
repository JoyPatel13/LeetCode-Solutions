class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i<n; i++){
            int maxcnt = 0 ;
            for(int j = i; j<n; j++){
                int cnt = count(s.begin() + i , s.begin() + j + 1, '1');
                if(cnt == k){
                    string candidate = s.substr(i, j - i + 1);
                   if(ans == "" || candidate.length() < ans.length() || 
                       (candidate.length() == ans.length() && candidate < ans)){
                        ans = candidate;
                    }
                }
            }
        }
        return ans;
    }
};