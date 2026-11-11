class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common = min(need1, need2);
        long long totalCost = common * min((long long)costBoth, (long long)cost1 + cost2);

        if(need1 > need2){
            long long rem = need1 - need2;
            totalCost += rem * min((long long)costBoth, (long long)cost1);
        }
        else if(need2 > need1 ){
            long long rem = need2 - need1;
            totalCost += rem * min((long long)costBoth, (long long)cost2);
        }

        return totalCost;
        
    }
};