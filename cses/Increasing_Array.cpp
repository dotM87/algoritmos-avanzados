#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define DEBUG cerr << "DEBUG: " << __LINE__ << endl;

int main() {
  FAST_IO;
  ll n, cnt = 0;
  cin >> n;
  
  vll a(n);
  
  cin >> a[0];
  
  rep(i, 1, n) {
    cin >> a[i];
    int ant = a[i-1];
    while (a[i] < ant) {
      a[i] = a[i] + 1;
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}