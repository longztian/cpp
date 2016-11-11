// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <limits>
#include <cmath>
#include <memory>
#include <set>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.empty()) return 0;

    int maxA = numeric_limits<int>::min();
    for (int v : A) {
        if (v < 0) v *= -1;
        if (maxA < v) maxA = v;
    }

    shared_ptr<set<int>> pAbsSum = make_shared<set<int>>(), pAbsSumNext;
    pAbsSum->insert(abs(A[0]));
    int sum;
    for (int i = 1, n = A.size(); i < n; ++i) {
        pAbsSumNext.reset(new set<int>());
        for (auto it = pAbsSum->begin(), ite = pAbsSum->end(); it != ite; ++it) {
            sum = abs(*it - A[i]);
            if (sum <= maxA) pAbsSumNext->insert(sum);
            sum = abs(*it + A[i]);
            if (sum <= maxA) pAbsSumNext->insert(sum);
        }
        pAbsSum = pAbsSumNext;
    }

    return *min_element(pAbsSum->begin(), pAbsSum->end());
}
