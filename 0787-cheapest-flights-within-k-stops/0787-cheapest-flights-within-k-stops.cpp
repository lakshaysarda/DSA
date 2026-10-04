class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // k stops = k + 1 flights
        for (int i = 0; i < k + 1; i++) {

            vector<int> temp = dist;

            for (auto flight : flights) {

                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (dist[u] != 1e9 &&
                    dist[u] + price < temp[v]) {

                    temp[v] = dist[u] + price;
                }
            }

            dist = temp;
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};