class Solution {
public:
    bool isPalindrome(string s) {
        string pal = "";
        for(char c : s){
            if(c >= 'a' && c<='z' || c>= '0' && c<='9') pal += c;
            else if (c>='A' && c<='Z') pal += tolower(c);
        }
        int l = 0;
        int r = pal.size() -1;
        while(l<=r) {
            if(pal[l]!= pal[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};