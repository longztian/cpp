// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int M, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    vector<int> index(M + 1, -1);
    int i = 0, j = 0, n = 0;
    while (j < N) {
        if (index[A[j]] == -1) {
            index[A[j]] = j;
            ++j;
        } else {
            // clear indexes for i to A[j]'s old index
            int e = index[A[j]];
            n += (j - i) * (j - i + 1) / 2;
            n -= (j - e - 1) * (j - e) / 2;
            for (int k = i; k <= e; ++k) {
                index[A[k]] = -1;
            }
            // move i to A[j]'s old index + 1;
            i = e + 1;
        }
    }
    n += (N - i) * (N - i + 1) / 2;

    return n;
}
