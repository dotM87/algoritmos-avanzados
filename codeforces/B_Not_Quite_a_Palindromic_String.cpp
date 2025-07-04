#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mp;
typedef priority_queue<int> pq;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define fore(i, a, b) for(int i = (a); i <(b); i++)
#define forv(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DEBUG cerr << "DEBUG: " << __LINE__ << endl;

const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;

signed main() {
  FAST_IO;
  int t;
  cin >> t;
  while (t--){
    int n, pairs;
    cin >> n >> pairs;
    string s;
    cin >> s;
    int zeros = count(all(s), '0');
    int ones  = n - zeros;
    int m     = n/2;
    int nopairs  = m - pairs;
    if (nopairs < 0 || zeros < nopairs || ones < nopairs) {
      cout << "NO\n";
      continue;
    }
    int a = zeros - nopairs;
    int b = ones  - nopairs;
    int max_k0 = a/2;
    int min_k0 = max(0, pairs - b/2);
    cout << (min_k0 <= max_k0 ? "YES\n" : "NO\n");
  }

  return 0;
}
