/*
TC = O(n)
*/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, {}, [](auto& x) {
            return pair{x[0], -x[1]};
        });
        int count = 0;
        int r =0 ;
        for(auto& x : intervals){
            if(x[1] > r){
                count++ ;
                r = x[];
            }
        }
        return count;
    }
};