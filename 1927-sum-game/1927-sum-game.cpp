class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int q1 = 0, q2 = 0;
        int s1 = 0, s2 = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q1++;
            else
                s1 += num[i] - '0';
        }

        // Second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                s2 += num[i] - '0';
        }

        int qDiff = q1 - q2;
        int sDiff = s1 - s2;

        // Unequal/odd number of ? difference
        if (qDiff % 2 != 0)
            return true;

        // Bob can make the sums equal
        if (sDiff + 9 * (qDiff / 2) == 0)
            return false;

        // Otherwise Alice wins
        return true;
    }
};