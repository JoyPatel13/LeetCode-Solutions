class Solution {
public:
    unordered_set<string> st;

    bool solve(int idx, string&s, int n, vector<int>&dp){
        if(idx >= n) return true;

        if(st.find(s) != st.end()) return true;
        
        if(dp[idx]!=-1) return dp[idx];

        for(int i =1; i<=n; i++){
            string temp = s.substr(idx, i);
            if(st.find(temp)!=st.end() && solve(idx+i, s, n, dp)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        for(string &word : wordDict){
            st.insert(word);
        }

        return solve(0, s, n, dp);
    }
};