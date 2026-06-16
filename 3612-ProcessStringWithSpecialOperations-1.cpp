/*
TC = O(2^n)
sc = O(2^n)

*/


class Solution {
public:
    string processStr(string s) {
        string ans;
        for (char c:s){
            if(c == '*' ){
                if( !ans.empty())
                ans.pop_back();
            }
            else if (c=='#'){
                ans = ans + ans;
            }
            else if(c == '%' ){
                if( !ans.empty())
                reverse(ans.begin(),ans.end());
                
            }
            else{
                ans += c;
            }
        }
        return ans;
    }
};