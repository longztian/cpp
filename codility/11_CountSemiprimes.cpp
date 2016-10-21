// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cmath>

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> primes(N+1, 1);
    primes[0] = 0;
    primes[1] = 0;

    int n = (int) sqrt(N);
    for (int i = 2; i <= n; ++i) {
        if (primes[i] != 1) continue;
        for (int j = i * i; j <= N; j += i) {
            primes[j] = 0;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (primes[i] != 1) continue;
        primes[i * i] = 2;
        for (int j = i * i + i; j <= N; j += i) {
            if (primes[j / i] == 1) primes[j] = 2;
        }
    }

    vector<int> nSemiPrimes;
    nSemiPrimes.reserve(N + 1);
    nSemiPrimes.push_back(0);
    for (int i = 1; i <= N; ++i) {
        nSemiPrimes.push_back(primes[i] == 2 ? nSemiPrimes.back() + 1 : nSemiPrimes.back());
    }

    int M = P.size();
    vector<int> ret(M, 0);
    for (int i = 0; i < M; ++i) {
        ret[i] = nSemiPrimes[Q[i]] - nSemiPrimes[P[i]-1];
    }
    return ret;
}
