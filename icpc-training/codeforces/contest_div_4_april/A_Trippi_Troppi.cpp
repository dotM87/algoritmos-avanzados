#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  string finalOutput;
  
  rep(i, 0, n) {
    string s, res;
    cin >> ws;
    getline(cin, s);
    if (!s.empty()) {
      res.push_back(s[0]);
      rep(j, 1, s.size()-1) {
        if (s[j] == ' ')
          res.push_back(s[j+1]);
      }
    }
    finalOutput += res + "\n";
  }
  
  cout << finalOutput << "\n"; 
  return 0;
}
