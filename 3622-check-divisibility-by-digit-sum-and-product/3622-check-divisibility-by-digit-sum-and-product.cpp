class Solution {
public:
    bool checkDivisibility(int n) {
        int N = n;
        int sum = 0 ;
        int prod = 1 ;
        while(N>0){
            int digit = N%10;
            sum+= digit;
            prod *= digit;
            N = N/10;
        }
        if(prod<= n){
            int ans = n % (sum+ prod);
            if(ans == 0) return true;
        }
        return false;
    }
};