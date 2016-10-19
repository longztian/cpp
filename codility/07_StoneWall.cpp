// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++11 (g++ 4.8.2)
    int N = H.size();

    vector<int> stack;
    int n = 1;
    stack.push_back(H.front());

    for (int i = 1; i < N; ++i) {
        while (!stack.empty() && stack.back() > H[i]) {
            stack.pop_back();
        }

        if (!stack.empty() && stack.back() == H[i]) continue;

        stack.push_back(H[i]);
        n += 1;
    }

    return n;
}
