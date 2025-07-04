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

vi a;
vi depth;

void build(int l, int r, int d) {
    if (l > r) return;
    int idx = l;
    for (int i = l+1; i <= r; ++i) {
        if (a[i] > a[idx]) idx = i;
    }
    depth[idx] = d;
    build(l, idx-1, d+1);
    build(idx+1, r, d+1);
}

int main() {
    FAST_IO;

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        a.assign(n, 0);
        rep(i, 0, n) {
            cin >> a[i];
        }
        depth.assign(n, 0);
        build(0, n-1, 0);
        rep(i, 0, n) {
            cout << depth[i] << (i+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
