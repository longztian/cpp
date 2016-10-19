// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cmath>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 3) return 0;

    vector<int> peeks;
    for (int i = 1; i < N - 1; ++i) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peeks.push_back(i);
            i += 1;
        }
    }

    int np = peeks.size();
    if (np < 2) return np;

    int nf = (int) sqrt(peeks.back() - peeks.front()) + 1;
    if (nf > np) nf = np;
    int nf_min = 1;
    int lastFlag = 0;
    for (int i = 1; i < np && nf_min < nf; ++i) {
        if (peeks[i] - peeks[lastFlag] >= nf) {
            nf_min += 1;
            lastFlag = i;
        }
    }

    int nFlags = nf_min;
    for(; nf > nFlags; --nf) {
        nf_min = 1;
        lastFlag = 0;
        for (int i = 1; i < np && nf_min < nf; ++i) {
            if (peeks[i] - peeks[lastFlag] >= nf) {
                nf_min += 1;
                lastFlag = i;
            }
        }
        if (nFlags < nf_min) nFlags = nf_min;
    }

    return nFlags;
}
