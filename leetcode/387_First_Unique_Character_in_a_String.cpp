const int NLETTERS = 26;

class Solution {
public:
    int firstUniqChar(string s) {
        const int N = s.size();
        const int NOTFOUND = N;
        const int REPEATED = N + 1;

        int indexes[NLETTERS];
        std::fill_n(indexes, NLETTERS, NOTFOUND);

        int id = 0;
        for (int i = 0; i < N; ++i) {
            id = s[i] - 'a';

            if (indexes[id] == REPEATED) continue;

            if (indexes[id] == NOTFOUND) {
                indexes[id] = i;  // first time seen, save index
            } else {
                indexes[id] = REPEATED;  // mark as repeated
            }
        }

        const int minIndex = *std::min_element(indexes, indexes + NLETTERS);

        return minIndex < N ? minIndex : -1;
    }
};
