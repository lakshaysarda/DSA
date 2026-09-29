class Solution {
public:
    vector<int> parent, size;

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int extra = 0;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            if (findUPar(u) == findUPar(v)) {
                extra++;
            }
            else {
                unionBySize(u, v);
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (findUPar(i) == i)
                components++;
        }

        if (extra >= components - 1)
            return components - 1;

        return -1;
    }
};