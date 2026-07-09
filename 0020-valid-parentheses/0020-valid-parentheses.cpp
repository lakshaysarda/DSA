class Solution {
public:
    bool isValid(string s) {

        if (s.size() == 1 ) return false;


        stack<char>st;
   for ( int i =0 ; i < s.size();i++){

        if (s[i]=='(' || s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }

        if (s[i] == ')'){
            if(st.empty() ||st.top() != '(') return false;
            st.pop();
        } 

        if (s[i] == '}'){
            if(st.empty() ||st.top() != '{') return false;
             st.pop();
        }

        if (s[i] == ']'){
            if(st.empty() ||st.top() != '[') return false;
             st.pop();
        }
    }  if (st.empty() == false) return false;
    return true;
    }
};