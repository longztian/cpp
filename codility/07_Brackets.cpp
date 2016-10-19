// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    int N = S.size();
    if (N == 0) return 1;
    if (N % 2 == 1) return 0;

    string stack;
    for (char c : S) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else {
            if (stack.empty()) return 0;
            if ((c == ')' && stack.back() != '(')
             || (c == ']' && stack.back() != '[')
             || (c == '}' && stack.back() != '{')) return 0;
            stack.pop_back();
        }
    }
    return stack.empty() ? 1 : 0;
}
