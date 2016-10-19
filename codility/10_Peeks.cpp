// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cmath>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 3) return 0;

    int np = 0;
    vector<int> nPeeks(2, 0);
    nPeeks.reserve(N);

    for (int i = 1; i < N - 1; ++i) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            np += 1;
            nPeeks.push_back(np);
            i += 1;
        }
        nPeeks.push_back(np);
    }
    nPeeks.push_back(np);

    if (np < 2) return np;

    int step;
    bool zeroPeek;
    if (np * np > N) {
        int step_min = N % np == 0 ? N / np : (N / np + 1);
        int step_max = (int) sqrt(N);
        for (int step = step_min; step <= step_max; ++step) {
            if (N % step != 0) continue;

            zeroPeek = false;
            for (int i = step; i <= N; i += step) {
                if (nPeeks[i] - nPeeks[i - step] == 0) {
                    zeroPeek = true;
                    break;
                }
            }
            if (zeroPeek == false) return N / step;
        }

        np = step_max;
    }

    // np now < sqrt(N)
    for (; np > 1; --np) {
        if (N % np != 0) continue;

        step = N / np;
        zeroPeek = false;
        for (int i = step; i <= N; i += step) {
            if (nPeeks[i] - nPeeks[i - step] == 0) {
                zeroPeek = true;
                break;
            }
        }
        if (zeroPeek == false) return np;
    }

    return np;
}
