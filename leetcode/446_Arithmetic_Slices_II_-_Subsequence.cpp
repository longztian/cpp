class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size();
        if (N < 3) return 0;

        unordered_map<int, Sequence> stepSeqs;
        long step;
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                step = (long) A[j] - A[i];
                cout << i << " " << j << " : " << step << endl;
                if (step > numeric_limits<int>::max() || step < numeric_limits<int>::min()) continue;
                stepSeqs[step].ij[i].push_back(j);
            }
        }

        int n = 0;
        for (auto it = stepSeqs.begin();  it != stepSeqs.end(); ++it) {
            cout << "step=" << it->first;
            n += it->second.count();
            cout << endl;
        }

        return n;
    }

private:
    class Sequence {
    public:
        unordered_map<int, vector<int>> ij;

        int count() {
            if (ij.size() < 2) return 0;

            int n = 0;
            for (auto it = ij.begin(); it != ij.end(); ++it) {
                vector<vector<int>> sequences;
                vector<int> seq(1, it->first);
                myGetSeq(sequences, seq, it->first);

                for (auto& l : sequences) {
                    cout << "SEQ: ";
                    for (int i : l) cout << " " << i;
                    cout << " = "<< l.size() - 2 << endl;
                    n += (l.size() - 2);
                }
                cout << endl;
            }

            return n;
        }
    private:
        void myGetSeq(vector<vector<int>>& sequences, vector<int>& seq, int i) {
            auto it = ij.find(i);
            if (it == ij.end()) {
                if (seq.size() > 2) sequences.push_back(seq);
                return;
            }

            cout << "begin=" << i << " : ";
            for (int j : it->second) cout << " " << j;
            cout << endl;

            for (int j : it->second) {
                seq.push_back(j);
                myGetSeq(sequences, seq, j);
                seq.pop_back();
            }
        }
    };
};
