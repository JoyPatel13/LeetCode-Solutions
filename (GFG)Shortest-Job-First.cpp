/*
TC = O(n) + O(nlogn)
SC = O(1)
*/

class Solution {
  public:
    int solve(vector<int>& bt) {
        sort(bt.begin() , bt.end());
        int sum = 0 ;
        int ans =0  ;
        for(int i = 0; i<bt.size() -1 ;i++){
              sum += bt[i];
              ans += sum;
        }
        return ans/bt.size();
    }
};