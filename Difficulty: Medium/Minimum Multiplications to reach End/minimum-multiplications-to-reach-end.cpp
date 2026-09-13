class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        if (start == end ) return 0;

        queue<pair<int,int>> q;

        vector<int> dist(1000, 1e9);

        dist[start] = 0;

        q.push({0, start});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int steps = it.first;
            int node = it.second;

            for (auto x : arr) {

                int num = (node * x) % 1000;

                if (steps + 1 < dist[num]) {

                    dist[num] = steps + 1;

                    if (num == end)
                        return steps + 1;

                    q.push({steps + 1, num});
                }
            }
        }

        return -1;
    }
};