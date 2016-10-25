// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <cmath>
#include <vector>

int gcd(int a, int b) {
    int r = a % b;
    return r == 0 ? b : gcd(b, r);
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    auto maxA = *max_element(A.cbegin(), A.cend());
    auto maxB = *max_element(B.cbegin(), B.cend());
    auto N = max(maxA, maxB);

    vector<bool> prime((long) N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2, n = (int) sqrt(N); i <= n; ++i) {
        for (int j = i * i; j <= N; j += i) {
            prime[j] = false;
        }
    }

    vector<int> plist;
    for (int i = 0; i <= N; ++i) {
        if (prime[i]) plist.push_back(i);
    }


    int npd = 0;
    int d, a, b; // , k
    bool diff;
    for (int i = 0, Z = A.size(); i < Z; ++i) {
        if (A[i] != B[i]) {
            diff = false;
            d = gcd(A[i], B[i]);
            a = A[i] / d;
            b = B[i] / d;

            if ((prime[a] && d % a != 0) || (prime[b] && d % b != 0)) continue;

            // cout << "a = " << a << " b = " << b << " d = " << d << endl;
            for (int j = 0; plist[j] < a; ++j) {
                if (a % plist[j] == 0 && d % plist[j] != 0) {
                    diff = true;
                    break;
                }
            }
            /*
            for (int j = 2, n = (int) sqrt(a); j <= n; ++j) {
                if (a % j == 0) {
                    if (prime[j] && d % j != 0) {
                        diff = true;
                        break;
                    }

                    k = a / j;
                    if (prime[k] && d % k != 0) {
                        diff = true;
                        break;
                    }
                }
            }
             */
            if (diff) continue;

            for (int j = 0; plist[j] < b; ++j) {
                if (b % plist[j] == 0 && d % plist[j] != 0) {
                    diff = true;
                    break;
                }
            }
            /*
            for (int j = 2, n = (int) sqrt(b); j <= n; ++j) {
                if (b % j == 0) {
                    if (prime[j] && d % j != 0) {
                        diff = true;
                        break;
                    }

                    k = b / j;
                    if (prime[k] && d % k != 0) {
                        diff = true;
                        break;
                    }
                }
            }
             */
            if (diff) continue;
        }

        // cout << "a = " << a << " b = " << b << " found " << endl;
        npd += 1;
    }

    return npd;
}
