class Solution {
public:
    using PTR = const string*;
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 0;
        if (myIsConnected(beginWord, endWord)) return 2;

        map<PTR, pair<int, int>> visited;
        for (auto& s : wordList) {
            if (s == beginWord || s == endWord) continue;
            visited[&s] = make_pair(-1,-1);
        }
        visited[&beginWord] = make_pair(0, -1);
        visited[&endWord] = make_pair(-1, 0);

        queue<PTR> ql, qr;
        ql.push(&beginWord);
        qr.push(&endWord);
        while (!ql.empty() && !qr.empty()) {
            for (auto& kv : visited) {
                if (kv.second.first == -1) {
                    if (myIsConnected(*ql.front(), *kv.first)) {
                        kv.second.first = visited[ql.front()].first + 1;
                        if (kv.second.second != -1) {
                            return kv.second.first + kv.second.second + 1;
                        }
                        ql.push(kv.first);
                    }
                }

                if (kv.second.second == -1) {
                    if (myIsConnected(*qr.front(), *kv.first)) {
                        kv.second.second = visited[qr.front()].second + 1;
                        if (kv.second.first != -1) {
                            return kv.second.first + kv.second.second + 1;
                        }
                        qr.push(kv.first);
                    }
                }
            }
            ql.pop();
            qr.pop();
        }

        return 0;
    }

private:
    bool myIsConnected(const string& s1, const string& s2) {
        for (int i = 0, n = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (n == 1) return false;
                n += 1;
            }
        }
        return true;
    }
};
