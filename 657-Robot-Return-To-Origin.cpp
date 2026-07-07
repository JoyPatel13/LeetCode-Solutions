/*
TC = O(n)
SC = O(n)
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        int left =0 , right =0 , up =0,down =0 ;
        for (char c: moves){
            if(c == 'U') up++;
            else if(c == 'D') down++;
            else if (c == 'R') right++ ;
            else left++;
        }
        return ((up==down && left==right));
    }
};