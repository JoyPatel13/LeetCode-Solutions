class Solution {
public:
    long long flowerGame(int n, int m) {
        //Alice need to get odd number to win , so we need odd flowers across the lanes
        long long oddInX = (n+1)/2;
        long long EvenInX = n/2;

        long long OddInY = (m+1)/2;
        long long EvenInY = (m)/2;
        return  (oddInX * EvenInY) +  (EvenInX*OddInY);
    }
};