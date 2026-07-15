class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for (int num : nums) {
            prefixSum += num;

            if (mpp.find(prefixSum - goal) != mpp.end())
                ans += mpp[prefixSum - goal];

            mpp[prefixSum]++;
        }

        return ans;
    }
};