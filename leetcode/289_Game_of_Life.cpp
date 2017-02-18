class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0: 00 dead -> dead
        // 2: 10 dead -> live
        // 1: 01 live -> dead
        // 3: 11 live -> live
        const int NR = board.size();
        if (NR == 0) return;

        const int NC = board.front().size();
        if (NC == 0) return;

        int live = 0, rb = 0, re = 0, cb = 0, ce = 0;
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                rb = max(i - 1, 0);
                re = min(i + 2, NR);
                cb = max(j - 1, 0);
                ce = min(j + 2, NC);

                // count live
                live = 0;
                for (int r = rb; r < re; ++r) {
                    for (int c = cb; c < ce; ++c) {
                        live += (board[r][c] & 1);
                    }
                }

                // update [i,j]
                if (board[i][j]) {
                    // live
                    if (live >= 3 && live <= 4) board[i][j] |= 2; // live
                } else {
                    // dead
                    if (live == 3) board[i][j] |= 2; //live
                }
            }
        }

        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
