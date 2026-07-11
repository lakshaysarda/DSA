class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            while (!st.empty() && st.top() > 0 && a < 0) {

                if (st.top() < -a) {
                    st.pop();               // stack asteroid explodes
                }
                else if (st.top() == -a) {
                    st.pop();               // both explode
                    a = 0;
                    break;
                }
                else {
                    a = 0;                 // current asteroid explodes
                    break;
                }
            }

            if (a != 0)
                st.push(a);
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};