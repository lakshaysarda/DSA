class Solution {
public:

    int distance(int x, int y) {
        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        map<int, vector<vector<int>>> mpp;

        for (auto point : points) {
            int d = distance(point[0], point[1]);
            mpp[d].push_back(point);
        }

        vector<vector<int>> ans;

        for (auto it : mpp) {

            for (auto point : it.second) {

                ans.push_back(point);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};