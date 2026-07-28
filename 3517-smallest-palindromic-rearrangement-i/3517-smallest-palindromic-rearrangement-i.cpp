class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.size();
        int part = len/2;
        sort(s.begin() , s.begin() + part);
        for(int i=0; i<part ;i++){
            s[len-1-i] = s[i];
        }
        return s;
        
    }
};