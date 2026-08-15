class Solution {
public:

    struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {

            int d1 = a[0]*a[0] + a[1]*a[1];
            int d2 = b[0]*b[0] + b[1]*b[1];

            return d1 < d2;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<vector<int>,
                       vector<vector<int>>,
                       comp> pq;

        for (auto point : points) {

            pq.push(point);

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};