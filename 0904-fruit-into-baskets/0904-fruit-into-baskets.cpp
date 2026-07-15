class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int left = 0;
        int right = 0;
        int maxi = 0;

        unordered_map<int,int> mpp;

        while (right < fruits.size()) {

            // Add current fruit
            mpp[fruits[right]]++;

            // Shrink until only 2 fruit types remain
            while (mpp.size() > 2) {

                mpp[fruits[left]]--;

                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);

                left++;
            }

            // Update answer
            maxi = max(maxi, right - left + 1);

            right++;
        }

        return maxi;
    }
};