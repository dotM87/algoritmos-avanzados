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
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    bool found = false;
    for (int start = 1; start <= n && !found; ++start) {
        set<int> avail;
        for (int i = 1; i <= n; ++i) avail.insert(i);
        a[0] = start;
        avail.erase(start);
        int cur_min = start, cur_max = start;
        bool ok = true;
        rep (i, 1,n) {
            if (s[i - 1] == '<') {
                auto it = avail.lower_bound(cur_min);
                if (it == avail.begin()) { ok = false; break; }
                --it;
                int val = *it;
                a[i] = val;
                avail.erase(it);
                cur_min = val;
            } else {
                auto it = avail.upper_bound(cur_max);
                if (it == avail.end()) { ok = false; break; }
                int val = *it;
                a[i] = val;
                avail.erase(it);
                cur_max = val;
            }
        }
        if (ok) {
            found = true;
            rep(i, 0, n) cout << a[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
}


  return 0;
}
