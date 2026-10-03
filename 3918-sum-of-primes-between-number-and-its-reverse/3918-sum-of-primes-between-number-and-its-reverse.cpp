class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int rev = 0 ;
        int nn  = n;
        while(n!=0){
            int remainder = n%10;
            rev = rev*10 + remainder;
            n/=10;
        }

        int mini = min(nn, rev);
        int maxi = max(nn, rev);
        int ans = 0;
        for(int i = mini; i<=maxi; i++){
            if(i< 2 ) continue;
            bool isPrime = true;
            for(int j =2; j*j<=i; j++){
                if(i%j == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                ans+= i;
            }
        }
        return ans;
    }
};