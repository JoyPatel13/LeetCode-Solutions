class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return false;
        unordered_map<char , int > m1;
        for(char ch:s){
            m1[ch]++;
        }
        for(char ch : t){
            if(m1.find(ch) == m1.end() || m1[ch] == 0) return false;
            m1[ch] -- ;
        }
        return true;
    }
};