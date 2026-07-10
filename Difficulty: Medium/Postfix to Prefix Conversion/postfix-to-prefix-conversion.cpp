class Solution {
public:

    string postToPre(string s) {

        stack<string> st;

        for (char ch : s) {

            if (isalnum(ch)) {

                st.push(string(1, ch));
            }

            else {

                string b = st.top();
                st.pop();

                string a = st.top();
                st.pop();

                st.push(string(1, ch) + a + b);
            }
        }

        return st.top();
    }
};