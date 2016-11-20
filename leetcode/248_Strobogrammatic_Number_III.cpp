namespace {

unordered_map<char, char> digits({
  {'0', '0'},
  {'1', '1'},
  {'6', '9'},
  {'8', '8'},
  {'9', '6'}
});

vector<char> first     ({'1', '6', '8', '9'});
vector<char> firstMatch({'1', '9', '8', '6'});

vector<char> center({'0', '1', '8'});

vector<char> digit     ({'0', '1', '6', '8', '9'});
vector<char> digitMatch({'0', '1', '9', '8', '6'});

}

class Solution {
public:
  int strobogrammaticInRange(string low, string high) {
    int nl = low.size(), nh = high.size();

    if (nh == 0) return 0;
    if (nh > 0 && high[0] == '-') return 0;
    if (nl > 0 && low[0] == '-') nl = 0;

    if (nl > nh) return 0;
    if (nl == nh) {
      if (low > high) return 0;
      if (low == high) return myIsStrobogrammatic(low) ? 1 : 0;
      return myNStrobogrammaticInRange(&low, &high);
    }

    // nl < nh now
    int count = 0;
    // nl
    if (nl > 0) {
      count += myNStrobogrammaticInRange(&low, nullptr);
    }

    // nl + 1 to nh
    for (int i = nl + 1; i < nh; ++i) {
      int m = i / 2;

      int n = i % 2 == 0 ? 1 : 3; // center
      // first, last
      if (m > 0) n *= 4;
      // second to center
      for (int j = 1; j < m; ++j) n *= 5;

      count += n;
    }

    // nh
    count += myNStrobogrammaticInRange(nullptr, &high);

    return count;
  }

private:
  bool myIsStrobogrammatic(const string& num) {
    unordered_map<char, char>::iterator it;
    for (auto i = num.data(), j = i + num.size() - 1; i <= j; ++i, --j) {
      it = digits.find(*i);
      if (it == digits.end() || *j != it->second) return false;
    }
    return true;
  }

  int myNStrobogrammaticInRange(const string* low, const string* high) {
    int n = low ? low->size() : high->size();

    int count = 0;
    string num(n, '0');
    myStrobogrammaticInRange(0, count, n % 2, num, low, high);

    return count;
  }

  void myStrobogrammaticInRange(int i, int& count, bool oddDigit, string& num, const string* low, const string* high) {
    if (i == num.size() / 2) {
      if (oddDigit) {
        for (int j = 0; j < center.size(); ++j) {
          num[i] = center[j];
          myStrobogrammaticInRange(i, count, false, num, low, high);
        }
      } else {
        if (low && num < *low) return;
        if (high && num > *high) return;
        ++count;
      }
    } else if (i == 0) {
      for (int j = 0; j < first.size(); ++j) {
        num[0] = first[j];
        num[num.size() - 1] = firstMatch[j];
        myStrobogrammaticInRange(i + 1, count, oddDigit, num, low, high);
      }
    } else {
      for (int j = 0; j < digit.size(); ++j) {
        num[i] = digit[j];
        num[num.size() - i - 1] = digitMatch[j];
        myStrobogrammaticInRange(i + 1, count, oddDigit, num, low, high);
      }
    }
  }
};
