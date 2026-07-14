class LFUCache {
public:
    class Node {
    public:
        int key, value, freq;
        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int cap;
    int minFreq;

    unordered_map<int, list<Node>::iterator> keyNode;
    unordered_map<int, list<Node>> freqList;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void update(list<Node>::iterator it) {
        int key = it->key;
        int value = it->value;
        int freq = it->freq;

        freqList[freq].erase(it);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        freqList[freq + 1].push_front(Node(key, value));
        freqList[freq + 1].front().freq = freq + 1;
        keyNode[key] = freqList[freq + 1].begin();
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        int ans = keyNode[key]->value;
        update(keyNode[key]);
        return ans;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->value = value;
            update(keyNode[key]);
            return;
        }

        if (keyNode.size() == cap) {
            Node temp = freqList[minFreq].back();
            keyNode.erase(temp.key);
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);
        }

        minFreq = 1;
        freqList[1].push_front(Node(key, value));
        keyNode[key] = freqList[1].begin();
    }
};