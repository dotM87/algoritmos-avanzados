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
  int t; cin >> t;
  while(t--){
    int n, x;
    string res;
    cin >> n >> x;
    int arr[n];
    vector<int> unos;
    forn(i,n){
      cin >> arr[i];
      if (arr[i] == 1) unos.pb(i);
    }
    if (sz(unos) > x){
      res = "NO";
    } else {
      int first = unos[0];
      int last = unos[sz(unos) - 1];
      int distance = last - first + 1;
      if (distance > x){
        res = "NO";
      } else {
        res = "YES";
      }
    }
    cout << res << "\n";
  }
  return 0;
}
