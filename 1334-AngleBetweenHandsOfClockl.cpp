/*
TC = O(1)
SC = O(1);

*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hr = (float(minutes)/2) + (30*(float(hour)));
        float min = minutes*6;
        float ans = hr - min;
        if(ans < 0) ans = -1*ans;
        if(ans>180) return 360-ans;
        else return ans;
        return min;
    }
};