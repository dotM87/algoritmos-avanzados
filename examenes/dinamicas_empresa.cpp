#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
  FAST_IO;
  int n, m;
  cin >> n;
  list<int> tabu;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tabu.push_back(x);
  }

  auto getIterator = [&tabu](int pos) -> list<int>::iterator {
    auto it = tabu.begin();
    while (pos-- > 0)
      ++it;
    return it;
  };

  cin >> m;
  cin.ignore();

  while (m--) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> mov;
    int num;
    while (ss >> num) {
      mov.push_back(num);
    }
    if (mov.size() == 2) {
      int start = mov[0];
      int end = mov[1];
      int res;
      {
        auto it = getIterator(start);
        res = *it;
      }
      if (start <= end) {
        auto it = getIterator(start);
        int count = end - start;
        for (int i = 0; i <= count; i++) {
          res = min(res, *it);
          ++it;
        }
      } else {
        {
          auto it = getIterator(start);
          while (it != tabu.end()) {
            res = min(res, *it);
            ++it;
          }
        }
        {
          auto it = tabu.begin();
          for (int i = 0; i <= end; i++) {
            res = min(res, *it);
            ++it;
          }
        }
      }
      cout << res << "\n";
    } else if (mov.size() == 3) {
      if (mov[0] <= mov[1]) {
        for (int k = mov[0]; k <= mov[1]; k++) {
          auto it = getIterator(k);
          *it = *it + mov[2];
        }
      } else {
        for (int k = mov[0]; k < n; k++) {
          auto it = getIterator(k);
          *it = *it + mov[2];
        }
        for (int k = 0; k <= mov[1]; k++) {
          auto it = getIterator(k);
          *it = *it + mov[2];
        }
      }
    }
  }

  return 0;
}