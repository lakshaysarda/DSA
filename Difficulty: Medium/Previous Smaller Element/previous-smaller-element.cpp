class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;   // stores indices

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = arr[st.top()];   // return value

            st.push(i);
        }

        return prev;
    }
};