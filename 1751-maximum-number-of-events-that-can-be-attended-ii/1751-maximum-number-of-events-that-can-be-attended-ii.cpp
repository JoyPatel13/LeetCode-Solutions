class Solution {
public:
    int n ;
    vector<int>nextIdx;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& events, int i, int k){
        if(k == 0 || i>= n) return 0;
        int ans = 0;

        if(dp[i][k]!= -1) return dp[i][k];

        int notTake = solve(events, i+1, k);

        int value = events[i][2];
        int j     = nextIdx[i];
        int take  = value + solve(events, j, k-1);

        return dp[i][k] = max(take , notTake);
    }

    int findNext(vector<vector<int>>& events, int end){
        int low = 0 ;
        int high = n-1;
        int res = n ;
        while(low<= high){
            int mid = low + (high- low)/2;

            if(events[mid][0] > end){
                res = mid ;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());
        nextIdx.resize(n);

        for(int i =0 ;i< n;i++){
            int end = events[i][1];
            nextIdx[i] = findNext(events, end);
        }
        dp.assign(n+1, vector<int>(k+1, -1));
        return solve(events, 0, k);
    }
};