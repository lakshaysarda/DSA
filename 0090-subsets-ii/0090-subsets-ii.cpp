

class Solution {
public:

    void solve(int index, vector<int>& nums,
               vector<int>& ds,
               set<vector<int>>& ans) {

        // Store the current subset
        ans.insert(ds);

        for (int i = index; i < nums.size(); i++) {

            // Choose the current element
            ds.push_back(nums[i]);

            // Recur for the remaining elements
            solve(i + 1, nums, ds, ans);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() ,nums.end());

        set<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);
        vector<vector<int>> hello(ans.begin(),ans.end());

        return hello;
    }
};