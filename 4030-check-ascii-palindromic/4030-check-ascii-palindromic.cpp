class Solution {
public:

    bool isPalindromic(string s) {
        string ans ; 
        for(char ch : s){
            int index = ch ;
            
            for(int i=7 ;i>=0 ;i--){
                if((ch >> i)&1){
                    ans+= '1';
                }
                else{
                    ans+= '0';
                }
            }
        }
        int low = 0;
        int high = ans.size() - 1; 
        while(low<=high){
            
            if(ans[low] != ans[high]){
                return false;
            }
            low++ ;
            high--;
        }
        return true;
    }
};