/*
TC = O(3n)
SC = O(2n)
*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size());
        vector<int> right(ratings.size());
        left[0] =1 ;
        right[ratings.size() -1 ]= 1;
        for (int i=1 ;i< ratings.size() ;i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            else{
                left[i] = 1 ;
            }

        }

        for(int i = ratings.size()-2 ;i>=0 ;i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+ 1] + 1;
            }
            else{
                right[i] = 1;
            }
        }

        int sum =0 ;
        for(int i =0 ;i <ratings.size();i++){
            sum+= max(right[i] , left[i]);
        }
        return sum;



    }
};


//Optimal Solution ( Slope Approach )
/*
    TC = O(n)
    SC = O(1)

*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1 ;
        int i = 1 ;
        int n = ratings.size();
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                sum+= peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down > peak){
                sum += down - peak;
            }
        }
        return sum;
    }
};