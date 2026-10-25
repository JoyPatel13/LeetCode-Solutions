class Solution {
public:
    typedef long long ll;

    ll getSumByFormula(ll count, ll x){
        return (count * x) - (count*(count + 1)) /2 ;

    }

    int maxValue(int n, int index, int maxSum) {
        ll left = 1;
        ll right = maxSum;
        ll mid;
        int ans =0 ;
        while(left <= right){
            mid = left + (right - left)/2;

            ll left_count = min((ll)index, mid - 1);

            ll left_sum = getSumByFormula(left_count, mid);

            left_sum += max((ll)0, index - (mid - 1)); //extra ones if any


            ll right_count = min((ll)n - index -1 , mid - 1);

            ll right_sum = getSumByFormula(right_count, mid);

            right_sum += max((ll)0, n- index - 1 - (mid - 1)); //extra ones if any

            ll totalSum = left_sum + mid + right_sum;

            if(totalSum <= maxSum){
                ans =  max((ll)ans, mid);
                left = mid +1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};