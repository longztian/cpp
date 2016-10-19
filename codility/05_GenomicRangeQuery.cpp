// GenomicRangeQuery
// https://codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

#include <stdexcept>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    int N = S.size();
    int M = P.size();
    vector<int> ret(M, 5);
    vector<int> factors;

    for (char c : S) {
        switch (c) {
            case 'A': factors.push_back(1); break;
            case 'C': factors.push_back(2); break;
            case 'G': factors.push_back(3); break;
            case 'T': factors.push_back(4); break;
            default: throw runtime_error("input error");
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (factors[i] < ret[j]) {
                if (i >= P[j] && i <= Q[j]) {
                    ret[j] = factors[i];
                }
            }
        }
    }

    return ret;
}



// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <stdexcept>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    int N = S.size();
    vector<int> A, C, G, T;
    A.reserve(N);
    C.reserve(N);
    G.reserve(N);
    T.reserve(N);

    switch (S.front()) {
        case 'A':
            A.push_back(1);
            C.push_back(0);
            G.push_back(0);
            T.push_back(0);
            break;
        case 'C':
            A.push_back(0);
            C.push_back(1);
            G.push_back(0);
            T.push_back(0);
            break;
        case 'G':
            A.push_back(0);
            C.push_back(0);
            G.push_back(1);
            T.push_back(0);
            break;
        case 'T':
            A.push_back(0);
            C.push_back(0);
            G.push_back(0);
            T.push_back(1);
            break;
        default: throw string("input error");
    }

    for (int i = 1; i < N; ++i) {
        switch (S[i]) {
            case 'A':
                A.push_back(A.back() + 1);
                C.push_back(C.back());
                G.push_back(G.back());
                T.push_back(T.back());
                break;
            case 'C':
                A.push_back(A.back());
                C.push_back(C.back() + 1);
                G.push_back(G.back());
                T.push_back(T.back());
                break;
            case 'G':
                A.push_back(A.back());
                C.push_back(C.back());
                G.push_back(G.back() + 1);
                T.push_back(T.back());
                break;
            case 'T':
                A.push_back(A.back());
                C.push_back(C.back());
                G.push_back(G.back());
                T.push_back(T.back() + 1);
                break;
            default: throw runtime_error("input error");
        }
    }

    int M = P.size(), p, q;
    vector<int> ret;
    ret.reserve(M);
    for (int j = 0; j < M; ++j) {
        p = P[j];
        q = Q[j];
        if (p == 0) {
            if (A[q] > 0) {
                ret.push_back(1);
            } else if (C[q] > 0) {
                ret.push_back(2);
            } else if (G[q] > 0) {
                ret.push_back(3);
            } else if (T[q] > 0) {
                ret.push_back(4);
            } else {
                throw runtime_error("internal error");
            }
        } else {
            if (A[q] - A[p -1] > 0) {
                ret.push_back(1);
            } else if (C[q] - C[p - 1] > 0) {
                ret.push_back(2);
            } else if (G[q] - G[p - 1] > 0) {
                ret.push_back(3);
            } else if (T[q] - T[p - 1] > 0) {
                ret.push_back(4);
            } else {
                throw runtime_error("internal error");
            }
        }
    }

    return ret;
}
