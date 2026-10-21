class Solution {
public:
    bool possible(vector<int>& time, long long given_time, int totalTrips){
        long long trips =0 ;
        for(int &t : time){
            trips += given_time / t; 

        }
        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l = 1;
        long long r = (long long) *min_element(begin(time), end(time))*totalTrips;

        while(l < r){
            long long mid = (l + r)/ 2;

            if(possible(time, mid, totalTrips)){
                r = mid;
            }
            else{
                l = mid+ 1 ;
                
            }
        }
        return l ;
    }
};