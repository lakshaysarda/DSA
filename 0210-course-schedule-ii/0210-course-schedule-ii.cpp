class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // adj[i] = list of courses that depend on course i
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);

        // prerequisites[i] = {course, prereq} -> prereq must be taken before course
        for (auto &it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto &neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If topo doesn't contain all courses, there's a cycle
        if (topo.size() == numCourses) {
            return topo;
        }
        return {};
    }
};