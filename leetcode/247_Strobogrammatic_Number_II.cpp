namespace {

vector<char> first     ({'1', '6', '8', '9'});
vector<char> firstMatch({'1', '9', '8', '6'});

vector<char> digit     ({'0', '1', '6', '8', '9'});
vector<char> digitMatch({'0', '1', '9', '8', '6'});

vector<char> single    ({'0', '1', '8'});

}

class Solution {
public:
  vector<string> findStrobogrammatic(int n) {
    if (n <= 0) return vector<string>();

    vector<string> results;
    string num(n, '0');

    myGenerateNumber(0, n % 2, num, results);

    return results;
  }

private:
  void myGenerateNumber(int d, bool oddDigit, string& num, vector<string>& results) {
    if (d == num.size() / 2) {
      if (oddDigit) {
        for (int i = 0; i < single.size(); ++i) {
          num[d] = single[i];
          myGenerateNumber(d, false, num, results);
        }
      } else {
        results.push_back(num);
      }
    } else if (d == 0) {
      for (int i = 0; i < first.size(); ++i) {
        num[d] = first[i];
        num[num.size() - d - 1] = firstMatch[i];
        myGenerateNumber(d + 1, oddDigit, num, results);
      }
    } else {
      for (int i = 0; i < digit.size(); ++i) {
        num[d] = digit[i];
        num[num.size() - d - 1] = digitMatch[i];
        myGenerateNumber(d + 1, oddDigit, num, results);
      }
    }
  }
};
