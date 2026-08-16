class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size() ;
        int m = station.size();
        vector<int> early(n) ;
        vector<int> latest(n);
        if(n<=1)return 0;
        int j =0 ;
        for(int i =0 ;i< n ; i++){
            while(j< m && skill[i] !=station[j]){
                j++;
            }
            early[i] = j ;
            j++;
        }

        //right to left 
        j = m-1;
        for(int i = n-1 ;i>=0 ;i--){
            while(j>=0 && station[j]!= skill[i]){
                j-- ;
            }
            latest[i]= j;
            j--;
        }

        int maxGap = 0 ;
        for(int i =1 ;i< n;i++){
            maxGap = max(maxGap , latest[i] - early[i-1]);
        }
        return maxGap;
    }
};