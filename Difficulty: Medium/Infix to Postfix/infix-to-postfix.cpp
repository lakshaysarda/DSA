class Solution {
public:
    int priority(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPostfix(string s) {

        stack<char> st;
        string ans = "";

        for (char ch : s) {

            if (isalnum(ch)) {
                ans += ch;
            }

            else if (ch == '(') {
                st.push(ch);
            }

            else if (ch == ')') {

                while (st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }

                st.pop();
            }

            else {

                if (ch == '^') {

                    while (!st.empty() && st.top() != '(' && priority(ch) < priority(st.top())) {

                        ans += st.top(); 
                        st.pop();
                    }

                }

                else {

        while (!st.empty() && st.top() != '(' && priority(ch) <= priority(st.top()))
        
         {
                        ans += st.top();
                        st.pop();
                    }

                }
                
                st.push(ch);
            } 
        }             

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};