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

signed f(int k, const vi& a, int l, int r) {
    ll ans = 0;
    rep(i, l, r+1) {
        if (k == 1) {
            ans += (r - i + 1);
            break;
        }
        while (k % a[i] == 0) {
            k /= a[i];
        }
        ans += k;
    }
    return ans;
}

int main() {
    FAST_IO;
    int t;
    cin >> t;
    rep(tc, 0, t) {
        int n, q;
        cin >> n >> q;
        vi a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        rep(i, 0, q) {
            int k, l, r;
            cin >> k >> l >> r;
            ll ans = f(k, a, l-1, r-1);
            cout << ans << "\n";
        }
    }
    return 0;
}
