class Solution {
public:
    bool checkString(string s) {
        int lastA = -1;
        int lastB = INT_MAX ;
        bool flag = true;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'a') {
                lastA = max(lastA , i);
                if(lastA > lastB) flag = false;
            }
            else{
                lastB = min(lastB, i);
                if(lastA > lastB){
                    flag = false;
                }

            }
                
        }
        if(lastA == -1) return true;
        return flag;
    }
};