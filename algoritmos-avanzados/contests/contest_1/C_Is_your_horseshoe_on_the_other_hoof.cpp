#include <bits/stdc++.h>
#include <set>

using namespace std;

int main(){
  int count = 0;
  set<int> s;
  int x;
  for (int i = 0; i < 4; i++){
    cin >> x;
    s.insert(x);
  }
  count = 4 - s.size();
  cout << count << endl;
  return 0;
}