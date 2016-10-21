// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    int M = N * 2 + 1;
    vector<int> count(M, 0);
    for (int v : A) {
        count[v] += 1;
    }

    vector<int> nd(M, N);
    int i = 1, j, k;
    if (count[i] > 0) {
        nd[i] -= count[i]; // self
        for (j = 2; j < M; ++j) {
            if (count[j] > 0) nd[j] -= count[i]; // other
        }
    }

    for (i = 2; i < M; ++i) {
        if (count[i] > 0) {
            nd[i] -= count[i]; // self

            j = i * i;
            if (j < M && count[j] > 0) nd[j] -= count[i]; // other: i**2

            for (j = i * i + i; j < M; j += i) {
                if (count[j] > 0) {
                    nd[j] -= count[i];
                    k = j / i;
                    if (count[k] > 0) nd[j] -= count[k];
                }
            }
        }
    }

    vector<int> ret;
    ret.reserve(N);
    for (int v : A) {
        ret.push_back(nd[v]);
    }

    return ret;
}
