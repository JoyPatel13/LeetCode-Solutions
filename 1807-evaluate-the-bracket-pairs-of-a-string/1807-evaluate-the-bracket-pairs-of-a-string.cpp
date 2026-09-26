class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mp;
        for(const auto& k : knowledge){
            mp[k[0]] = k[1];
        }
        string ans = "";
        for(int i = 0; i<s.size() ;i++){
            if(s[i] == '('){
                string temp ="";
                i++;
                while(s[i]!=')'){
                    temp += s[i];
                    i++;
                }
                if(mp.count(temp)){
                    ans+= mp[temp];
                }
                else{
                    ans+= "?";
                }
            }
            else{
                ans+= s[i] ;
            }
        }
        return ans;

    }
};