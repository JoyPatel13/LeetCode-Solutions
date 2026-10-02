class Solution {
public: 
    void f(int open, int close, int n, vector<string>&ans, string s){
        if(open == n && open == close) {
            ans.push_back(s);
            return ;
        }
        if(open< n ){
            f(open+1, close, n, ans, s+'(');
        }

        if(close < open){
            f(open, close+1, n, ans, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
         f(0, 0, n, ans, "");
         return ans;
    }
};