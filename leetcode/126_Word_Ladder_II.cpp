class Solution {
public:
    using WordP = const string*;
    using WordLevelMap = map<WordP, pair<int, int>>;
    using WordParentMap = map<WordP, vector<WordP>>;

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        if (beginWord == endWord) return vector<vector<string>>();
        if (myIsConnected(beginWord, endWord)) return vector<vector<string>>(1, {beginWord, endWord});
        if (wordList.empty()) return vector<vector<string>>();

        WordLevelMap wordLevel;
        for (auto& word : wordList) {
            if (word == beginWord || word == endWord) continue;
            wordLevel[&word] = {-1, -1};
        }
        wordLevel[&beginWord] = {0, -1};
        wordLevel[&endWord] = {-1, 0};

        WordParentMap leftParents, rightParents;
        set<WordP> joints;
        int n = -1, nLeft, nRight;

        queue<WordP> qLeft, qRight;
        qLeft.push(&beginWord);
        qRight.push(&endWord);

        while (!qLeft.empty() && !qRight.empty()) {
            nLeft = wordLevel[qLeft.front()].first;
            nRight = wordLevel[qRight.front()].second;

            if (n != -1 && nLeft + nRight >= n) break;

            for (auto& kv : wordLevel) {
                if (kv.second.first == -1 && myIsConnected(*qLeft.front(), *kv.first)) {
                    kv.second.first = nLeft + 1;
                    if (kv.second.second != -1) {
                        if (n == -1) n = kv.second.first + kv.second.second;
                        if (kv.second.first + kv.second.second == n) joints.insert(kv.first);
                    }
                    qLeft.push(kv.first);
                    leftParents[kv.first].push_back(qLeft.front());
                } else if (kv.second.first == nLeft + 1 && myIsConnected(*qLeft.front(), *kv.first)) {
                    leftParents[kv.first].push_back(qLeft.front());
                }

                if (kv.second.second == -1 && myIsConnected(*qRight.front(), *kv.first)) {
                    kv.second.second = nRight + 1;
                    if (kv.second.first != -1) {
                        if (n == -1) n = kv.second.first + kv.second.second;
                        if (kv.second.first + kv.second.second == n) joints.insert(kv.first);
                    }
                    qRight.push(kv.first);
                    rightParents[kv.first].push_back(qRight.front());
                } else if (kv.second.second == nRight + 1 && myIsConnected(*qRight.front(), *kv.first)) {
                    rightParents[kv.first].push_back(qRight.front());
                }
            }
            qLeft.pop();
            qRight.pop();
        }

        // build sequence
        vector<vector<WordP>> sequences;
        vector<WordP> seq;
        for (auto& joint : joints) {
            seq.push_back(joint);
            myBuildSequence(&beginWord, &endWord, leftParents, rightParents, seq, sequences);
            seq.clear();
        }

        // covert pointers to strings
        vector<vector<string>> strseq;
        for (auto &s : sequences) {
            strseq.push_back(vector<string>());
            for (auto p : s) {
                strseq.back().push_back(*p);
            }
        }

        return strseq;
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

    void myBuildSequence(WordP begin, WordP end,
                         const WordParentMap& leftParents, const WordParentMap& rightParents,
                         vector<WordP>& seq, vector<vector<WordP>>& sequences) {
        if (begin) {
            // left side
            if (seq.back() == begin) {
                // hit the beginning
                // reverse left, make a copy here
                vector<WordP> seqLeft(seq.rbegin(), seq.rend());
                // continue to build the right side
                myBuildSequence(nullptr, end, leftParents, rightParents, seqLeft, sequences);
                return;
            }

            for (auto p : leftParents.at(seq.back())) {
                seq.push_back(p);
                myBuildSequence(begin, end, leftParents, rightParents, seq, sequences);
                seq.pop_back();
            }
        } else {
            // right side
            if (seq.back() == end) {
                // hit the end
                // check duplicates
                bool isNew = true;
                for (auto& s : sequences) {
                    if (equal(seq.begin(), seq.end(), s.begin())) {
                        isNew = false;
                        break;
                    }
                }
                if (isNew) sequences.push_back(seq);
                return;
            }

            for (auto p : rightParents.at(seq.back())) {
                seq.push_back(p);
                myBuildSequence(begin, end, leftParents, rightParents, seq, sequences);
                seq.pop_back();
            }
        }
    }
};
