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
  string s;
  cin >> s;
  int sum = 0;
  forv(i, s){
    sum += isupper(i) ? 1 : 0;
  }
  if (sum > (sz(s)-sum)){
    transform(s.begin(), s.end(), s.begin(),
              ::toupper);
  } else {
    transform(s.begin(), s.end(), s.begin(),
              ::tolower);
  }
  cout << s;

  return 0;
}
