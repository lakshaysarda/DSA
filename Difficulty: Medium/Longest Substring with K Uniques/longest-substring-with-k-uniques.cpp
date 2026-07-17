class Solution {
public:
    int longestKSubstr(string s, int k) {

        int left = 0;
        int right = 0;
        int ans = -1;

        unordered_map<char, int> mpp;

        while (right < s.size()) {

            mpp[s[right]]++;

            while (mpp.size() > k) {

                mpp[s[left]]--;

                if (mpp[s[left]] == 0)
                    mpp.erase(s[left]);

                left++;
            }

            if (mpp.size() == k) {
                ans = max(ans, right - left + 1);
            }

            right++;
        }

        return ans;
    }
};