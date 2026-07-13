class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> value;

        // length of the number
        for (int len = 2; len <= 9; len++) {

            // starting digit
            for (int start = 1; start <= 10 - len; start++) {

                int num = 0;

                // build the number
                for (int k = 0; k < len; k++) {
                    num = num * 10 + (start + k);
                }

                if (num >= low && num <= high)
                    value.push_back(num);
            }
        }

        return value;
    }
};