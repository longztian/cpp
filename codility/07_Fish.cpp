// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <utility>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    vector<pair<int, int>> liveStack;
    int N = A.size();

    for (int i = 0; i < N; ++i) {
        if (liveStack.empty() || B[i] == 1) {
            liveStack.emplace_back(pair<int, int>({A[i], B[i]}));
        } else {
            bool alive = true;
            while (alive && !liveStack.empty() && liveStack.back().second == 1) {
                if (A[i] < liveStack.back().first) {
                    alive = false;
                } else {
                    liveStack.pop_back();
                }
            }
            if (alive) liveStack.emplace_back(pair<int, int>({A[i], B[i]}));
        }
    }

    return liveStack.size();
}
