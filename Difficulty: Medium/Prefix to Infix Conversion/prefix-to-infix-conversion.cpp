class Solution {
public:

    string preToInfix(string s) {

        stack<string> st;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (isalnum(s[i])) {

                st.push(string(1, s[i]));
            }

            else {

                string a = st.top();
                st.pop();

                string b = st.top();
                st.pop();

                st.push("(" + a + s[i] + b + ")");
            }
            }

        return st.top();
    }
};