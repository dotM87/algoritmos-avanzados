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

#define forn(i, n) for(int i = 0; i < (n); i++)
#define fore(i, a, b) for(int i = (a); i < (b); i++)
#define forv(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(int a, int b, int p, const string& s) {
    int n = sz(s);
    if (n == 1) return 1;
    int m = n - 1;
    vector<pair<int,char>> seg;
    seg.reserve(m);
    forn(i, m) {
        if (i == 0 || s[i] != s[i - 1]) {
            seg.pb({i, s[i]});
        }
    }
    int sum = 0;
    int indi = sz(seg);
    for (int i = sz(seg) - 1; i >= 0; --i) {
        int cost = (seg[i].se == 'A' ? a : b);
        if (sum + cost > p) break;
        sum += cost;
        indi = i;
    }
    if (indi == sz(seg)) return n;
    return seg[indi].fi + 1;
}

signed main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int a, b, p;
        string s;
        cin >> a >> b >> p >> s;
        cout << solve(a, b, p, s) << '\n';
    }
    return 0;
}

