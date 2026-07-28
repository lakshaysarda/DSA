class Solution {
public:
    long long solve(vector<int>& bt) {

        sort(bt.begin(), bt.end());

        long long wait = 0;
        long long totalWait = 0;

        for (int i = 0; i < bt.size(); i++) {
            totalWait += wait;
            wait += bt[i];
        }

        return totalWait / bt.size();
    }
};