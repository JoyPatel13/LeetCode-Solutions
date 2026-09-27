class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st ;
        string current_str = "";
        for(char c : s){
            if(c == '('){
                st.push(current_str);
                current_str = "";
            }
            else if(c == ')'){
                reverse(current_str.begin(), current_str.end());
                current_str = st.top() + current_str;
                st.pop();
            }
            else{
                current_str+= c;
            }
        }
        return current_str;

    }
};