class Solution {
public:
    int minRotations(int n, string s) {
        auto dist = [](int a, int b){
            int d = abs(a - b);
            return min(d, 10-d);
        };
        vector<int> digits(n);
        for(int i = 0;i<n; i++){
            digits[i] = s[i] - '0';
        }

        //counting cost without rotations 
        int base_cost = dist(0, digits[0]);
        for(int i =0; i<n-1; i++){
            base_cost += dist(digits[i] , digits[i+1]);
            
        }

        int min_cost = base_cost;
        for(int k =0; k<n; k++){
            int curr = base_cost ;
            if(k == 0){
                curr -= dist(0, digits[0]);
                curr+= dist(0, digits[n-1]);
            }
            else{
                curr -= dist(digits[k-1], digits[k]);
                curr += dist(digits[k-1], digits[n-1]);
            }
            min_cost = min(min_cost, curr);
        }
        return min_cost;
    }
};