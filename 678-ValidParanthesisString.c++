//Brute Force

// TC = O(3^n)
// SC = O(n)

// bool checkAllCases(string s , int index , int cnt){
//     if(cnt<0) return false;
//     if(index == s.size()){
//         return cnt==0;
//     }
//     if(s[index]=='(') cnt++ ;
//     if(s[index]==')') cnt--;
//     return (checkAllCases(s,index+1 , cnt+1) || checkAllCases(s,index+1 , cnt-1) || checkAllCases(s,index+1,cnt));
// }

// class Solution {
// public:
//     bool checkValidString(string s) {
//         return checkAllCases(s , 0 , 0);
//     }
// };



/*
Optimal Solution
TC : O(n)
SC : O(1)
*/

class Solution {
    public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                min++;
                max++;
            } else if (s[i] == ')') {
                min--;
                max--;
            } else {
                
            min--;
            max++;
        }
        if (min < 0)
        min = 0;
        if (max < 0)
                return false;
            }
            return min == 0;
        }
    };
    
    