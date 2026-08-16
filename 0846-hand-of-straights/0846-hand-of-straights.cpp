class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> mp;

        for (int x : hand)
            mp[x]++;

        while (!mp.empty()) {

            int card = mp.begin()->first;

            for (int j = 0; j < groupSize; j++) {

                int x = card + j;

                if (mp.find(x) == mp.end())
                    return false;

                mp[x]--;

                if (mp[x] == 0)
                    mp.erase(x);
            }
        }

        return true;
    }
};