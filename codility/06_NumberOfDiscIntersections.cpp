// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <map>
#include <iterator>

using mmap_t = multimap<long, long>;
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 2) return 0;

    mmap_t edges;
    for (long i = 0; i < N; ++i) {
        edges.emplace(mmap_t::value_type({i - A[i], i + A[i]}));
    }

    int count, nPairs = 0;
    for (auto it = edges.begin(), itE = edges.end(); it != itE; ++it) {
        count = distance(it, edges.upper_bound(it->second)) - 1;
        nPairs += count;
        if (nPairs > 10000000) return -1;
    }

    return nPairs;
}


// vector<pair> is much faster


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <utility>
#include <vector>
#include <algorithm>

using pair_t = pair<long, long>;
using map_t = vector<pair_t>;

auto comp = [](const pair_t& e1, const pair_t& e2){ return e1.first < e2.first; };

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 2) return 0;

    map_t edges;
    edges.reserve(N);
    for (long i = 0; i < N; ++i) {
        edges.emplace_back(pair_t(i - A[i], i + A[i]));
    }

    sort(edges.begin(), edges.end(), comp);

    int count, nPairs = 0;
    for (auto p = edges.data(), pE = p + N; p < pE; ++p) {
        count = upper_bound(p, pE, pair_t(p->second, 0), comp) - p - 1;
        nPairs += count;
        if (nPairs > 10000000) return -1;
    }

    return nPairs;
}
