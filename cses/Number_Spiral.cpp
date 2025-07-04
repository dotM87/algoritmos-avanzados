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

ll machine(int x, int y) {
    if (y <= x) {
        if (x % 2 == 0)
            return 1LL * x * x - y + 1;
        else
            return 1LL * (x - 1) * (x - 1) + y;
    } else {
        if (y % 2 == 1)
            return 1LL * y * y - x + 1;
        else
            return 1LL * (y - 1) * (y - 1) + x;
    }
}

signed main() {
  FAST_IO;
  int t;
  cin >> t;
  while(t--){
    int x, y;
    cin >> x >> y;
    cout << machine(x, y) << endl;
  } 


  return 0;
}
