class Solution {
public:
    vector<int> prevSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;   // stores indices

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }

        return prev;
    }

    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        stack<int> st;   // stores indices

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }

        return next;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> left = prevSmaller(heights);
        vector<int> right = nextSmaller(heights);

        int maxi = 0;

        for (int i = 0; i < heights.size(); i++) {

            int width = right[i] - left[i] - 1;
            int area = width * heights[i];

            maxi = max(maxi, area);
        }

        return maxi;
    }
};