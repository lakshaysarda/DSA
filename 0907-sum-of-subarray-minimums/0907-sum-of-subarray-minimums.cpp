class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }

        return prev;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }

        return next;
    }

    int sumSubarrayMins(vector<int>& arr) {

        vector<int> left = prevSmaller(arr);
        vector<int> right = nextSmaller(arr);

        long long ans = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            ans = (ans + (leftCount * rightCount % MOD) * arr[i]) % MOD;
        }

        return ans;
    }
};