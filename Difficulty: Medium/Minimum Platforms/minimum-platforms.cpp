class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0;
        int j = 0;

        int platforms = 0;
        int maxPlatforms = 0;

        while (i < arr.size()) {

            if (arr[i] <= dep[j]) {
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            }
            else {
                platforms--;
                j++;
            }
        }

        return maxPlatforms;
    }
};