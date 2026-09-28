class Solution {
public:
    int maxDepth(string s) {
        int ans = 0 ;
        int len =0 ;
        for(char c : s){
            if(c == '('){
                ans++;
            }
            else if (c == ')'){
                ans --;
            }
            len = max(len, ans);
        }
        return len;
    }
};