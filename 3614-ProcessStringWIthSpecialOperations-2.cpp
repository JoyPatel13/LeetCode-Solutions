/*
TC = O(2n)

*/


class Solution {
public:
    char processStr(string s, long long k) {
        long long len =0 ;
        for(char c : s){
            if(c == '*'){
                if(len>0){
                    len--;
                }   
            }
            else if (c == '#'){
                len*=2;
            }
            else if (c == '%'){
                
            }
            else{
                len++;
            }
        }
        if(k>= len ) {
            return '.';
        }
        for (int i =s.size()-1 ; i>=0 ;i--){
            if(s[i] == '%'){
                k = len - 1 - k;
            }
            else if (s[i] == '#'){
                if(len!=0){
      
                    len = len /2 ;
                    k = k %len;
                }
            }
            else if (s[i] == '*'){
                len++;
            }
            else{
                len--;
                if(k == len){
                    return s[i];
                }
            }

        }
        return '.';

    }
};