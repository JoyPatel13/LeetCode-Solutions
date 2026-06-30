class Solution {
public:

    int numberOfSubstrings(string s) {
        int right = 0;
        int left =0 ;
        vector<int>freq(3,0);
        int len = s.size();
        int total =0 ;
        while(right < len){
            char curr = s[right];
            freq[curr-'a']++;
            while(Check(freq)){
                total += len-right;
                char leftChar = s[left];
                freq[leftChar-'a']--;
                left++;
            }
            right++;

        }
        return total;
    }

private:
    bool Check(vector<int>&freq){
        if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
            return true;
        }
        return false;
    }
};