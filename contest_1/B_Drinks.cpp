#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  double count = 0;
  for (int i = 0; i < n; i++){
    double a;
    cin >> a;
    count += a;
  }
  cout << fixed << setprecision(12) << count / n << endl;
  return 0;
}