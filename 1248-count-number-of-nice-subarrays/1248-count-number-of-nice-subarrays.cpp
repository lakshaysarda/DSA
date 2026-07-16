class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        int odd = 0;
        int prefixEven = 0;
        int ans = 0;

        while (right < nums.size()) {

            if (nums[right] % 2 == 1) {
                odd++;
                prefixEven = 0;
            }

            while (odd == k) {

                prefixEven++;

                if (nums[left] % 2 == 1)
                    odd--;

                left++;
            }

            ans += prefixEven;
            right++;
        }

        return ans;
    }
};