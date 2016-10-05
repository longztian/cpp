#include "sortStack.hpp"

void sortStack(Stack& s) {
  Stack tmp;

  while (!s.empty()) {
    // get top
    auto v = s.top();
    s.pop();

    // pop large nodes
    int n = 0;
    while (!tmp.empty() && tmp.top() > v) {
      s.push(tmp.top());
      tmp.pop();
      n += 1;
    }

    tmp.push(v);

    // push back large nodes
    while (n) {
      tmp.push(s.top());
      s.pop();
      n -= 1;
    }
  }

  while (!tmp.empty()) {
    s.push(tmp.top());
    tmp.pop();
  }
}
