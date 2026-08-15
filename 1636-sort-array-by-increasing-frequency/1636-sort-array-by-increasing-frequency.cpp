class Solution {
public:

    struct comp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {

            // Same frequency -> LARGER value first
            if (a.second == b.second) {
                return a.first < b.first;
            }

            // Smaller frequency first
            return a.second > b.second;
        }
    };

    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int,int> freq;

        // Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // Min heap
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            comp
        > pq;

        // Push {value, frequency}
        for (auto it : freq) {
            pq.push({it.first, it.second});
        }

        vector<int> ans;

        while (!pq.empty()) {

            int value = pq.top().first;
            int frequency = pq.top().second;

            pq.pop();

            for (int i = 0; i < frequency; i++) {
                ans.push_back(value);
            }
        }

        return ans;
    }
};