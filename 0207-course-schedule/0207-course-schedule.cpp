class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Create adjacency list
        // adj[u] = list of v such that u -> v (u must be done before v)
        vector<int> adj[numCourses];
        for (auto &it : prerequisites) {
            int course = it[0];
            int pre = it[1];
            adj[pre].push_back(course);   // pre -> course
        }
        
        // Step 2: Calculate in-degree of each node
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }
        
        // Step 3: Push all nodes with in-degree 0 into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 4: BFS (Kahn's Algorithm)
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            // reduce in-degree of neighbors
            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Step 5: If topo sort includes all nodes, no cycle -> can finish
        if (topo.size() == numCourses) {
            return true;
        }
        return false;
    }
};