// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int minStep(vector<int>& A, vector<int>& fab, int i, int n, vector<int>& minCache, const int NOTREACHABLE) {
    if (minCache[i + 1] == -1) {
        vector<int> nsteps;
        for (auto it = fab.rbegin(), itE = fab.rend(); it != itE; ++it) {
            if (*it > n) continue;
            if (*it == n) return 1;

            if (A[i + *it] == 1) {
                nsteps.push_back(1 + minStep(A, fab, i + *it, n - *it, minCache, NOTREACHABLE));
            }
        }

        minCache[i + 1] = nsteps.empty() ? NOTREACHABLE: *min_element(nsteps.begin(), nsteps.end());
    }
    return minCache[i + 1];
}

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    vector<int> fab;
    for (int i2 = 0, i1 = 1, i = i1 + i2; i <= N + 1; i2 = i1, i1 = i, i = i1 + i2) {
        fab.push_back(i);
    }
    A.push_back(1);
    vector<int> minCache(N + 1, -1);
    const int NOTREACHABLE = N + 3;
    int n = minStep(A, fab, -1, N + 1, minCache, NOTREACHABLE);
    return n < NOTREACHABLE ? n : -1;
}
