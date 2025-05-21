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

const int MOD = 1e9+7;

int maxsum(const vector<int>& arr, int k) {
  ll S = 0;
  ll best = 0;
  ll cur = 0;
  for (int x : arr) {
    S = (S + x) % MOD;
    cur = max(0LL, cur + x);
    best = max(best, cur);
  }

  if (best <= 0) {
    return (int)((S + MOD) % MOD);
  }

  ll p2 = 1, base = 2;
  int exp = k;
  while (exp > 0) {
    if (exp & 1) p2 = p2 * base % MOD;
    base = base * base % MOD;
    exp >>= 1;
  }

  ll add = ( (p2 - 1 + MOD) % MOD ) * best % MOD;

  ll res = (S + add) % MOD;
  if (res < 0) res += MOD;
  return (int)res;

}


int main() {
  FAST_IO;
  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin >> n >> k;
    vector <int> arr;
    while (n--){
      int aux;
      cin >> aux;
      arr.pb(aux);
    }
    cout << maxsum(arr, k) << endl;
  }


  return 0;
}
